#pragma once

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
