#include "Controller.h"
#include <iostream>

// JSON Imports
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

Controller::Controller(QObject *parent, Model *_model) : QObject(parent), model(_model)
{
    std::cout << "Controller initialized!" << std::endl;
}

Controller::~Controller(){
    std::cout << "Controller object destroyed!" << std::endl;
}


void Controller::setValue(int value){
    std::cout << "Controller::setValue() with value " << value <<  "called!" << std::endl;
    model->saveValue(value);
}

//function for reading JSON and convert it to a QJsonObject
bool Controller::readJsonFile(std::string file_path, QJsonObject& result){
    // step 1
        QFile file_obj(QString::fromStdString(file_path));
        if (!file_obj.open(QIODevice::ReadOnly)) {
            std::cout << "Failed to open " << file_path << std::endl;
            exit(1);
        }

        // step 2
        QTextStream file_text(&file_obj);
        QString json_string;
        json_string = file_text.readAll();
        file_obj.close();
        QByteArray json_bytes = json_string.toLocal8Bit();

        // step 3
        auto json_doc = QJsonDocument::fromJson(json_bytes);

        if (json_doc.isNull()) {
            std::cout << "Failed to create JSON doc." << std::endl;
            return false;
        }
        if (!json_doc.isObject()) {
            std::cout << "JSON is not an object." << std::endl;
            return false;
        }

        QJsonObject json_obj = json_doc.object();

        if (json_obj.isEmpty()) {
            std::cout << "JSON object is empty." << std::endl;
            return false;
        }

        // step 4
        result = json_obj;
        return true;
}
