#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtWidgets>
#include <QList>

#include "tank.h"
#include "lightMissile.h"
#include "heavyMissile.h"
#include "landscape.h"
#include "constants.h"

namespace Ui {
class TanksWindow;
}

using namespace gameConstants;
using namespace mathConstants;

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
	void switchMissiles();

private:
	void moveTank(Tank *player, int x);
	void enableControls(bool status);
	void switchPlayers();
	void gameReset();
	void turnEndReset();
	void endTurn();
	void startExploding();

	Ui::TanksWindow *ui;
	QGraphicsScene *scene;
	Tank *player1;
	Tank *player2;
	Tank *currentPlayer;
	Tank *enemyPlayer;
	QList<Missile*> missileList;
	Missile *missile;
	Explosion *explosion;
	QTimer *drawingTimer;
	QTimer *shootingTimer;
	QTimer *explosionTimer;
	Landscape *land;
	int currentAngle;
	int currentPower;
	QPointF currentMissilePosition;
	float currentTimeFromShot;
	bool isFiring;
};

