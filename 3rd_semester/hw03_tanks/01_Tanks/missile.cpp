#include "missile.h"

Missile::Missile(qreal radius) : radius(radius)
{
}

QRectF Missile::boundingRect() const
{
	qreal penWidth = 1;
	return QRectF(- radius - penWidth / 2, - radius - penWidth / 2,
				  radius * 2 + penWidth, radius * 2 + penWidth);
}

void Missile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawEllipse(QRectF(- radius, - radius, radius * 2, radius * 2));
}

