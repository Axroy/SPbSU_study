#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtWidgets>
#include <QList>

#include "tank.h"
#include "lightMissile.h"
#include "heavyMissile.h"
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
	void keyPressEvent(QKeyEvent *event);
	void shoot();
	void updateMissilePosition();
	void updateAngle(int angle);
	void updatePower(int power);
	void moveLeft();
	void moveRight();
	void updatePositions();
	void updateExplosion();

private:
	void moveTank(Tank *player, int x);
	void enableControls(bool status);
	void switchPlayers();
	void switchMissiles();
	void gameReset();
	void turnEndReset();
	void endTurn();
	void startExploding();

	Ui::TanksWindow *ui;
	QGraphicsScene *scene;
	Tank *currentPlayer;
	Tank *enemyPlayer;
	QList<Missile*> missileList;
	Missile *missile;
	Explosion *explosion;
	QTimer *drawingTimer;
	QTimer *shootingTimer;
	QTimer *explosionTimer;
	Landscape land;
	int currentAngle;
	int currentPower;
	QPointF currentMissilePosition;
	float currentTimeFromShot;
	const int moveSize = 1;
	const int tankWidth = 18;
	const int tankHeight = 6;
	bool isFiring;
};

