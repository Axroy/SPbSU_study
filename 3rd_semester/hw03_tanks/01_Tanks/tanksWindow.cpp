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

	tank = new Tank(100, 30);
	scene->addItem(tank);
	tank->setTransformOriginPoint(50, 15);

	missile = new Missile(4);
	scene->addItem(missile);
	missile->setPos(50, 50);

	this->setFocus();
}

TanksWindow::~TanksWindow()
{
	delete ui;
}

void TanksWindow::paintEvent(QPaintEvent *event)
{
	tank->rotateGun(currentAngle);
	tank->setRotation(currentAngle);
}

void TanksWindow::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Enter:
		break;

	case Qt::Key_Up:
		ui->angleScrollBar->setValue(ui->angleScrollBar->value() + 1);
		break;

	case Qt::Key_Down:
		ui->angleScrollBar->setValue(ui->angleScrollBar->value() - 1);
		break;

	case Qt::Key_Left:
		break;

	case Qt::Key_Right:
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
