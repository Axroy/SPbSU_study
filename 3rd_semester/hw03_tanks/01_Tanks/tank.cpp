#include "tank.h"


Tank::Tank(qreal width, qreal height) : width(width), height(height), gun(new Gun(width / 2, height / 3))
{
}

QRectF Tank::boundingRect() const
{
	qreal penWidth = 1;
	return QRectF(- width - penWidth / 2, - height - penWidth / 2,
				  width + penWidth, height + penWidth);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawRect(QRectF(- width, - height, width, height));
	gun->paint(painter, option, widget);
}

void Tank::rotateGun(int angle)
{
	gun->setRotation(angle);
}
