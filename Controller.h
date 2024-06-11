#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Model.h"
#include <QVariantMap>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr, Model *_model = nullptr);
    ~Controller();

    Q_INVOKABLE void setValue(int value);

    bool readJsonFile(std::string file_path, QJsonObject& result);

private:
    Model *model;
};

#endif // CONTROLLER_H
