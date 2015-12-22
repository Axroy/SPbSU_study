#pragma once

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

/// A tank's gun
class Gun : public QGraphicsItem
{
public:
	Gun(int width, int height, QColor color);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
	int width;
	int height;
	QColor color;
};

