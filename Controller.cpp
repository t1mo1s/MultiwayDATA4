#include "Controller.h"
#include <iostream>

Controller::Controller(QObject *parent, Model *_model) : QObject(parent), model(_model)
{
    std::cout << "Controller initialized!" << std::endl;
}


void Controller::setValue(int value){
    std::cout << "Controller::setValue() with value " << value <<  "called!" << std::endl;
    model->saveValue(value);
}
