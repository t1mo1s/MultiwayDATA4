#ifndef RECTANGLEMODEL_H
#define RECTANGLEMODEL_H

#include <QAbstractListModel>
#include "CustomRectangle.h"
#include <memory>

class RectangleModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit RectangleModel(QObject *parent = nullptr);


    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    void addRectangle(qreal x, qreal y, qreal width, qreal height);
    Q_INVOKABLE void removeRect(int index);
    Q_INVOKABLE void updateRect(int index, int newIndex);

private:
    QList<std::shared_ptr<CustomRectangle>> rectangles;

};

#endif // RECTANGLEMODEL_H
