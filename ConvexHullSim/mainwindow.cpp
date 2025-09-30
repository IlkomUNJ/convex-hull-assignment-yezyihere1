#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawingwidget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    DrawingWidget *canvas = new DrawingWidget(this);
    QPushButton *fixButton = new QPushButton("Fix Convex Hull");
    QPushButton *clearButton = new QPushButton("Clear Canvas");


    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(fixButton);
    buttonLayout->addWidget(clearButton);

    QWidget *buttonContainer = new QWidget();
    buttonContainer->setLayout(buttonLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(canvas);
    mainLayout->addWidget(buttonContainer);


    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    setWindowTitle("Computer Graphics Simulation");


    connect(clearButton, &QPushButton::clicked, canvas, &DrawingWidget::clearCanvas);
    connect(fixButton, &QPushButton::clicked, canvas, &DrawingWidget::runConvexHull);
}

MainWindow::~MainWindow()
{
    delete ui;
}
