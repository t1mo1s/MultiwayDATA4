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

void RectangleModel::addRectangle(qreal x, qreal y, qreal width, qreal height, qreal indx) {
    beginInsertRows(QModelIndex(), rectangles.size(), rectangles.size());
    std::shared_ptr<CustomRectangle> rect = std::make_shared<CustomRectangle>(
                QRectF(x, y, width, height),
                QPen(Qt::blue, 2),
                QBrush(QColor(250, 250, 250,0)),
                indx);
    std::cout << "added Rectangle to the model with x: "<<x<<" , y= "<<y<<"\n";
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
