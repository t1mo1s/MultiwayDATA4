#include "RectangleModel.h"
#include <iostream>

RectangleModel::RectangleModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

int RectangleModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return rectangles.size();
}

QVariant RectangleModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= rectangles.size())
        return QVariant();

    const std::shared_ptr<CustomRectangle> rect = rectangles.at(index.row());
    if (role == IndexRole)
        return rect->index();
    // Add other roles handling as needed

    return QVariant();
}


QHash<int, QByteArray> RectangleModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IndexRole] = "index";
    // Add other roles as needed
    return roles;
}

void RectangleModel::saveRectangle(std::shared_ptr<CustomRectangle> rect) {
    beginInsertRows(QModelIndex(), rectangles.size(), rectangles.size());
    std::cout << "added Rectangle to the model"<<"\n"<<std::endl;
    rectangles.append(rect);
    endInsertRows();
    emit notify();
}

void RectangleModel::deleteRect(qreal index) {
    if (index < 0 || index >= rectangles.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    std::cout << " removing rectangle with index: "<<index<<std::endl;
    rectangles.removeAt(index);
    endRemoveRows();
}

/*
void RectangleModel::updateRect(int index, int newIndex) {
    if (index < 0 || index >= rectangles.size())
        return;

    rectangles[index]->setIndex(newIndex);
    emit dataChanged(this->index(index), this->index(index), {IndexRole});
}
*/

void RectangleModel::printRects(){
    //iterate over the QList rectangles and print the entries to the console
    foreach (const std::shared_ptr<CustomRectangle>& rectPtr, rectangles) {
        std::cout << "Rectangle with Index: " <<rectPtr->index()<<"\n"<<std::endl;
    }
}
