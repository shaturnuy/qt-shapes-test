#pragma once

#include "shapecounterwidget.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QGroupBox>

class ShapesMenu : public QWidget
{
    Q_OBJECT

private:
    ShapeCounterWidget *triangleCounter_ {nullptr};
    ShapeCounterWidget *circleCounter_ {nullptr};
    ShapeCounterWidget *squareCounter_ {nullptr};

    QHBoxLayout *menuLayout_ {nullptr};
    QGroupBox *menuGroupBox_ {nullptr};

public:
    ShapesMenu(unsigned int buttonSize = 100, QWidget *parent = nullptr) noexcept;
    ~ShapesMenu();

signals:
    void sendShape(int shape);

public slots:
    void defineShape();
    void resetCounters();
};
