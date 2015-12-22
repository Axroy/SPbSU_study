#include "explosion.h"

Explosion::Explosion(int initialRadius, QColor color) : radius(initialRadius), maxRadius(initialRadius * 3),
	maxed(false), color(color)
{
}

QRectF Explosion::boundingRect() const
{
	qreal penWidth = 1;
	return QRectF(- radius - penWidth / 2, - radius - penWidth / 2,
				  radius * 2 + penWidth, radius * 2 + penWidth);
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->setPen(color);
	painter->setBrush(QBrush(color));
	painter->drawEllipse(QRectF(- radius, - radius, radius * 2, radius * 2));
}

void Explosion::updateExplosionSize()
{
	radius += 1;
	if (radius > maxRadius)
		maxed = true;
}

bool Explosion::isMaxed()
{
	return maxed;
}

