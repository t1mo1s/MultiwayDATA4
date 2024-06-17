#include "RectangleModel.h"

RectangleModel::RectangleModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

int RectangleModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return rectangles.size();
}

void RectangleModel::addRectangle(qreal x, qreal y, qreal width, qreal height) {
    beginInsertRows(QModelIndex(), rectangles.size(), rectangles.size());
    std::shared_ptr<CustomRectangle> rect = std::make_shared<CustomRectangle>(
                QRectF(x, y, width, height),
                QPen(Qt::blue, 2),
                QBrush(QColor(250, 250, 250,0)));
    rectangles.append(rect);
    endInsertRows();
}

void RectangleModel::removeRect(int index) {
    if (index < 0 || index >= rectangles.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    rectangles.removeAt(index);
    endRemoveRows();
}

void RectangleModel::updateRect(int index, int newIndex) {
    if (index < 0 || index >= rectangles.size())
        return;

    rectangles[index]->setIndex(newIndex);
    emit dataChanged(this->index(index), this->index(index), {IndexRole});
}
