#include "tanksWindow.h"
#include "ui_tanksWindow.h"

TanksWindow::TanksWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TanksWindow)
{
	ui->setupUi(this);

	scene = new QGraphicsScene(this);
	ui->graphicsView->setScene(scene);

	timer = new QTimer(this);
	timer->start(30);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));

	connect(ui->angleScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updateAngle(int)));
	connect(ui->powerScrollBar, SIGNAL(valueChanged(int)), this, SLOT(updatePower(int)));
	connect(ui->moveLeftButton, SIGNAL(clicked(bool)), this, SLOT(moveLeft()));
	connect(ui->moveRightButton, SIGNAL(clicked(bool)), this, SLOT(moveRight()));

	tank = new Tank(15, 5, scene);
	scene->addItem(tank);
	moveTank(tank, 60);

	QPainterPath landPath;
	landPath.moveTo(land.getPoint(0));
	for (int i = 0; i < land.getPointsNumber(); i++)
		landPath.lineTo(land.getPoint(i));
	scene->addPath(landPath);

	scene->addLine(-50, 0 ,100, 0, QPen(Qt::green));
	scene->addLine(0, -50, 0, 100, QPen(Qt::blue));
	scene->addLine(0, 0, 0, 0);

	ui->graphicsView->scale(2, 2);

	this->setFocus();
}

TanksWindow::~TanksWindow()
{
	delete ui;
}

void TanksWindow::paintEvent(QPaintEvent *event)
{
	tank->rotateGun(currentAngle);
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

	case Qt::Key_Exit:
		QApplication::exit();
		break;

	default:
		break;
	}
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
	moveTank(tank, tank->pos().x() - moveSize);
}

void TanksWindow::moveRight()
{
	moveTank(tank, tank->pos().x() + moveSize);
}

void TanksWindow::moveTank(Tank *tank, int x)
{
	int y = land.getYCoordinate(x);
	tank->setPos(x, y);
}

void TanksWindow::enableControls(bool status)
{
	ui->angleScrollBar->setEnabled(status);
	ui->powerScrollBar->setEnabled(status);
	ui->moveLeftButton->setEnabled(status);
	ui->moveRightButton->setEnabled(status);
	ui->fireButton->setEnabled(status);
}
