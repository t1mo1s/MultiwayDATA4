#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>

#include "Model.h"
#include "Controller.h"
#include "Canvas.h"
#include "ModuleList.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<Canvas>("CustomComponents", 1, 0, "QPainterCanvas");
    qmlRegisterType<ModuleList>("CustomComponents", 1, 0, "ModuleList");
    qmlRegisterType<Module>("CustomComponents", 1, 0, "Module");

    QQmlApplicationEngine engine;

    Model model;
    Controller controller(nullptr,&model);

    engine.rootContext()->setContextProperty("controller", &controller);
    engine.rootContext()->setContextProperty("model", &model);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
