#pragma once

#include <QVector>
#include <QPoint>
#include <QPair>

/// Something to simulate the land
/// Consists of several points between which lines are drawn
class Landscape
{
public:
	Landscape();
	QPoint getPoint(int index);
	QPoint getFirstPoint();
	QPoint getLastPoint();
	int getNumberOfPoints();
	/// Returns y coordinate of a point on the landscape with x xoordinate
	int getYCoordinate(int x);
private:
	/// Returns a pair (closestToTheLeft, closestToTheRight)
	QPair<QPoint, QPoint> getClosestPoints(int x);
	QVector<QPoint> *points;
};

