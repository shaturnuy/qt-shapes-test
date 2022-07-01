#include "displayarea.h"

DisplayArea::DisplayArea(QWidget *parent) noexcept
    : QWidget{parent}
{
    shapesScene_ = new QGraphicsScene;

    shapesView_ = new QGraphicsView;
    shapesView_->setFixedSize(SHAPES_VIEW_SIZE, SHAPES_VIEW_SIZE);
    shapesView_->setScene(shapesScene_);
    shapesView_->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    displayLayout_ = new QVBoxLayout(this);
    displayLayout_->setAlignment(Qt::AlignCenter);
    displayLayout_->addWidget(shapesView_);

    displayGroupBox_ = new QGroupBox(this);
    displayGroupBox_->setLayout(displayLayout_);
    displayGroupBox_->setStyleSheet("QGroupBox {border:0;}");
    setMinimumSize(displayGroupBox_->sizeHint());
}

/*------------------------------------------------------------------------------------------------*/
void DisplayArea::shiftLastUsedCoordinate()
{
    if (lastUsedCoordinate.x + ROW_OFFSET < SHAPES_VIEW_SIZE)
    {
        lastUsedCoordinate.x += SHAPE_SIZE + SHAPE_OFFSET;
    }
    else if (lastUsedCoordinate.y + ROW_OFFSET < SHAPES_VIEW_SIZE)
    {
        lastUsedCoordinate.x = ROW_OFFSET;
        lastUsedCoordinate.y += SHAPE_SIZE + SHAPE_OFFSET;
    }
    else
    {
        ROW_OFFSET += SHAPE_OFFSET;
        lastUsedCoordinate.x = ROW_OFFSET;
        lastUsedCoordinate.y = ROW_OFFSET;
    }
}

/*------------------------------------------------------------------------------------------------*/
void DisplayArea::addShapeOnScene(const Shape *shape) const
{
    shapesScene_->addItem(shape->getTriangleLeftSide());
    shapesScene_->addItem(shape->getTriangleRightSide());
    shapesScene_->addItem(shape->getTriangleBotSide());
    shapesScene_->addItem(shape->getCircle());
    shapesScene_->addItem(shape->getSquare());
}

/*------------------------------------------------------------------------------------------------*/
void DisplayArea::drawShape(int shapeIndex, Shape *shape) const
{
    switch (shapeIndex)
    {
    case ShapePushButton::Shape::Triangle :
        shape->drawTriangle();
        break;
    case ShapePushButton::Shape::Circle :
        shape->drawCircle();
        break;
    case ShapePushButton::Shape::Square :
        shape->drawSquare();
        break;
    default:
        break;
    }
}

/*------------------------------------------------------------------------------------------------*/
void DisplayArea::draw(QQueue<int> shapesQueue)
{
    for (auto currentSize = shapesStorage.size(); currentSize < shapesQueue.size(); currentSize++)
    {
        shapesStorage.append(new Shape(lastUsedCoordinate, SHAPE_SIZE));
        addShapeOnScene(shapesStorage[currentSize]);
        shiftLastUsedCoordinate();
    }

    size_t shapesStorageIndex {0};
    while (!shapesQueue.isEmpty())
    {
        drawShape(shapesQueue.head(), shapesStorage[shapesStorageIndex++]);
        shapesQueue.dequeue();
    }
}

/*------------------------------------------------------------------------------------------------*/
void DisplayArea::hideAllShapes()
{
    for (auto index {0}; index < shapesStorage.size(); index++)
        shapesStorage[index]->hideShape();
}

/*------------------------------------------------------------------------------------------------*/
DisplayArea::~DisplayArea()
{
    delete shapesScene_;
    delete shapesView_;
    delete displayLayout_;
    delete displayGroupBox_;
}
