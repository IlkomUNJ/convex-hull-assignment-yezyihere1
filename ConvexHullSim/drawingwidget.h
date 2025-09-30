#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QWidget>
#include <QPoint>
#include <QList>

class DrawingWidget : public QWidget {
    Q_OBJECT

public:
    explicit DrawingWidget(QWidget *parent = nullptr);

    void clearCanvas();

    void runConvexHull();

protected:

    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

private:
    QList<QPoint> inputPoints;
    QList<QPoint> hullPoints;
    QString iterationText;

};

#endif
