#ifndef RECTANGLEMODEL_H
#define RECTANGLEMODEL_H

#include <QAbstractListModel>
#include "CustomRectangle.h"
#include <memory>

class RectangleModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        IndexRole = Qt::UserRole + 1,
        // other roles as needed
    };

    explicit RectangleModel(QObject *parent = nullptr);


    // need to override this methods because qabstractlsitmodel
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addRectangle(qreal x, qreal y, qreal width, qreal height);
    Q_INVOKABLE void removeRect(int index);
    //Q_INVOKABLE void updateRect(int index, int newIndex);
    void printRects();




private:
    QList<std::shared_ptr<CustomRectangle>> rectangles;

};

#endif // RECTANGLEMODEL_H
