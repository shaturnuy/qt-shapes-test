#pragma once

#include "shapepushbutton.h"

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>

class ShapeCounterWidget : public QWidget
{
    Q_OBJECT

private:
    unsigned int clickCounter_ {0};

    QLabel *clickCounterLabel_ {nullptr};
    ShapePushButton *shapePushButton_ {nullptr};

    QVBoxLayout *widgetLayout_ {nullptr};
    QGroupBox *widgetGroupBox_ {nullptr};

public:
    explicit ShapeCounterWidget(int shape, unsigned int buttonSize, QWidget *parent = nullptr) noexcept;
    ~ShapeCounterWidget();

    void resetClickCounter();

signals:
    void buttonWasClicked();

private slots:
    void increaseClickCounter();
};
