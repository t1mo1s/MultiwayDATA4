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

    CustomRectangle(const QRectF &r, const QPen &p = QPen(), const QBrush &b = QBrush());
};

#endif // CUSTOMRECTANGLE_H
