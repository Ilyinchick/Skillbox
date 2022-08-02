import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: main
    width: 640
    height: 480
    visible: true
    title: "Title"

    Rectangle {
        id: scene
        anchors.fill: parent
        state: "LeftState"

        Rectangle {
            id: leftRectangle
            x: 100
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 5
            radius: 10
            Text {
                id: leftText
                anchors.centerIn: parent
                text: "move"
                font.pointSize: 12
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    ball.x += 30
                    scene.state = "TempState"
                    if (ball.x >= rightRectangle.x) {
                        scene.state = "LeftState"
                    }
                }
        }
        }

        Rectangle {
            id: rightRectangle
            x: 300
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 5
            radius: 10
            Text {
                id: rightText
                anchors.centerIn: parent
                text: "return"
                font.pointSize: 12
            }
            MouseArea {
                anchors.fill: parent
                onClicked: scene.state = "LeftState"
            }
        }

        Rectangle {
            id: ball
            color: "blue"
            x: leftRectangle.x + 5
            y: leftRectangle.y + 5
            width: leftRectangle.width - 10
            height: leftRectangle.width - 10
            radius: width/2;
        }

        states: [
            State {
                name: "TempState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
        },
            State {
                name: "LeftState"
                PropertyChanges {
                    target: ball
                    x: leftRectangle.x + 5
                }
            }

        ]

        transitions: [
            Transition {
                from: "TempState"
                to: "LeftState"
                NumberAnimation {
                    properties: "x, y"
                    duration: 500
                    easing.type: Easing.OutBounce
                }
            }

        ]
    }
}
