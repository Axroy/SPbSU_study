#include "tanksWindow.h"
#include "ui_tanksWindow.h"

TanksWindow::TanksWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TanksWindow)
{
	ui->setupUi(this);

	scene = new QGraphicsScene(this);
	ui->graphicsView->setScene(scene);

	Tank *testTank = new Tank(100, 30);
	scene->addItem(testTank);
	testTank->rotateGun(25);

}

TanksWindow::~TanksWindow()
{
	delete ui;
}
