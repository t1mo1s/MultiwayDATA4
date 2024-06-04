#ifndef VIEW_H
#define VIEW_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>


class View : public QObject
{
    Q_OBJECT
public:
    explicit View(QObject *parent = nullptr);

public slots:
    void update(int val);

signals:
    void updateView(int value);

private:
    QGuiApplication *app;

};

#endif // VIEW_H
