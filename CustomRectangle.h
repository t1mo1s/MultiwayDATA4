#ifndef CUSTOMRECTANGLE_H
#define CUSTOMRECTANGLE_H

#include <QRectF>
#include <QPen>
#include <QBrush>

class CustomRectangle {
public:
    QRectF rect;
    QPen pen;
    QBrush brush;
    qreal index;

    CustomRectangle(const QRectF &r, const QPen &p = QPen(), const QBrush &b = QBrush(), qreal idx = 0);
};

#endif // CUSTOMRECTANGLE_H
