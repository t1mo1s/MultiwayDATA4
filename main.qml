import QtQuick 2.15
import QtQuick.Controls 2.15
import CustomComponents 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true

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

            Connections {
                target: model
                /*
                function onUpdateView(val){
                    updatedValue = val
                }
                */
            }

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

            // ListView to display the list items
            ListView {
                width: 200
                height: 300
                model: itemListModel

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
                            text: model.name
                        }

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                console.log("Item clicked: " + model.name)
                            }
                        }
                    }
                }

                // Footer for adding new items
                footer: Row {
                    TextField {
                        id: newItemText
                        placeholderText: "Enter new item"
                        width: parent.width * 0.7
                        onAccepted: {
                            if (newItemText.text.trim() !== "") {
                                itemListModel.append({ name: newItemText.text })
                                newItemText.text = ""
                            }
                        }
                    }
                    Button {
                        text: "Add"
                        onClicked: {
                            if (newItemText.text.trim() !== "") {
                                itemListModel.append({ name: newItemText.text })
                                newItemText.text = ""
                            }
                        }
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

                ModuleList {
                    id: m_List
                    anchors.centerIn: parent

                    modules: [
                        Module {
                            name: "testModulEins"
                        },
                        Module {
                            name: "testModulZwei"
                        }
                    ]
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("Canvas clicked at: " + mouse.x + ", " + mouse.y)
                        editorCanvas.checkIntersect(mouse.x, mouse.y)
                        // Access the modules array through the m_List instance
                        for (let i = 0; i < m_List.modules.length; i++) {
                            console.log("Module name:", m_List.modules[i].name);
                        }
                    }
                }
            }
        }
    }
}
