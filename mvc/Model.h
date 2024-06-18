#ifndef MODEL_H
#define MODEL_H

#include <QObject>


class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);
    void saveValue(int val);
    int m_value;

signals:
    void notify(int val);

private:

};

#endif // MODEL_H
