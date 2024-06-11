#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>

#include "Model.h"
#include "Controller.h"
#include "View.h"
#include <QString>

// JSON Imports
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include <iostream>
#include <yaml-cpp/yaml.h>

void printNode(const YAML::Node& node, int indent = 0);

void printSequence(const YAML::Node& sequence, int indent = 0) {
    for (std::size_t i = 0; i < sequence.size(); ++i) {
        for (int j = 0; j < indent; ++j) std::cout << "  ";
        std::cout << "- ";
        if (sequence[i].IsScalar()) {
            std::cout << sequence[i].as<std::string>() << std::endl;
        } else if (sequence[i].IsMap()) {
            std::cout << std::endl;
            printNode(sequence[i], indent + 1);
        } else if (sequence[i].IsSequence()) {
            std::cout << std::endl;
            printSequence(sequence[i], indent + 1);
        }
    }
}

void printNode(const YAML::Node& node, int indent) {
    for (YAML::const_iterator it = node.begin(); it != node.end(); ++it) {
        for (int i = 0; i < indent; ++i) std::cout << "  ";
        std::cout << it->first.as<std::string>() << ": ";
        if (it->second.IsScalar()) {
            std::cout << it->second.as<std::string>() << std::endl;
        } else if (it->second.IsMap()) {
            std::cout << std::endl;
            printNode(it->second, indent + 1);
        } else if (it->second.IsSequence()) {
            std::cout << std::endl;
            printSequence(it->second, indent + 1);
        }
    }
}


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;


    Model model;
    Controller controller(nullptr,&model);
    View view(nullptr);

    engine.rootContext()->setContextProperty("controller", &controller);
    engine.rootContext()->setContextProperty("view", &view);

    QObject::connect(&model, &Model::notify,
                     &view, &View::update);

    //JSON Processing logic
    /*

    std::string file_path = "/home/devel/Documents/2xADDs_INL_1HOST.json";


    QJsonObject general;

    if(!controller.readJsonFile(file_path, general)){
        std::cerr << "Failed to read JSON file" << std::endl;
        return 1;
    } else{
        //iterate over the Json root
        QJsonObject tmp = general.value("General").toObject();
        for (auto it = tmp.begin(); it != tmp.end(); ++it) {
            // get each key and print it
            std::cout << "Key: " << it.key().toStdString() << std::endl;

            // get all Hosts
            if ( it.key() == "Host"){
                // get the Host Array
                QJsonArray hosts = tmp.value("Host").toArray();

                // iterate over host Array
                for (const QJsonValue &hostValue : hosts){
                    QJsonObject host = hostValue.toObject();
                    for (auto it = host.begin(); it != host.end(); ++it) {
                        // get each key and print it
                        std::cout << "Key: " << it.key().toStdString() << std::endl;


                        if ( it.key() == "ACM"){
                            // get the Host Array
                            QJsonArray acms = host.value("ACM").toArray();

                            // iterate over acm Array
                            for (const QJsonValue &acmValue : acms){

                                QJsonObject ACM = acmValue.toObject();
                                for (auto it = ACM.begin(); it != ACM.end(); ++it) {
                                    // get each key and print it
                                    std::cout << "Key: " << it.key().toStdString() << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    */


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);




    return app.exec();
}



