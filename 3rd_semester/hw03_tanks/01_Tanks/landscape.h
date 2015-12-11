#pragma once

#include <QVector>
#include <QPoint>
#include <QPair>

class Landscape
{
public:
	Landscape();
	QPoint getPoint(int index);
	QPoint getFirstPoint();
	QPoint getLastPoint();
	int getNumberOfPoints();
	int getYCoordinate(int x);
private:
	QPair<QPoint, QPoint> getClosestPoints(int x);
	QVector<QPoint> *points;
};

