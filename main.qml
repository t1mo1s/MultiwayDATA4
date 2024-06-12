import QtQuick 2.15
import QtQuick.Controls 2.15
import CustomComponents 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true

    property int updatedValue: 0

    Row {

        Column {
            width: 200

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

            SpinBox {
                id: yValue
                from: 0
                to: 100
            }

            Button {
                text: "X"
                onClicked: {
                    controller.setValue(ageField.value)
                    editorCanvas.addRectangle((ageField.value),(yValue.value),50,50)
                }
            }


            Text {
                text: "Updated Value: " + updatedValue
                font.pixelSize: 20
            }
        }
        Column {

            CustomPaintedItem {
                id: editorCanvas
                width: 400
                height: 400
            }
        }
    }
}
