#include "Canvas.h"
#include <iostream>

Canvas::Canvas(QQuickItem *parent)
: QQuickPaintedItem(parent)
{}

void Canvas::paint(QPainter *painter)
{
    // Draw the canvas border
    painter->setBrush(QBrush(QColor(250, 250, 250,0)));  // Transparent brush
    painter->setPen(QPen(Qt::blue, 2));
    painter->drawRect(0,0, width(), height());
    // Draw all rectangles
    for (CustomRectangle &customRect : rectangles) {
        if (&customRect != selectedOne){
            painter->setPen(customRect.pen);
            painter->setBrush(customRect.brush);
        } else {
            painter->setPen(QPen(Qt::red));
            painter->setBrush(customRect.brush);
        }
        painter->drawRect(customRect.rect);
    }
}

void Canvas::addRectangle(qreal x, qreal y, qreal width, qreal height)
{
    rectangles.append(CustomRectangle(QRectF(x, y, width, height), QPen(Qt::blue, 2), QBrush(QColor(250, 250, 250,0))));
    update();
    qDebug() << "Added rectangle: " << x << y << width << height;
}

void Canvas::print()
{
    std::cout << "Canvas method called!" << std::endl;
}

void Canvas::setName(QString name)
{
    m_name = name;
    std::cout << "setName: " << std::endl;
    emit nameChanged(name);
}

QString Canvas::name() const
{
    std::cout << "getName: " << std::endl;
    return m_name;
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    std::cout << "mouse pressed at " << event->globalX() << event->globalY() <<  std::endl;
    for (const CustomRectangle &rect : rectangles) {
        if (rect.rect.contains(event->pos())) {
            std::cout << "rectangle clicked" << std::endl;
            break;
        }
    }
    QQuickPaintedItem::mousePressEvent(event);
}

void Canvas::checkIntersect(qreal mouseX, qreal mouseY) {
    bool found = false; // To track if any rectangle was clicked
    for (int i = 0; i < rectangles.size(); ++i) {
        CustomRectangle &rect = rectangles[i];
        qreal RectX1, RectY1, RectX2, RectY2;
        rect.rect.getCoords(&RectX1, &RectY1, &RectX2, &RectY2);

        if (mouseX > RectX1 && mouseX < RectX2 && mouseY > RectY1 && mouseY < RectY2) {
            std::cout << "Rectangle clicked!" << std::endl;
            selectedOne = &rect;
            found = true; // Set the flag to true when a rectangle is clicked
            break; // Exit the loop since a rectangle was found
        }
    }

    if (!found) {
        std::cout << "No Rectangle clicked!" << std::endl;
        selectedOne = nullptr;
    }

    update();
}

