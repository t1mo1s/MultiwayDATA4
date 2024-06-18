#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>

#include <mvc/Model.h>
#include <mvc/Controller.h>
#include <viewElements/Canvas.h>
#include <viewElements/RectangleModel.h>
#include <utils/Type.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<Canvas>("CustomComponents", 1, 0, "QPainterCanvas");

    QQmlApplicationEngine engine;

    // rectModel testl
    RectangleModel rectModel(nullptr);

    //Model model;
    Controller controller(nullptr,&rectModel);

    // add the rectangleModel instance to the qml context
    engine.rootContext()->setContextProperty("rectangleModel", &rectModel);
    // add the controller instance to the qml context
    engine.rootContext()->setContextProperty("controller", &controller);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
