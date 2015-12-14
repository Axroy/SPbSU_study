#pragma once

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QGraphicsScene>

#include "gun.h"
#include "missile.h"

class Tank : public QGraphicsItem
{
public:
	Tank(int width, int height, QColor color, QGraphicsScene *scene, Missile *missile);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void rotateGun();
	QPoint getGunEndPos();
	QPoint getDownCenterPos();
	void setDownCenterPos(QPoint pos);
	int getGunAngle();
	void setGunAngle(int angle);
	int getShotPower();
	void setShotPower(int power);
	Missile *getMissile();
	void setMissile(Missile *missile);

private:
	int width;
	int height;
	int gunAngle;
	int shotPower;
	QColor color;
	Gun *gun;
	Missile *loadedMissile;
};

