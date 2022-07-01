#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) noexcept
    : QWidget(parent)
{
    shapesMenu_ = new ShapesMenu;
    controlMenu_ = new ControlMenu;
    displayArea_ = new DisplayArea;

    renderLayout_ = new QVBoxLayout;
    renderLayout_->addWidget(displayArea_);
    renderLayout_->addWidget(controlMenu_);
    renderLayout_->setAlignment(displayArea_, Qt::AlignCenter);
    renderLayout_->setAlignment(controlMenu_, Qt::AlignCenter);

    mainLayout_ = new QHBoxLayout;
    mainLayout_->addLayout(renderLayout_);
    mainLayout_->addWidget(shapesMenu_);
    mainLayout_->setAlignment(shapesMenu_, Qt::AlignCenter | Qt::AlignLeft);
    mainLayout_->setAlignment(Qt::AlignCenter);
    setLayout(mainLayout_);

    connect(shapesMenu_, &ShapesMenu::sendShape, controlMenu_, &ControlMenu::addShapeInQueue);
    connect(controlMenu_, &ControlMenu::sendShapesQueue, displayArea_, &DisplayArea::draw);

    connect(controlMenu_, &ControlMenu::clearButtonWasClicked, shapesMenu_, &ShapesMenu::resetCounters);
    connect(controlMenu_, &ControlMenu::clearButtonWasClicked, displayArea_, &DisplayArea::hideAllShapes);
}

/*------------------------------------------------------------------------------------------------*/
MainWindow::~MainWindow()
{
    delete shapesMenu_;
    delete controlMenu_;
    delete displayArea_;
    delete renderLayout_;
    delete mainLayout_;
}
