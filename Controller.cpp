#include "Controller.h"

Controller::Controller(Model *_model) : model{_model}
{

}


void Controller::setValue(int value){
    model->saveValue(value);
}
