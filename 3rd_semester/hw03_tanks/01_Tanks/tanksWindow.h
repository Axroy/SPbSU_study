#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtWidgets>

#include "tank.h"
#include "missile.h"
#include "landscape.h"

namespace Ui {
class TanksWindow;
}

class TanksWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit TanksWindow(QWidget *parent = 0);
	~TanksWindow();

private slots:
	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void updateAngle(int angle);
	void updatePower(int power);
	void moveLeft();
	void moveRight();

private:
	void moveTank(Tank *tank, int x);

	Ui::TanksWindow *ui;
	QGraphicsScene *scene;
	Tank *tank;
	Missile *missile;
	QTimer *timer;
	Landscape land;
	int currentAngle;
	int currentPower;
	const int moveSize = 10;
};

