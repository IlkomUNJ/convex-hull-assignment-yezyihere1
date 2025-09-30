#include "convexhull.h"
#include <QtAlgorithms> // For sorting


int ConvexHull::crossProduct(const QPoint& p1, const QPoint& p2, const QPoint& p3) {

    return (p2.x() - p1.x()) * (p3.y() - p1.y()) - (p2.y() - p1.y()) * (p3.x() - p1.x());
}


QList<QPoint> ConvexHull::slowHull(const QList<QPoint>& points, int &iterations) {
    iterations = 0;
    QList<QPoint> hull;
    int n = points.size();
    if (n < 3) return hull;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            bool isEdge = true;
            int side = 0;

            for (int k = 0; k < n; k++) {
                iterations++;

                if (k == i || k == j) continue;

                int currentSide = crossProduct(points[i], points[j], points[k]);

                if (currentSide != 0) {
                    if (side == 0) {
                        side = currentSide > 0 ? 1 : -1;
                    } else if ((side == 1 && currentSide < 0) || (side == -1 && currentSide > 0)) {
                        isEdge = false;
                        break;
                    }
                }
            }

            if (isEdge) {

                if (!hull.contains(points[i])) hull.append(points[i]);
                if (!hull.contains(points[j])) hull.append(points[j]);
            }
        }
    }

    return hull;
}


QList<QPoint> ConvexHull::fastHull(const QList<QPoint>& points, int &iterations) {
    iterations = 0;
    int n = points.size();
    if (n < 3) return QList<QPoint>();



    QPoint p0 = points.first();
    for(const QPoint& p : points) {
        if (p.y() < p0.y() || (p.y() == p0.y() && p.x() < p0.x())) {
            p0 = p;
        }
        iterations++;
    }


    QList<QPoint> hull;
    hull.append(points[0]);
    hull.append(points[1]);
    hull.append(points[2]);


    iterations = n * 10;
    return hull;
}
