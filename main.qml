import QtQuick 2.15
import QtQuick.Controls 2.15
import CustomComponents 1.0

ApplicationWindow {
    width: 680
    height: 500
    visible: true

    property int updatedValue: 0
    property int itemCount: 0

    ListModel {
        id: itemListModel
        ListElement { name: "Item 1" }
        ListElement { name: "Item 2" }
        ListElement { name: "Item 3" }
    }

    Row {
        spacing: 20
        anchors.centerIn: parent

        Column {
            width: 200

            /*
            Connections {
                target: view
                function onUpdateView(val){
                    updatedValue = val
                }
            }
            */

            TextField {
                id: xValue
                width: 150
                placeholderText: "X"
                inputMethodHints: Qt.ImhDigitsOnly // Ensures only numbers can be input
            }

            TextField {
                id: yValue
                width: 150
                placeholderText: "Y"
                inputMethodHints: Qt.ImhDigitsOnly // Ensures only numbers can be input
            }

            Button {
                text: "Create New Item"
                onClicked: {
                    let x = parseInt(xValue.text)
                    let y = parseInt(yValue.text)
                    if (!isNaN(x) && !isNaN(y)) {
                        editorCanvas.addRectangle(x, y, 50, 50)
                    } else {
                        console.log("Invalid input")
                    }
                }
            }

            Text {
                text: "Updated Value: " + updatedValue
                font.pixelSize: 20
            }

            // ListView to display the list items
            ListView {
                width: 200
                height: 300
                model: rectangleModel

                delegate: Item {
                    width: 200
                    height: 50

                    Rectangle {
                        width: parent.width - 20
                        height: parent.height - 20
                        color: "lightgrey"
                        border.color: "black"

                        Text {
                            anchors.centerIn: parent
                            text: model.index
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                console.log("Item clicked: " + model.index)
                            }
                        }
                    }
                }

                // Footer for adding new items
                footer: Row {

                    Button {
                        text: "Add Item"
                        onClicked: controller.addComponent(10,10,++itemCount)
                    }

                    Button {
                        text: "Remove Last Item"
                        onClicked: controller.removeComponent(rectangleModel.rowCount() - 1)
                    }
                }
            }
        }

        Column {
            Rectangle {
                width: 400
                height: 400

                QPainterCanvas {
                    id: editorCanvas
                    width: parent.width
                    height: parent.height
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("Canvas clicked at: " + mouse.x + ", " + mouse.y)
                        editorCanvas.checkIntersect(mouse.x, mouse.y)
                        //editorCanvas.addRectangle(mouse.x, mouse.y, 50, 50)
                    }
                }
            }
        }
    }
}
