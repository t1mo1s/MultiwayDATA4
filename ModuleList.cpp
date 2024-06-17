#include "ModuleList.h"

ModuleList::ModuleList()
{
}

QQmlListProperty<Module> ModuleList::modules() {
    return QQmlListProperty<Module>(this, this,
        &ModuleList::append_module,
        &ModuleList::module_count,
        &ModuleList::module_at,
        &ModuleList::clear_modules);
}

void ModuleList::append_module(QQmlListProperty<Module> *list, Module *module)
{
    ModuleList *moduleList = qobject_cast<ModuleList *>(list->object);
    if (moduleList) {
        module->setParentItem(moduleList);
        moduleList->m_modules.append(module);
    }
}

int ModuleList::module_count(QQmlListProperty<Module> *list) {
    ModuleList *moduleList = qobject_cast<ModuleList *>(list->object);
    if (moduleList) {
        return moduleList->m_modules.count();
    }
    return 0;
}

Module* ModuleList::module_at(QQmlListProperty<Module> *list, int index) {
    ModuleList *moduleList = qobject_cast<ModuleList *>(list->object);
    if (moduleList) {
        return moduleList->m_modules.at(index);
    }
    return nullptr;
}

void ModuleList::clear_modules(QQmlListProperty<Module> *list) {
    ModuleList *moduleList = qobject_cast<ModuleList *>(list->object);
    if (moduleList) {
        moduleList->m_modules.clear();
    }
}



