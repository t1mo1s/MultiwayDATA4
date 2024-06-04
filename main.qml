import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 640
    height: 480
    visible: true

    Column {
        anchors.centerIn: parent


        SpinBox {
            id: ageField
            from: 0
            to: 100
        }

        Button {
            text: "save"
            onClicked: {
                controller.setValue(ageField.value)
            }
        }
    }
}
