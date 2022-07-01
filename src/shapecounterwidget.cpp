#include "shapecounterwidget.h"

ShapeCounterWidget::ShapeCounterWidget(int shape, unsigned int buttonSize, QWidget *parent) noexcept
    : QWidget {parent},
      clickCounter_ {0}
{
    shapePushButton_ = new ShapePushButton(shape, buttonSize);

    clickCounterLabel_ = new QLabel(QString::number(clickCounter_));
    clickCounterLabel_->setAlignment(Qt::AlignCenter);
    clickCounterLabel_->setFixedSize(buttonSize, buttonSize / 4);
    clickCounterLabel_->setStyleSheet("font: 14px;");

    widgetLayout_ = new QVBoxLayout(this);
    widgetLayout_->addWidget(shapePushButton_);
    widgetLayout_->addWidget(clickCounterLabel_);
    widgetLayout_->setSpacing(buttonSize / 25);

    widgetGroupBox_ = new QGroupBox(this);
    widgetGroupBox_->setLayout(widgetLayout_);
    widgetGroupBox_->setFlat(true);
    setMinimumSize(widgetGroupBox_->sizeHint());

    connect(shapePushButton_, &QPushButton::clicked, this, &ShapeCounterWidget::increaseClickCounter);
    connect(shapePushButton_, &QPushButton::clicked, this, &ShapeCounterWidget::buttonWasClicked);
}

/*------------------------------------------------------------------------------------------------*/
void ShapeCounterWidget::resetClickCounter()
{
    clickCounter_ = 0;
    clickCounterLabel_->setText(QString::number(clickCounter_));
}

/*------------------------------------------------------------------------------------------------*/
void ShapeCounterWidget::increaseClickCounter()
{
    clickCounterLabel_->setText(QString::number(++clickCounter_));
}

/*------------------------------------------------------------------------------------------------*/
ShapeCounterWidget::~ShapeCounterWidget()
{
    delete clickCounterLabel_;
    delete shapePushButton_;
    delete widgetLayout_;
    delete widgetGroupBox_;
}
