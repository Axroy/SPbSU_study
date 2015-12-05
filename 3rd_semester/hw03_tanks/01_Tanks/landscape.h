#pragma once

#include <QVector>
#include <QPoint>
#include <QPair>

class Landscape
{
public:
	Landscape();
	QPoint getPoint(int index);
	int getPointsNumber();
	int getYCoordinate(int x);
private:
	QPair<QPoint, QPoint> getClosestPoints(int x);

	QVector<QPoint> *points;
};

