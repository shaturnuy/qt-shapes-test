#pragma once

#include "shapepushbutton.h"
#include "shape.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QQueue>
#include <QVector>

class DisplayArea : public QWidget
{
    Q_OBJECT

private:
    const int SHAPES_VIEW_SIZE {550};
    const int SHAPE_SIZE {50};
    const int SHAPE_OFFSET {5};
    int ROW_OFFSET {SHAPE_SIZE};

    QVector<Shape*> shapesStorage {};
    Coordinate lastUsedCoordinate {ROW_OFFSET, ROW_OFFSET};

    QGraphicsScene *shapesScene_ {nullptr};
    QGraphicsView *shapesView_ {nullptr};

    QVBoxLayout *displayLayout_ {nullptr};
    QGroupBox *displayGroupBox_ {nullptr};


    void shiftLastUsedCoordinate();
    void addShapeOnScene(const Shape *shape) const;
    void drawShape(int shapeIndex, Shape *shape) const;

public:
    DisplayArea(QWidget *parent = nullptr) noexcept;
    ~DisplayArea();

public slots:
    void draw(QQueue<int> shapesQueue);
    void hideAllShapes();
};
