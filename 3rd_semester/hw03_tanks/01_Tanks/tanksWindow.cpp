#include "tanksWindow.h"
#include "ui_tanksWindow.h"

TanksWindow::TanksWindow(QWidget *parent) :
    QMainWindow(parent),
	ui(new Ui::TanksWindow),
	scene(new QGraphicsScene(this)),
	drawingTimer(new QTimer(this)),
	shootingTimer(new QTimer(this)),
	explosionTimer(new QTimer(this)),
	land(new Landscape()),
	currentTimeFromShot(0),
	isFiring(false)
{
	ui->setupUi(this);
	ui->graphicsView->setScene(scene);
	ui->graphicsView->scale(viewScale, viewScale);
	ui->graphicsView->setSceneRect(ui->graphicsView->rect());
	ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignBottom);

	drawingTimer->start(normalFPSInMSec);
	connect(drawingTimer, SIGNAL(timeout()), this, SLOT(updatePositions()));
	connect(shootingTimer, SIGNAL(timeout()), this, SLOT(updateMissilePosition()));
	connect(explosionTimer, SIGNAL(timeout()), this, SLOT(updateExplosion()));
	connect(ui->angleScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updateAngle(int)));
	connect(ui->powerScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updatePower(int)));
	connect(ui->moveLeftButton, SIGNAL(clicked(bool)), this, SLOT(moveLeft()));
	connect(ui->moveRightButton, SIGNAL(clicked(bool)), this, SLOT(moveRight()));
	connect(ui->fireButton, SIGNAL(clicked(bool)), this, SLOT(shoot()));
	connect(ui->changeMissileButton, SIGNAL(clicked(bool)), this, SLOT(switchMissiles()));

	QPainterPath landPath;
	landPath.moveTo(land->getFirstPoint());
	for (int i = 0; i < land->getNumberOfPoints(); i++)
		landPath.lineTo(land->getPoint(i));
	scene->addPath(landPath);

	missileList.append(new LightMissile(tankHeight));
	missileList.append(new HeavyMissile(tankHeight));
	missile = missileList.first();
	ui->currentMissileNameLabel->setText(missile->getName());

	player1 = new Tank(tankWidth, tankHeight, Qt::red, scene, missile);
	player2 = new Tank(tankWidth, tankHeight, Qt::blue, scene, missile);

	player1->setZValue(landZValue + 1);
	scene->addItem(player1);
	moveTank(player1, player1StartX);

	player2->setZValue(landZValue + 1);
	scene->addItem(player2);
	moveTank(player2, player2StartX);

	currentPlayer = player1;
	enemyPlayer = player2;

	currentPlayer->setGunAngle(ui->angleScrollBar->value());
	currentPlayer->setShotPower(ui->powerScrollBar->value());

	enableControls(false);

	QMessageBox::StandardButton networkDecisionMessage;
	networkDecisionMessage = QMessageBox::question(this, "Server or client?", "Do you want to be a server?",
									   QMessageBox::Yes | QMessageBox::No);

	if (networkDecisionMessage == QMessageBox::Yes)
	{
		myTurn = false;
		network = new Network(server, ui->connectionStatusLabel, ui->IPComboBox, ui->portLineEdit);
		setWindowTitle("Tanks Server");
		ui->IPComboBox->setVisible(false);
		ui->portLineEdit->setVisible(false);
		ui->connectButton->setVisible(false);
	}
	else
	{
		myTurn = true;
		network = new Network(client, ui->connectionStatusLabel, ui->IPComboBox, ui->portLineEdit);
		setWindowTitle("Tanks Client");
		connect(ui->connectButton, SIGNAL(clicked(bool)), this, SLOT(connectToServer()));
	}

	connect(network, SIGNAL(connected()), this, SLOT(connected()));
	connect(network, SIGNAL(disconnected()), this, SLOT(disconnected()));
	connect(network, SIGNAL(messageReceived(Message)), this, SLOT(messageReceived(Message)));

	this->setFocus();
}

TanksWindow::~TanksWindow()
{
	delete ui;
	delete land;
	delete network;
}

void TanksWindow::keyPressEvent(QKeyEvent *event)
{
	if (!myTurn)
		return;

	switch (event->key())
	{
	case Qt::Key_Right:
		ui->angleScrollBar->setValue(ui->angleScrollBar->value() + angleStepSize);
		break;

	case Qt::Key_Left:
		ui->angleScrollBar->setValue(ui->angleScrollBar->value() - angleStepSize);
		break;

	case Qt::Key_A:
		ui->moveLeftButton->click();
		break;

	case Qt::Key_D:
		ui->moveRightButton->click();
		break;

	case Qt::Key_Down:
		ui->powerScrollBar->setValue(ui->powerScrollBar->value() - powerStepSize);
		break;

	case Qt::Key_Up:
		ui->powerScrollBar->setValue(ui->powerScrollBar->value() + powerStepSize);
		break;

	case Qt::Key_Return:
		ui->fireButton->click();
		break;

	case Qt::Key_Space:
		ui->changeMissileButton->click();
		break;

	default:
		break;
	}
}

void TanksWindow::shoot()
{
	if (myTurn)
		network->sendMessage(shotFired);

	currentMissilePosition = currentPlayer->getGunEndPos();
	missile = currentPlayer->getMissile();
	scene->addItem(missile);
	missile->setPos(currentMissilePosition);
	missile->setVisible(true);
	isFiring = true;
	shootingTimer->start(normalFPSInMSec);
	enableControls(false);
}

void TanksWindow::updatePositions()
{
	currentPlayer->rotateGun();
	enemyPlayer->rotateGun();
	scene->update();

	if (!isFiring)
		return;

	if (missile->collidesWithItem(enemyPlayer) || missile->pos().y() >= land->getYCoordinate(missile->pos().x()))
	{
		startExploding();
		turnEndReset();
		return;
	}

	if (missile->pos().x() <= land->getFirstPoint().x() || missile->pos().x() > land->getLastPoint().x())
	{
		endTurn();
		return;
	}
}

void TanksWindow::updateExplosion()
{
	explosion->updateExplosionSize();
	if (explosion->isMaxed())
	{
		if (explosion->collidesWithItem(enemyPlayer))
		{
			endGame();
		}
		else
		{
			endTurn();
		}

		explosionTimer->stop();
		delete explosion;
	}
}

void TanksWindow::updateMissilePosition()
{
	if (!isFiring)
		return;

	currentTimeFromShot += normalFPSInSec;

	int startX = currentPlayer->getGunEndPos().x();
	int startY = currentPlayer->getGunEndPos().y();

	int currentAngle = currentPlayer->getGunAngle();
	int currentPower = currentPlayer->getShotPower();

	int sign = 1;
	if (currentAngle < 0)
		sign = -1;

	int modifiedCurrentAngle = abs(abs(currentAngle) - piRad / 2);

	double cosAngle = cos(modifiedCurrentAngle * pi / piRad);
	double sinAngle = sin(modifiedCurrentAngle * pi / piRad);

	double velocityX = (currentPower / missile->getWeight()) * cosAngle * sign;
	double velocityY = (currentPower / missile->getWeight()) * sinAngle;

	currentMissilePosition = QPoint(startX + currentTimeFromShot * velocityX,
								   startY - velocityY * currentTimeFromShot
								   + gravitationalAcceleration * currentTimeFromShot * currentTimeFromShot / 2);
	missile->setPos(currentMissilePosition);
}

void TanksWindow::updateAngle(int angle)
{
	int currentAngle = currentPlayer->getGunAngle();
	if (angle > currentAngle)
		network->sendMessage(angleUp);
	if (angle < currentAngle)
		network->sendMessage(angleDown);

	currentPlayer->setGunAngle(angle);
}

void TanksWindow::updatePower(int power)
{
	int currentPower = currentPlayer->getShotPower();
	if (power > currentPower)
		network->sendMessage(powerUp);
	if (power < currentPower)
		network->sendMessage(powerDown);

	currentPlayer->setShotPower(power);
}

void TanksWindow::moveLeft()
{
	moveTank(currentPlayer, currentPlayer->getDownCenterPos().x() - moveSize);
	network->sendMessage(leftMove);
}

void TanksWindow::moveRight()
{
	moveTank(currentPlayer, currentPlayer->getDownCenterPos().x() + moveSize);
	network->sendMessage(rightMove);
}

void TanksWindow::switchMissiles()
{
	int nextMissileIndex = missileList.indexOf(missile) + 1;
	if (nextMissileIndex == missileList.size())
		nextMissileIndex = 0;

	missile = missileList.at(nextMissileIndex);
	currentPlayer->setMissile(missile);

	if (myTurn)
	{
		network->sendMessage(missileSwitched);
		ui->currentMissileNameLabel->setText(missile->getName());
	}
}

void TanksWindow::connectToServer()
{
	network->setupConnection();
}

void TanksWindow::connected()
{
	if (myTurn)
		enableControls(true);

	ui->IPComboBox->setVisible(false);
	ui->portLineEdit->setVisible(false);
	ui->connectButton->setVisible(false);
}

void TanksWindow::disconnected()
{
	enableControls(false);

	if (network->isServer())
		return;
	ui->IPComboBox->setVisible(true);
	ui->portLineEdit->setVisible(true);
	ui->connectButton->setVisible(true);
}

void TanksWindow::messageReceived(Message message)
{
	switch (message)
	{
		case angleUp:
			currentPlayer->setGunAngle(currentPlayer->getGunAngle() + angleStepSize);
		break;

		case angleDown:
			currentPlayer->setGunAngle(currentPlayer->getGunAngle() - angleStepSize);
		break;

		case powerUp:
			currentPlayer->setShotPower(currentPlayer->getShotPower() + powerStepSize);
		break;

		case powerDown:
			currentPlayer->setShotPower(currentPlayer->getShotPower() - powerStepSize);
		break;

		case leftMove:
			moveTank(currentPlayer, currentPlayer->getDownCenterPos().x() - moveSize);
		break;

		case rightMove:
			moveTank(currentPlayer, currentPlayer->getDownCenterPos().x() + moveSize);
		break;

		case missileSwitched:
			switchMissiles();
		break;

		case shotFired:
			shoot();
		break;

		case gameEnded:
			gameReset();
		break;

		default:
		break;
	}
}

void TanksWindow::moveTank(Tank *player, int x)
{
	if (x < land->getFirstPoint().x() || x > land->getLastPoint().x())
		return;

	int y = land->getYCoordinate(x);
	player->setDownCenterPos(QPoint(x, y));
}

void TanksWindow::enableControls(bool status)
{
	ui->angleScrollBar->setEnabled(status);
	ui->powerScrollBar->setEnabled(status);
	ui->moveLeftButton->setEnabled(status);
	ui->moveRightButton->setEnabled(status);
	ui->fireButton->setEnabled(status);
	ui->changeMissileButton->setEnabled(status);
}

void TanksWindow::switchPlayers()
{
	Tank *temp = enemyPlayer;
	enemyPlayer = currentPlayer;
	currentPlayer = temp;
}

void TanksWindow::gameReset()
{
	network->clearBuffer();

	turnEndReset();
	moveTank(player1, player1StartX);
	moveTank(player2, player2StartX);
	currentPlayer = player1;
	enemyPlayer = player2;

	missile = missileList.first();
	player1->setMissile(missile);
	player2->setMissile(missile);
	ui->currentMissileNameLabel->setText(missile->getName());

	ui->angleScrollBar->setValue(0);
	ui->powerScrollBar->setValue(0);
	player1->setGunAngle(0);
	player1->setShotPower(0);
	player2->setGunAngle(0);
	player2->setShotPower(0);

	if (network->isServer())
	{
		myTurn = false;
		enableControls(false);
	}
	else
	{
		myTurn = true;
		enableControls(true);
	}
}

void TanksWindow::turnEndReset()
{
	currentTimeFromShot = 0;
	isFiring = false;
	shootingTimer->stop();
	if (missile->scene() != 0)
		scene->removeItem(missile);

	missile = enemyPlayer->getMissile();
	if (!myTurn)
		ui->currentMissileNameLabel->setText(missile->getName());
}

void TanksWindow::endTurn()
{
	turnEndReset();
	switchPlayers();

	enableControls(!myTurn);
	myTurn = !myTurn;
}

void TanksWindow::endGame()
{
	QString gameEndMessage = "";
	if (myTurn)
		gameEndMessage = "You won!";
	else
		gameEndMessage = "You lost!";

	QMessageBox::StandardButton winMessage;
	winMessage = QMessageBox::question(this, "Repeat?", gameEndMessage + "\nRepeat the game?",
									   QMessageBox::Yes | QMessageBox::No);

	if (winMessage == QMessageBox::Yes)
	{
		if (myTurn)
			network->sendMessage(gameEnded);
		gameReset();
	}
	else
		QApplication::exit();
}

void TanksWindow::startExploding()
{
	missile->setVisible(false);
	explosion = missile->explode(scene);
	explosion->setZValue(player1->zValue() + 1);
	explosionTimer->start(explosionGrowSpeed);
}
