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
	drawingTimer->start(15);
	connect(drawingTimer, SIGNAL(timeout()), this, SLOT(updatePositions()));

	shootingTimer = new QTimer(this);
	connect(shootingTimer, SIGNAL(timeout()), this, SLOT(updateMissilePosition()));

	connect(ui->angleScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updateAngle(int)));
	connect(ui->powerScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updatePower(int)));
	connect(ui->moveLeftButton, SIGNAL(clicked(bool)), this, SLOT(moveLeft()));
	connect(ui->moveRightButton, SIGNAL(clicked(bool)), this, SLOT(moveRight()));
	connect(ui->fireButton, SIGNAL(clicked(bool)), this, SLOT(shoot()));

	currentPlayer = new Tank(45, 15, Qt::red, scene);
	scene->addItem(currentPlayer);
	moveTank(currentPlayer, 60);

	enemyPlayer = new Tank(15, 5, Qt::blue, scene);
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

	case Qt::Key_Up:
		ui->angleScrollBar->setValue(ui->angleScrollBar->value() + 2);
		break;

	case Qt::Key_Down:
		ui->angleScrollBar->setValue(ui->angleScrollBar->value() - 2);
		break;

	case Qt::Key_Left:
		ui->moveLeftButton->click();
		break;

	case Qt::Key_Right:
		ui->moveRightButton->click();
		break;

	case Qt::Key_A:
		ui->powerScrollBar->setValue(ui->powerScrollBar->value() - 2);
		break;

	case Qt::Key_D:
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
	missile = new Missile(2, currentMissilePosition);
	scene->addItem(missile);
	isFiring = true;
	shootingTimer->start(100);
	enableControls(false);
}

void TanksWindow::updateMissilePosition()
{
	if (!isFiring)
		return;

	currentTimeFromShot += 0.1;

	int startX = currentPlayer->getGunEndPos().x();
	int startY = currentPlayer->getGunEndPos().y();

	double cosAngle = cos(currentAngle * 3.14 / 180);
	double sinAngle = sin(currentAngle * 3.14 / 180);

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
	currentPlayer->rotateGun(-currentAngle);

	if (!isFiring)
		return;

	if (missile->collidesWithItem(enemyPlayer))
	{
		QMessageBox *winMessage = new QMessageBox;
		winMessage->setText("Enemy tank shot!");
		winMessage->show();
		if (!winMessage->isEnabled())
			delete winMessage;

		isFiring = false;
		shootingTimer->stop();
		currentTimeFromShot = 0;
		enableControls(true);
		delete missile;
	}
	if (missile->pos().y() >= land.getYCoordinate(missile->pos().x()))
	{
		isFiring = false;
		shootingTimer->stop();
		currentTimeFromShot = 0;
		enableControls(true);
		delete missile;
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
