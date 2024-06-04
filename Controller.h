#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Model.h"

class Controller : QObject
{
    Q_OBJECT
public:
    Controller(Model *_model);
    Q_INVOKABLE void setValue(int value);

private:
    Model *model;
};

#endif // CONTROLLER_H
