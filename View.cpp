#include "View.h"
#include <iostream>


View::View(QObject *parent) : QObject{parent}
{

}


void View::update(int val){
    std::cout << "update called" << std::endl;
    std::cout << val << std::endl;

}
