#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtWidgets>

#include "tank.h"
#include "missile.h"

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

private:
	Ui::TanksWindow *ui;
	QGraphicsScene *scene;
	Tank *tank;
	Missile *missile;
	QTimer *timer;
	int currentAngle;
	int currentPower;
};

