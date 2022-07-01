#pragma once

#include "shapesmenu.h"
#include "controlmenu.h"
#include "displayarea.h"

#include <QWidget>
#include <QBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    ShapesMenu *shapesMenu_ {nullptr};
    ControlMenu *controlMenu_ {nullptr};
    DisplayArea *displayArea_ {nullptr};

    QVBoxLayout *renderLayout_ {nullptr};
    QHBoxLayout *mainLayout_ {nullptr};

public:
    MainWindow(QWidget *parent = nullptr) noexcept;
    ~MainWindow();
};
