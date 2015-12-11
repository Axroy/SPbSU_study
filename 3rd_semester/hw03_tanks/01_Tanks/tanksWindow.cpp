#include "tanksWindow.h"
#include "ui_tanksWindow.h"

TanksWindow::TanksWindow(QWidget *parent) :
    QMainWindow(parent),
	ui(new Ui::TanksWindow),
	currentTimeFromShot(0),
	isFiring(false)
{
	ui->setupUi(this);

	scene = new QGraphicsScene(0, 0, 1000, 1000, this);
	ui->graphicsView->setScene(scene);

	drawingTimer = new QTimer(this);
	drawingTimer->start(15);
	connect(drawingTimer, SIGNAL(timeout()), this, SLOT(updatePositions()));

	shootingTimer = new QTimer(this);
	connect(shootingTimer, SIGNAL(timeout()), this, SLOT(updateMissilePosition()));

	connect(ui->angleScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updateAngle(int)));
	connect(ui->powerScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updatePower(int)));
	connect(ui->moveLeftButton, SIGNAL(clicked(bool)), this, SLOT(moveLeft()));
	connect(ui->moveRightButton, SIGNAL(clicked(bool)), this, SLOT(moveRight()));
	connect(ui->fireButton, SIGNAL(clicked(bool)), this, SLOT(shoot()));

	currentPlayer = new Tank(tankWidth, tankHeight, Qt::red, scene);
	currentPlayer->setZValue(1);
	scene->addItem(currentPlayer);
	moveTank(currentPlayer, 60);

	enemyPlayer = new Tank(tankWidth, tankHeight, Qt::blue, scene);
	enemyPlayer->setZValue(1);
	scene->addItem(enemyPlayer);
	moveTank(enemyPlayer, 300);

	QPainterPath landPath;
	landPath.moveTo(land.getFirstPoint());
	for (int i = 0; i < land.getNumberOfPoints(); i++)
		landPath.lineTo(land.getPoint(i));
	scene->addPath(landPath);

	//Testing grid
	/*scene->addLine(-50, 0 ,100, 0, QPen(Qt::green));
	scene->addLine(0, -50, 0, 100, QPen(Qt::blue));
	scene->addLine(0, 0, 0, 0);*/

	ui->graphicsView->scale(2, 2);
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
	case Qt::Key_Enter:
		break;

	case Qt::Key_Right:
		ui->angleScrollBar->setValue(ui->angleScrollBar->value() + 2);
		break;

	case Qt::Key_Left:
		ui->angleScrollBar->setValue(ui->angleScrollBar->value() - 2);
		break;

	case Qt::Key_A:
		ui->moveLeftButton->click();
		break;

	case Qt::Key_D:
		ui->moveRightButton->click();
		break;

	case Qt::Key_Down:
		ui->powerScrollBar->setValue(ui->powerScrollBar->value() - 2);
		break;

	case Qt::Key_Up:
		ui->powerScrollBar->setValue(ui->powerScrollBar->value() + 2);
		break;

	case Qt::Key_Space:
		ui->fireButton->click();
		break;

	case Qt::Key_Exit:
		QApplication::exit();
		break;

	default:
		break;
	}
}

void TanksWindow::shoot()
{
	currentMissilePosition = currentPlayer->getGunEndPos();
	missile = new Missile(tankHeight / 3, currentMissilePosition);
	scene->addItem(missile);
	isFiring = true;
	shootingTimer->start(15);
	enableControls(false);
}

void TanksWindow::updateMissilePosition()
{
	if (!isFiring)
		return;

	currentTimeFromShot += 0.1;

	int startX = currentPlayer->getGunEndPos().x();
	int startY = currentPlayer->getGunEndPos().y();

	int sign = 1;
	if (currentAngle < 0)
		sign = -1;

	///TODO выделить куда-нибудь все константы
	double cosAngle = cos(currentAngle * 3.14 / 180) * sign;
	double sinAngle = sin(currentAngle * 3.14 / 180) * sign;

	double velocityX = currentPower * cosAngle;
	double velocityY = currentPower * sinAngle;

	currentMissilePosition = QPoint(startX + currentTimeFromShot * velocityX,
								   startY - velocityY * currentTimeFromShot
								   + 9.8 * currentTimeFromShot * currentTimeFromShot / 2);
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
	currentPlayer->rotateGun(currentAngle - 90);

	if (!isFiring)
		return;

	if (missile->collidesWithItem(enemyPlayer))
	{
		QMessageBox::StandardButton winMessage = QMessageBox::question(this, "Repeat?",
															"Repeat the game?", QMessageBox::Yes | QMessageBox::No);
		if (winMessage == QMessageBox::Yes)
			gameReset();
		else
			QApplication::exit();
	}
	else
		if (missile->pos().y() >= land.getYCoordinate(missile->pos().x()))
		{
			turnEndReset();
			currentAngle = -currentAngle;
			switchPlayers();
		}
	scene->update();
}

void TanksWindow::moveTank(Tank *player, int x)
{
	if (x < land.getFirstPoint().x() || x > land.getLastPoint().x())
		return;

	int y = land.getYCoordinate(x);
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

void TanksWindow::gameReset()
{
	moveTank(currentPlayer, 60);
	moveTank(enemyPlayer, 300);
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
	if (missile != nullptr)
		delete missile;
}
