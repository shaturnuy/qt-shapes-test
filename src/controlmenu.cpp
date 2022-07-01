#include "controlmenu.h"

ControlMenu::ControlMenu(QWidget *parent) noexcept
    : QWidget{parent}
{
    renderButton_ = new QPushButton("Отобразить");
    clearButton_ = new QPushButton("Очистить");

    menuLayout_ = new QHBoxLayout(this);
    menuLayout_->addWidget(renderButton_);
    menuLayout_->addWidget(clearButton_);

    menuGroupBox_ = new QGroupBox(this);
    menuGroupBox_->setLayout(menuLayout_);
    menuGroupBox_->setStyleSheet("QGroupBox {border:0;} QPushButton {font: 14px;}");
    setMinimumSize(menuGroupBox_->sizeHint());


    connect(renderButton_, &QPushButton::clicked, this, &ControlMenu::renderButtonWasClicked);

    connect(clearButton_, &QPushButton::clicked, this, &ControlMenu::clearButtonWasClicked);
    connect(clearButton_, &QPushButton::clicked, this, &ControlMenu::clearShapesQueue);
}

/*------------------------------------------------------------------------------------------------*/
QQueue<int> ControlMenu::getShapesQueue() const
{
    return shapesQueue_;
}

/*------------------------------------------------------------------------------------------------*/
void ControlMenu::renderButtonWasClicked()
{
    emit sendShapesQueue(getShapesQueue());
}

/*------------------------------------------------------------------------------------------------*/
void ControlMenu::clearShapesQueue()
{
    shapesQueue_.clear();
}

/*------------------------------------------------------------------------------------------------*/
void ControlMenu::addShapeInQueue(int shape)
{
    shapesQueue_.enqueue(shape);
}

/*------------------------------------------------------------------------------------------------*/
ControlMenu::~ControlMenu()
{
    delete renderButton_;
    delete clearButton_;
    delete menuLayout_;
    delete menuGroupBox_;
}
