#ifndef CUSTOMRECTANGLE_H
#define CUSTOMRECTANGLE_H

#include <QRectF>
#include <QPen>
#include <QBrush>
#include <QObject>

class CustomRectangle : public QObject {
    Q_OBJECT
    Q_PROPERTY(qreal index READ index WRITE setIndex NOTIFY indexChanged)

public:
    explicit CustomRectangle(const QRectF &r = QRectF(),
                             const QPen &p = QPen(),
                             const QBrush &b = QBrush(),
                             qreal idx = 0);
    //getters and setters
    qreal index() const;
    void setIndex(qreal newIndex);

    QPen pen() const;

    QBrush brush() const;

    QRectF rect() const;

signals:
    void indexChanged();

private:
    QRectF _rect;
    QPen _pen;
    QBrush _brush;
    qreal _index;
};

#endif // CUSTOMRECTANGLE_H
