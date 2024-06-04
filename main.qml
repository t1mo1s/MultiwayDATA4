import QtQuick 2.15
import QtQuick.Controls 2.15
import com.example 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true

    Column {
        anchors.centerIn: parent

        Controller {
            id: _controller
        }
l

        SpinBox {
            id: ageField
            from: 0
            to: 100
            onValueChanged: model.age = value
        }

        Button {
            text: "save"
            onClicked: Controller.setValue(7);
        }
    }






}
