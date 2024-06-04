import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 640
    height: 480
    visible: true

    property int updatedValue: 0

    Column {
        anchors.centerIn: parent



        Connections {
            target: view
            function onUpdateView(val){
                updatedValue = val
            }
        }

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

        Text {
            text: "Updated Value: " + updatedValue
            font.pixelSize: 20
        }
    }
}
