#pragma once

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

#include "gun.h"

class Tank : public QGraphicsItem
{
public:
	Tank(qreal width, qreal height);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void rotateGun(int angle);

private:
	qreal width;
	qreal height;
	Gun *gun;
};
