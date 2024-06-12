#include "Canvas.h"
#include <iostream>

Canvas::Canvas(QQuickItem *parent)
: QQuickPaintedItem(parent)
{

}


void Canvas::paint(QPainter *painter)
{
    painter->setBrush(QBrush(QColor(173, 216, 230)));  // Light blue color
        painter->setPen(QPen(Qt::blue, 2));

        for (const QRectF &rect : rectangles) {
            painter->drawRect(rect);
        }
}

void Canvas::addRectangle(qreal x, qreal y, qreal width, qreal height)
{
    rectangles.append(QRectF(x, y, width, height));
    update();
    qDebug() << "Added rectangle: " << x << y << width << height;
}

void Canvas::print(){
    std::cout << "Canvas method called!" << std::endl;
}
