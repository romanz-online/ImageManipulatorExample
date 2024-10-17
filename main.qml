import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt.labs.platform 1.1

ApplicationWindow {
    visible: true
    width: 1080
    height: 720
    title: "Image Manipulator"

    FileDialog {
        id: fileDialog
        title: "Please choose an image file"
        nameFilters: ["Image files (*.png *.jpg *.jpeg)", "All files (*)"]

        onAccepted: {
            if (ImageManipulator.selectFile(fileDialog.file)) {
                fileSelectText.text = fileDialog.file
            } else {
                fileSelectText.text = "Error: Couldn't parse file."
            }
        }
    }

    Button {
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.rightMargin: 10
        anchors.topMargin: 10
        padding: 10
        height: 32
        width: 32
        text: "X"
        onClicked: Qt.quit()
    }

    Row {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 10
        anchors.leftMargin: 10
        spacing: 10

        Button {
            padding: 10
            text: "Select File:"
            onClicked: fileDialog.open()
        }

        Text {
            id: fileSelectText
            anchors.verticalCenter: parent.verticalCenter
            text: "No file selected."
            color: "white"
        }
    }

    Row {
        anchors.centerIn: parent
        anchors.topMargin: 40
        spacing: 20

        ImageDisplay {
            id: originalImage
            imageID: 0
        }

        ImageDisplay {
            id: flippedImage
            imageID: 1
        }

        ImageDisplay {
            id: grayscaleImage
            imageID: 2
        }
    }
}
