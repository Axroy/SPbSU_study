#include "landscape.h"

Landscape::Landscape()
{
	points = new QVector<QPoint>(10);
	points->append(QPoint(0, 0));
	points->append(QPoint(10, -10));
	points->append(QPoint(50, -10));
	points->append(QPoint(70, -50));
	points->append(QPoint(100, 0));
	points->append(QPoint(150, 10));
	points->append(QPoint(200, 25));
	points->append(QPoint(300, -30));
	points->append(QPoint(320, 0));
	points->append(QPoint(340, -20));
}

QPoint Landscape::getPoint(int index)
{
	return points->at(index);
}

int Landscape::getNumberOfPoints()
{
	return points->size();
}

int Landscape::getYCoordinate(int x)
{
	QPoint previousPoint = getClosestPoints(x).first;
	QPoint nextPoint = getClosestPoints(x).second;
	int ratio = (x - previousPoint.x()) / (nextPoint.x() - x);
	return (previousPoint.y() + ratio * nextPoint.y()) / (1 + ratio);
}

QPair<QPoint, QPoint> Landscape::getClosestPoints(int x)
{
	QPoint previousPoint = points->at(0);
	QPoint nextPoint = points->at(0);
	for (int i = 0; i < points->size(); i++)
	{
		if (points->at(i).x() > x)
		{
			nextPoint = points->at(i);
			break;
		}
		previousPoint = points->at(i);
	}
	return QPair<QPoint, QPoint>(previousPoint, nextPoint);
}

