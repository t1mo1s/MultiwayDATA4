#ifndef VIEW_H
#define VIEW_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>

#include "Model.h"

class View : public QObject
{
    Q_OBJECT
public:
    explicit View(QObject *parent = nullptr);
    Model *model;

public slots:
    void update(int val);

signals:

private:
    QGuiApplication *app;

};

#endif // VIEW_H
