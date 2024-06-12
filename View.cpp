#include "View.h"
#include <iostream>


View::View(QObject *parent) : QObject{parent}
{
    // Register canvas in qml
    std::cout << "View()" << std::endl;
}


void View::update(int val){
    std::cout << "update called" << std::endl;
    std::cout << val << std::endl;
    emit updateView(val);
}
