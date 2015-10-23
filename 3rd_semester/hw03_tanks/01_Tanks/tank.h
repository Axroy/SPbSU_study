#pragma once

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

class Tank : public QGraphicsItem
{
public:
	Tank(qreal width, qreal height);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	qreal width;
	qreal height;
};

