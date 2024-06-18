#ifndef CUSTOMRECTANGLE_H
#define CUSTOMRECTANGLE_H

#include <QRectF>
#include <QPen>
#include <QBrush>
#include <QObject>

class CustomRectangle : public QObject {
    Q_OBJECT
    Q_PROPERTY(qreal Index READ Index WRITE setIndex NOTIFY IndexChanged)

public:
    CustomRectangle(const QRectF &r, const QPen &p = QPen(), const QBrush &b = QBrush(), qreal idx = 0);


private:
    QRectF rect;
    QPen pen;
    QBrush brush;
    qreal index;



};

#endif // CUSTOMRECTANGLE_H
