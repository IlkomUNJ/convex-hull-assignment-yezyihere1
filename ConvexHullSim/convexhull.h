#ifndef CONVEXHULL_H
#define CONVEXHULL_H

#include <QList>
#include <QPoint>

class ConvexHull {
public:

    static QList<QPoint> slowHull(const QList<QPoint>& points, int &iterations);
    static QList<QPoint> fastHull(const QList<QPoint>& points, int &iterations);

private:

    static int crossProduct(const QPoint& p1, const QPoint& p2, const QPoint& p3);
};

#endif
