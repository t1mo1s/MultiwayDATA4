#include "View.h"
#include <iostream>


View::View(QObject *parent, Model *_model) : QObject{parent},model(_model)
{

}


void View::update(){
    std::cout << "update called" << std::endl;
}
