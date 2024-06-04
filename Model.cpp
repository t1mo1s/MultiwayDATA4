#include "Model.h"
#include <iostream>


Model::Model(QObject *parent) : QObject(parent), m_value(0)
{

}

void Model::saveValue(int val){
    std::cout << "Model setValue()" << std::endl;
    m_value = val;
    emit notify(val);
}


