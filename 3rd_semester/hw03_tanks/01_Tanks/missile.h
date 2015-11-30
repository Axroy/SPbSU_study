#pragma once

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

class Missile : public QGraphicsItem
{
public:
	Missile(qreal radius);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	qreal radius;
};

