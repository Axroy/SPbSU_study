#pragma once

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

class Explosion : public QGraphicsItem
{
public:
	Explosion(int initialRadius, QColor color);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void updateExplosionSize();
	bool isMaxed();

private:
	int radius;
	int maxRadius;
	bool maxed;
	QColor color;
};

