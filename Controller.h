#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Model.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr, Model *_model = nullptr);

    void setValue(int value);

private:
    Model *model;
};

#endif // CONTROLLER_H
