#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include "Model.h"

class View : public QObject
{
    Q_OBJECT
public:
    explicit View(QObject *parent = nullptr, Model *_model = nullptr);
    Model *model;

public slots:
    void update();

signals:

private:


};

#endif // VIEW_H
