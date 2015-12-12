#include "missile.h"

QRectF Missile::boundingRect() const
{
	qreal penWidth = 1;
	return QRectF(- radius - penWidth / 2, - radius - penWidth / 2,
				  radius * 2 + penWidth, radius * 2 + penWidth);
}

void Missile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->setBrush(QBrush(Qt::black));
	painter->drawEllipse(QRectF(- radius, - radius, radius * 2, radius * 2));
}

Explosion *Missile::explode(QGraphicsScene *scene)
{
	explosion = new Explosion(radius * 3, Qt::darkRed);
	scene->addItem(explosion);
	explosion->setPos(pos());
	return explosion;
}

int Missile::getWeight()
{
	return weight;
}

