import QtQuick 2.15
import QtQuick.Controls 2.15
import CustomComponents 1.0

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
                editorCanvas.addRectangle(100,100,400,100)
            }
        }

        Text {
            text: "Updated Value: " + updatedValue
            font.pixelSize: 20
        }
    }

    CustomPaintedItem {
        id: editorCanvas
        width: 800
        height: 600
        anchors.centerIn: parent
    }
}
