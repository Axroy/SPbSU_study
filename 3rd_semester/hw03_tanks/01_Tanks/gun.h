#pragma once

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

class Gun : public QGraphicsItem
{
public:
	Gun(qreal width, qreal height, QColor color);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
	qreal width;
	qreal height;
	QColor color;
};

