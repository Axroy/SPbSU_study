#pragma once

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QGraphicsScene>

#include "gun.h"

class Tank : public QGraphicsItem
{
public:
	Tank(int width, int height, QColor color, QGraphicsScene *scene);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void rotateGun(int angle);
	QPoint getGunEndPos();
	QPoint getDownCenterPos();
	void setDownCenterPos(QPoint pos);

private:
	int width;
	int height;
	QColor color;
	Gun *gun;
};

