#include "Module.h"

Module::Module()
{

}

QString Module::name() const{
    return m_name;
};

void Module::setName(const QString &name){
    m_name = name;

};

void Module::paint(QPainter *painter){

};
