#include "gun.h"

Gun::Gun(int width, int height, QColor color) : width(width), height(height), color(color)
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
	painter->fillRect(QRectF(- width, - height, width, height), color);
}

