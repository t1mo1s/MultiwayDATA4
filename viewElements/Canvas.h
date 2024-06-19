#ifndef CANVAS_H
#define CANVAS_H

#include <QList>
#include <QRectF>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QMouseEvent>
#include <viewElements/CustomRectangle.h>

class Canvas : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QList<std::shared_ptr<CustomRectangle>> rectangles READ rectangles WRITE setRectangles NOTIFY rectanglesChanged)

public:
    explicit Canvas(QQuickItem *parent = nullptr);

    void paint(QPainter *painter) override;

    QString name() const;
    void setName(QString name);

    //rectangles property
    QList<std::shared_ptr<CustomRectangle>> rectangles() const;
    void setRectangles(QList<std::shared_ptr<CustomRectangle>> rectangles);

    Q_INVOKABLE void addRectangle(qreal x, qreal y, qreal width, qreal height);
    Q_INVOKABLE void print();

    Q_INVOKABLE void checkIntersect(double mouseX, double mouseY);
signals:
    void nameChanged(QString);
    void rectanglesChanged();

private:
    QList<std::shared_ptr<CustomRectangle>> _rectangles; // List to store rectangle
    std::shared_ptr<CustomRectangle> selectedOne;
    QString m_name;
};

#endif // CANVAS_H
