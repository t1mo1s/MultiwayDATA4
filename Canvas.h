#ifndef CANVAS_H
#define CANVAS_H
#include <QList>
#include <QRectF>

#include <QQuickPaintedItem>
#include <QPainter>

class Canvas : public QQuickPaintedItem
{
    Q_OBJECT
public:
    Canvas(QQuickItem *parent = nullptr);

    void paint(QPainter *painter) override;

    Q_INVOKABLE void addRectangle(qreal x, qreal y, qreal width, qreal height);

    Q_INVOKABLE void print();
private:
    QList<QRectF> rectangles; // List to store rectangle
};

#endif // CANVAS_H
