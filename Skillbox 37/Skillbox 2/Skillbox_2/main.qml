import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    width: 500
    height: 250
    visible: true

    Grid {
        columns: 1
        rows: 3
        anchors.horizontalCenter: parent.horizontalCeter
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width

            Image {
                    source: "image"
                    width: parent.width
            }

            ProgressBar {
            width: parent.width
            value: 0.1
            }

            Grid {
            rows: 1
            columns : 5
            width: parent.width

                Button { text: "▶️" }
                Button { text: "⏸️" }
                Button { text: "⏹" }
                Button { text: "⏪️" }
                Button { text: "⏩️" }
        }
    }
}
