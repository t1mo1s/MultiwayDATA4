#ifndef MODEL_H
#define MODEL_H

#include <QObject>


class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);
private:

};

#endif // MODEL_H
