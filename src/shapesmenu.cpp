#include "shapesmenu.h"

ShapesMenu::ShapesMenu(unsigned int buttonSize, QWidget *parent) noexcept
    : QWidget {parent}
{
    triangleCounter_ = new ShapeCounterWidget(ShapePushButton::Shape::Triangle, buttonSize);
    circleCounter_ = new ShapeCounterWidget(ShapePushButton::Shape::Circle, buttonSize);
    squareCounter_ = new ShapeCounterWidget(ShapePushButton::Shape::Square, buttonSize);

    menuLayout_ = new QHBoxLayout(this);
    menuLayout_->addWidget(triangleCounter_);
    menuLayout_->addWidget(circleCounter_);
    menuLayout_->addWidget(squareCounter_);
    menuLayout_->setSpacing(0);

    menuGroupBox_ = new QGroupBox(this);
    menuGroupBox_->setLayout(menuLayout_);
    menuGroupBox_->setStyleSheet("QGroupBox {border:0;}");
    setMinimumSize(menuGroupBox_->sizeHint());

    connect(triangleCounter_, &ShapeCounterWidget::buttonWasClicked, this, &ShapesMenu::defineShape);
    connect(circleCounter_, &ShapeCounterWidget::buttonWasClicked, this, &ShapesMenu::defineShape);
    connect(squareCounter_, &ShapeCounterWidget::buttonWasClicked, this, &ShapesMenu::defineShape);
}

/*------------------------------------------------------------------------------------------------*/
void ShapesMenu::defineShape()
{
    if (sender() == triangleCounter_)
        emit sendShape(ShapePushButton::Shape::Triangle);
    if (sender() == circleCounter_)
        emit sendShape(ShapePushButton::Shape::Circle);
    if (sender() == squareCounter_)
        emit sendShape(ShapePushButton::Shape::Square);
}

/*------------------------------------------------------------------------------------------------*/
void ShapesMenu::resetCounters()
{
    triangleCounter_->resetClickCounter();
    circleCounter_->resetClickCounter();
    squareCounter_->resetClickCounter();
}

/*------------------------------------------------------------------------------------------------*/
ShapesMenu::~ShapesMenu()
{
    delete triangleCounter_;
    delete circleCounter_;
    delete squareCounter_;
    delete menuLayout_;
    delete menuGroupBox_;
}
