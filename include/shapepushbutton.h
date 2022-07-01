#pragma once

#include <QPushButton>
#include <QPainter>

class ShapePushButton : public QPushButton
{
    Q_OBJECT

private:
    int shape_;

    void paintEvent(QPaintEvent *event);

    QPolygonF buildTriangle() const;
    QRect buildSquare() const;

    void drawTriangle(QPainter *painter) const;
    void drawCircle(QPainter *painter) const;
    void drawSquare(QPainter *painter) const;

public:
    explicit ShapePushButton(int shape, unsigned int buttonSize, QWidget *parent = nullptr) noexcept;
    ~ShapePushButton() {};

    enum Shape {Triangle, Circle, Square};
};
