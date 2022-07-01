#pragma once

#include <QWidget>
#include <QQueue>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGroupBox>

class ControlMenu : public QWidget
{
    Q_OBJECT

private:
    QQueue<int> shapesQueue_ {};

    QPushButton *renderButton_ {nullptr};
    QPushButton *clearButton_ {nullptr};

    QHBoxLayout *menuLayout_ {nullptr};
    QGroupBox *menuGroupBox_ {nullptr};

public:
    ControlMenu(QWidget *parent = nullptr) noexcept;
    ~ControlMenu();

    QQueue<int> getShapesQueue() const;

signals :
    void sendShapesQueue(QQueue<int> shapesQueue);
    void clearButtonWasClicked();

private slots:
    void renderButtonWasClicked();
    void clearShapesQueue();

public slots:
    void addShapeInQueue(int shape);
};
