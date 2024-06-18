#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <viewElements/RectangleModel.h>
#include <utils/Type.h>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr, RectangleModel *_model = nullptr);

    Q_INVOKABLE void addComponent(qreal x, qreal y //, Type type
                                  ,qreal index);
    // TODO : Q_INVOKABLE void addVehicle();
    Q_INVOKABLE void removeComponent(qreal index);

private:
    RectangleModel *model;
};

#endif // CONTROLLER_H
