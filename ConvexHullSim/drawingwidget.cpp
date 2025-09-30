#include "drawingwidget.h"
#include "convexhull.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPalette>

DrawingWidget::DrawingWidget(QWidget *parent) : QWidget(parent) {
    setMinimumSize(400, 300);


    QPalette pal = this->palette();

    pal.setColor(QPalette::Window, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    // ---------------------------------------------------
}

void DrawingWidget::mousePressEvent(QMouseEvent *event) {
    hullPoints.clear();
    iterationText.clear();
    inputPoints.append(event->pos());
    update();
}

void DrawingWidget::clearCanvas() {
    inputPoints.clear();
    hullPoints.clear();
    iterationText.clear();
    update();
}

void DrawingWidget::runConvexHull() {
    if (inputPoints.size() < 3) return;

    int slowIter = 0;
    int fastIter = 0;


    ConvexHull::slowHull(inputPoints, slowIter);


    hullPoints = ConvexHull::fastHull(inputPoints, fastIter);


    iterationText = QString("Slow Hull Iterations (O(N^3)): %1\nFast Hull Iterations (O(N log N)): %2")
                        .arg(slowIter)
                        .arg(fastIter);

    update();
}

void DrawingWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw Input Points
    painter.setPen(QPen(Qt::red, 5));
    for (const QPoint &p : inputPoints) {
        painter.drawPoint(p);
    }

    // Draw Convex Hull lines
    if (hullPoints.size() > 1) {
        painter.setPen(QPen(Qt::blue, 2));
        QPolygonF polygon(hullPoints.toVector());
        painter.drawPolygon(polygon);
    }

    // Draw Iteration Count Text
    if (!iterationText.isEmpty()) {
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 12));
        painter.drawText(10, 20, iterationText);
    }
}
