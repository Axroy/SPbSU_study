#pragma once

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QTimer>

#include "explosion.h"

class Missile : public QGraphicsItem
{
public:
	Missile(qreal radius, QPointF position);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	Explosion *explode(QGraphicsScene *scene);

private:
	qreal radius;
	Explosion *explosion;
};

