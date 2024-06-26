#ifndef RECTANGLEMODEL_H
#define RECTANGLEMODEL_H

#include <QAbstractListModel>
#include <viewElements/CustomRectangle.h>
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

    void saveRectangle(std::shared_ptr<CustomRectangle> rect);
    void deleteRect(qreal index);
    //Q_INVOKABLE void updateRect(int index, int newIndex);
    void printRects();

signals:
    void notify();
private:
    QList<std::shared_ptr<CustomRectangle>> rectangles;

};

#endif // RECTANGLEMODEL_H
