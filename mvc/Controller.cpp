#include <mvc/Controller.h>
#include <viewElements/CustomRectangle.h>
#include <QDebug>

Controller::Controller(QObject *parent, Model *_model) : QObject(parent), model(_model)
{
    qDebug() << "Controller initialized!";
}

void Controller::addComponent(qreal x, qreal y, Type type, qreal index){
    std::shared_ptr<CustomRectangle> rectangle;
    switch (type) {
    case Type::POWERPACK:
        rectangle = std::make_shared<CustomRectangle>(
                    QRectF(x, y, 50, 50),            // 50x50
                    QPen(Qt::yellow, 2),             // border color yellow
                    QBrush(QColor(250, 250, 250,0)), // transparent color
                    index,
                    Type::POWERPACK
                    );
        break;
    case Type::MODULE:
        rectangle = std::make_shared<CustomRectangle>(
                    QRectF(x, y, 150, 50),           // 150x50
                    QPen(Qt::blue, 2),               // border color blue
                    QBrush(QColor(250, 250, 250,0)),
                    index,
                    Type::POWERPACK
                    );
        break;
    default:
        qDebug() << "addComponent in Controller issue, wrong Type input!";
        break;
    }

}

