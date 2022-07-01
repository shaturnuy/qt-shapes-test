#pragma once

#include <QGraphicsItem>

struct Coordinate;

class Shape
{
private:
    QGraphicsLineItem *triangleLeftSide_ {nullptr};
    QGraphicsLineItem *triangleRightSide_ {nullptr};
    QGraphicsLineItem *triangleBotSide_ {nullptr};

    QGraphicsEllipseItem *circle_ {nullptr};
    QGraphicsRectItem *square_ {nullptr};

public:
    explicit Shape(Coordinate startCoordinate, int shapeSize) noexcept;
    ~Shape();

    inline QGraphicsLineItem* getTriangleLeftSide() const {return triangleLeftSide_;};
    inline QGraphicsLineItem* getTriangleRightSide() const {return triangleRightSide_;};
    inline QGraphicsLineItem* getTriangleBotSide() const {return triangleBotSide_;};
    inline QGraphicsEllipseItem* getCircle() const {return circle_;};
    inline QGraphicsRectItem* getSquare() const {return square_;};

    void drawTriangle() const;
    void drawCircle() const;
    void drawSquare() const;
    void hideShape() const;
};

struct Coordinate
{
    int x;
    int y;
    Coordinate() : x{0}, y{0} {};
    Coordinate(int x, int y) : x{x}, y{y} {};
};
