#include "gun.h"

Gun::Gun(qreal width, qreal height) : width(width), height(height)
{
}

QRectF Gun::boundingRect() const
{
	qreal penWidth = 1;
	return QRectF(- width - penWidth / 2, - height - penWidth / 2,
				  width + penWidth, height + penWidth);
}

void Gun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawRect(QRectF(- width, - height, width, height));
}

