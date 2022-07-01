#include "shape.h"

Shape::Shape(Coordinate startCoordinate, int shapeSize) noexcept
{
    triangleLeftSide_ = new QGraphicsLineItem(startCoordinate.x, startCoordinate.y + shapeSize,
                                             startCoordinate.x + shapeSize / 2, startCoordinate.y);
    triangleRightSide_ = new QGraphicsLineItem(startCoordinate.x + shapeSize / 2, startCoordinate.y,
                                              startCoordinate.x + shapeSize, startCoordinate.y + shapeSize);
    triangleBotSide_ = new QGraphicsLineItem(startCoordinate.x + shapeSize, startCoordinate.y + shapeSize,
                                            startCoordinate.x, startCoordinate.y + shapeSize);

    circle_ = new QGraphicsEllipseItem(startCoordinate.x, startCoordinate.y, shapeSize, shapeSize);
    square_ = new QGraphicsRectItem(startCoordinate.x, startCoordinate.y, shapeSize, shapeSize);

    hideShape();
}

/*------------------------------------------------------------------------------------------------*/
void Shape::drawTriangle() const
{
    triangleLeftSide_->setVisible(true);
    triangleRightSide_->setVisible(true);
    triangleBotSide_->setVisible(true);
}

/*------------------------------------------------------------------------------------------------*/
void Shape::drawCircle() const
{
    circle_->setVisible(true);
}

/*------------------------------------------------------------------------------------------------*/
void Shape::drawSquare() const
{
    square_->setVisible(true);
}

/*------------------------------------------------------------------------------------------------*/
void Shape::hideShape() const
{
    triangleLeftSide_->setVisible(false);
    triangleRightSide_->setVisible(false);
    triangleBotSide_->setVisible(false);
    circle_->setVisible(false);
    square_->setVisible(false);
}

/*------------------------------------------------------------------------------------------------*/
Shape::~Shape()
{
    delete triangleLeftSide_;
    delete triangleRightSide_;
    delete triangleBotSide_;
    delete circle_;
    delete square_;
}
