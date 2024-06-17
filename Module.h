#ifndef MODULE_H
#define MODULE_H

#include <QQuickPaintedItem>

class Module : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName //NOTIFY nameChanged
               )
    QML_ELEMENT

public:
    Module();

    QString name() const;
    void setName(const QString &name);


    void paint(QPainter *painter);


private:
    QString m_name;
};

#endif // MODULE_H
