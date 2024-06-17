#ifndef MODULELIST_H
#define MODULELIST_H

#include <QQuickItem>
#include "Module.h"

class ModuleList : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Module> modules READ modules //NOTIFY moduleChanged
               )
    QML_ELEMENT

public:
    ModuleList();
    QQmlListProperty<Module> modules();

    static void append_module(QQmlListProperty<Module> *list, Module *module);
    static int module_count(QQmlListProperty<Module> *list);
    static Module* module_at(QQmlListProperty<Module> *list, int index);
    static void clear_modules(QQmlListProperty<Module> *list);

private:

    QString m_name;
    QList<Module *> m_modules;

signals:

};

#endif // MODULELIST_H
