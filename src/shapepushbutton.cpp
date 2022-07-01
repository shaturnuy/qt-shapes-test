#include "shapepushbutton.h"

ShapePushButton::ShapePushButton(int shape, unsigned int buttonSize, QWidget *parent) noexcept :
    QPushButton {parent},
    shape_ {shape}
{
    setFixedSize(buttonSize, buttonSize);
}

/*------------------------------------------------------------------------------------------------*/
void ShapePushButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);
    QPainter painter(this);
    painter.setPen(Qt::NoPen);

    switch(shape_)
    {
    case ShapePushButton::Shape::Triangle :
        drawTriangle(&painter);
        break;
    case ShapePushButton::Shape::Circle :
        drawCircle(&painter);
        break;
    case ShapePushButton::Shape::Square :
        drawSquare(&painter);
        break;
    default :
        break;
    }
}

/*------------------------------------------------------------------------------------------------*/
QPolygonF ShapePushButton::buildTriangle() const
{
    QPolygonF triangle;
    triangle.append(QPointF(rect().center().x(), rect().center().y() - height() / 4));
    triangle.append(QPointF(rect().center().x() + width() / 4, rect().center().x() + height() / 4));
    triangle.append(QPointF(rect().center().x() - width() / 4, rect().center().x() + height() / 4));
    triangle.append(QPointF(rect().center().x(), rect().center().y() - height() / 4));

    return triangle;
}

/*------------------------------------------------------------------------------------------------*/
QRect ShapePushButton::buildSquare() const
{
    QRect square(0, 0, width() / 2, height() / 2);
    square.moveTo(rect().center() - square.center());

    return square;
}

/*------------------------------------------------------------------------------------------------*/
void ShapePushButton::drawTriangle(QPainter *painter) const
{
    painter->setBrush(Qt::darkRed);
    painter->drawPolygon(buildTriangle());
}

/*------------------------------------------------------------------------------------------------*/
void ShapePushButton::drawCircle(QPainter *painter) const
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(buildSquare());
}

/*------------------------------------------------------------------------------------------------*/
void ShapePushButton::drawSquare(QPainter *painter) const
{
    painter->setBrush(Qt::darkBlue);
    painter->drawRect(buildSquare());
}
