#pragma once

namespace gameConstants
{
	const int normalFPSInMSec = 15;
	const float normalFPSInSec = 0.15;
	const int player1StartX = 60;
	const int player2StartX = 300;
	const int moveSize = 1;
	const int tankWidth = 18;
	const int tankHeight = 6;
	const int viewScale = 2;
	const int angleStepSize = 2;
	const int powerStepSize = 2;
	const int explosionGrowSpeed = 10;
	const int landZValue = 0;
}

namespace mathConstants
{
	const float pi = 3.14;
	const int piRad = 180;
	const float gravitationalAcceleration = 9.8;
}

enum NetworkType
{
	server,
	client
};

enum Message
{
	leftMove,
	rightMove,
	angleUp,
	angleDown,
	powerUp,
	powerDown,
	shotFired,
	missileSwitched,
	gameEnded
};
