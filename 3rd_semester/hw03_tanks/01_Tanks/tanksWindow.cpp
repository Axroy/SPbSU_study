#include "tanksWindow.h"
#include "ui_tanksWindow.h"

TanksWindow::TanksWindow(QWidget *parent) :
    QMainWindow(parent),
	ui(new Ui::TanksWindow),
	currentTimeFromShot(0),
	isFiring(false)
{
	ui->setupUi(this);

	scene = new QGraphicsScene(this);
	ui->graphicsView->setScene(scene);

	drawingTimer = new QTimer(this);
	drawingTimer->start(normalFPSInMSec);
	connect(drawingTimer, SIGNAL(timeout()), this, SLOT(updatePositions()));

	shootingTimer = new QTimer(this);
	connect(shootingTimer, SIGNAL(timeout()), this, SLOT(updateMissilePosition()));

	explosionTimer = new QTimer(this);
	connect(explosionTimer, SIGNAL(timeout()), this, SLOT(updateExplosion()));

	connect(ui->angleScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updateAngle(int)));
	connect(ui->powerScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updatePower(int)));
	connect(ui->moveLeftButton, SIGNAL(clicked(bool)), this, SLOT(moveLeft()));
	connect(ui->moveRightButton, SIGNAL(clicked(bool)), this, SLOT(moveRight()));
	connect(ui->fireButton, SIGNAL(clicked(bool)), this, SLOT(shoot()));

	land = new Landscape();
	QPainterPath landPath;
	landPath.moveTo(land->getFirstPoint());
	for (int i = 0; i < land->getNumberOfPoints(); i++)
		landPath.lineTo(land->getPoint(i));
	scene->addPath(landPath);

	player1 = new Tank(tankWidth, tankHeight, Qt::red, scene);
	player1->setZValue(landZValue + 1);
	scene->addItem(player1);
	moveTank(player1, player1StartX);

	player2 = new Tank(tankWidth, tankHeight, Qt::blue, scene);
	player2->setZValue(landZValue + 1);
	scene->addItem(player2);
	moveTank(player2, player2StartX);

	currentPlayer = player1;
	enemyPlayer = player2;

	missileList.append(new LightMissile(tankHeight));
	missileList.append(new HeavyMissile(tankHeight));
	missile = missileList.first();
	ui->currentMissileNameLabel->setText(missile->getName());

	currentAngle = ui->angleScrollBar->value();
	currentPower = ui->powerScrollBar->value();

	ui->graphicsView->scale(viewScale, viewScale);
	ui->graphicsView->setSceneRect(ui->graphicsView->rect());
	ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignBottom);

	this->setFocus();
}

TanksWindow::~TanksWindow()
{
	delete ui;
}

void TanksWindow::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Right:
		ui->angleScrollBar->setValue(ui->angleScrollBar->value() + scrollbarMoveSize);
		break;

	case Qt::Key_Left:
		ui->angleScrollBar->setValue(ui->angleScrollBar->value() - scrollbarMoveSize);
		break;

	case Qt::Key_A:
		ui->moveLeftButton->click();
		break;

	case Qt::Key_D:
		ui->moveRightButton->click();
		break;

	case Qt::Key_Down:
		ui->powerScrollBar->setValue(ui->powerScrollBar->value() - scrollbarMoveSize);
		break;

	case Qt::Key_Up:
		ui->powerScrollBar->setValue(ui->powerScrollBar->value() + scrollbarMoveSize);
		break;

	case Qt::Key_Return:
		ui->fireButton->click();
		break;

	case Qt::Key_Space:
		switchMissiles();
		break;

	case Qt::Key_Escape:
		QApplication::exit();
		break;

	default:
		break;
	}
}

void TanksWindow::shoot()
{
	currentMissilePosition = currentPlayer->getGunEndPos();
	scene->addItem(missile);
	missile->setPos(currentMissilePosition);
	missile->setVisible(true);
	isFiring = true;
	shootingTimer->start(normalFPSInMSec);
	enableControls(false);
}

void TanksWindow::updateMissilePosition()
{
	if (!isFiring)
		return;

	currentTimeFromShot += normalFPSInSec;

	int startX = currentPlayer->getGunEndPos().x();
	int startY = currentPlayer->getGunEndPos().y();

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
	currentAngle = angle;
}

void TanksWindow::updatePower(int power)
{
	currentPower = power;
}

void TanksWindow::moveLeft()
{
	moveTank(currentPlayer, currentPlayer->getDownCenterPos().x() - moveSize);
}

void TanksWindow::moveRight()
{
	moveTank(currentPlayer, currentPlayer->getDownCenterPos().x() + moveSize);
}

void TanksWindow::updatePositions()
{
	currentPlayer->rotateGun(currentAngle - piRad / 2);
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

			QMessageBox::StandardButton winMessage;
			winMessage = QMessageBox::question(this, "Repeat?", "You won!\nRepeat the game?",
											   QMessageBox::Yes | QMessageBox::No);

			if (winMessage == QMessageBox::Yes)
				gameReset();
			else
				QApplication::exit();
		}
		else
			endTurn();

		explosionTimer->stop();
		delete explosion;
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
}

void TanksWindow::switchPlayers()
{
	Tank *temp = enemyPlayer;
	enemyPlayer = currentPlayer;
	currentPlayer = temp;
}

void TanksWindow::switchMissiles()
{
	int nextMissileIndex = missileList.indexOf(missile) + 1;
	if (nextMissileIndex == missileList.size())
		nextMissileIndex = 0;

	missile = missileList.at(nextMissileIndex);
	ui->currentMissileNameLabel->setText(missile->getName());
}

void TanksWindow::gameReset()
{
	currentPlayer = player1;
	enemyPlayer = player2;
	moveTank(currentPlayer, player1StartX);
	moveTank(enemyPlayer, player2StartX);
	currentAngle = 0;
	currentPower = 0;
	turnEndReset();
}

void TanksWindow::turnEndReset()
{
	currentTimeFromShot = 0;
	isFiring = false;
	shootingTimer->stop();
	enableControls(true);
	if (missile->scene() != 0)
		scene->removeItem(missile);
}

void TanksWindow::endTurn()
{
	turnEndReset();
	ui->angleScrollBar->setValue(-ui->angleScrollBar->value());
	switchPlayers();
}

void TanksWindow::startExploding()
{
	missile->setVisible(false);
	explosion = missile->explode(scene);
	explosion->setZValue(player1->zValue() + 1);
	explosionTimer->start(explosionGrowSpeed);
}
