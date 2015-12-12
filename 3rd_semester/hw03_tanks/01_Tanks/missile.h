#pragma once

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

#include "explosion.h"

class Missile : public QGraphicsItem
{
public:
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	Explosion *explode(QGraphicsScene *scene);
	int getWeight();

protected:
	qreal radius;
	int weight;
	Explosion *explosion;
};

