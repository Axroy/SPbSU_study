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
#include "network.h"
#include "networkClient.h"
#include "networkServer.h"
#include "networkEnums.h"

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
	///	Updates game objects' positions on scene
	/// Missile collisions are checked here
	void updatePositions();
	/// Updates explosion size
	/// Win is dependent on collision of explosion and enemy tank so it's checked here
	void updateExplosion();
	/// Calculates and updates missile position after shot
	void updateMissilePosition();
	void updateAngle(int angle);
	void updatePower(int power);
	void moveLeft();
	void moveRight();
	void switchMissiles();
	void connectToServer();
	void connected();
	void disconnected();
	void messageReceived(Message message);

private:
	///Moves tank to position with x coordinate on the landscape
	void moveTank(Tank *player, int x);
	void enableControls(bool status);
	void switchPlayers();
	void gameReset();
	void turnEndReset();
	void endTurn();
	void endGame();
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
	Network *network;
	bool myTurn;
	QPointF currentMissilePosition;
	float currentTimeFromShot;
	bool isFiring;
};

