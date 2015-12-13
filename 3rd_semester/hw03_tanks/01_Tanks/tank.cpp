#include "tank.h"


Tank::Tank(int width, int height, QColor color, QGraphicsScene *scene) : width(width), height(height),
	color(color), gun(new Gun(width / 2, height / 3, color))
{
	scene->addItem(gun);
	this->setTransformOriginPoint(-width / 2, -height / 2);
	gun->setTransformOriginPoint(-width / 2, -height / 6);
	gun->setPos(0, -height / 2 + height / 6);
	gun->setParentItem(this);
	gun->setRotation(-90);
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
	painter->fillRect(QRectF(- width, - height, width, height), color);
}

void Tank::rotateGun(int angle)
{
	gun->setRotation(angle);
}

QPoint Tank::getGunEndPos()
{
	return gun->mapToScene(gun->pos().x(), gun->pos().y() + height / 6).toPoint();
}

QPoint Tank::getDownCenterPos()
{
	return QPoint(pos().x() - width / 2, pos().y());
}

void Tank::setDownCenterPos(QPoint pos)
{
	setPos(pos.x() + width / 2, pos.y());
}

