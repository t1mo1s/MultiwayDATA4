#include "Model.h"
#include <iostream>
#include <QDebug>


Model::Model(QObject *parent) : QObject(parent)
{
    m_value = 0;
    std::cout << "Model initialized!" << " m_value = " << m_value << std::endl;
}

void Model::saveValue(int val){
    std::cout << "Mode::saveValue(), next setting m_value to the val"<<". Current m_value= "<< m_value << std::endl;
    m_value = val;
    std::cout << "Model::saveValue() m_value = " << m_value << std::endl;
    emit notify(val);
}


