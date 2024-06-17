#ifndef CANVAS_H
#define CANVAS_H

#include <QList>
#include <QRectF>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QMouseEvent>
#include <CustomRectangle.h>
#include <QAbstractListModel>
#include <memory>

class Canvas : public QQuickPaintedItem, QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit Canvas(QQuickItem *parent = nullptr, QObject *_parent = nullptr);

    void paint(QPainter *painter) override;
    QString name() const;
    void setName(QString name);
    Q_INVOKABLE void addRectangle(qreal x, qreal y, qreal width, qreal height);
    Q_INVOKABLE void print();

    Q_INVOKABLE void checkIntersect(double mouseX, double mouseY);
signals:
    void nameChanged(QString);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    QList<CustomRectangle *> rectangles; // List to store rectangle
    CustomRectangle *selectedOne;
    QString m_name;
};

#endif // CANVAS_H
