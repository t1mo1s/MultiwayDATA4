#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <mvc/Model.h>
#include <utils/Type.h>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr, Model *_model = nullptr);

    Q_INVOKABLE void addComponent(qreal x, qreal y, Type type, qreal index);
    // TODO : Q_INVOKABLE void addVehicle();

private:
    Model *model;
};

#endif // CONTROLLER_H
