#ifndef MODEL_H
#define MODEL_H

#include <QObject>


class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);
    int value() const { return m_value;}
    int m_value;
    void printVal();
    void saveValue(int val);

signals:
    void valueChanged(int newValue);
    void notify(int val);

private:

};

#endif // MODEL_H
