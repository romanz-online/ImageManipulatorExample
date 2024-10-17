import QtQuick 2.15

Column {
    spacing: 10
    width: 200
    property int imageID;

    Image {
        id: imageElement
        width: 200
        height: 200
        source: ""
        fillMode: Image.PreserveAspectFit
        cache: false
    }

    Row {
        id: avgPixelElement
        visible: false
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: avgPixelTextElement
            text: ""
            color: "white"
        }

        Rectangle {
            id: avgPixelColorElement
            width: 20
            height: 20
            color: "white"
        }
    }

    function handleImageUpdated() {
        Qt.callLater(function () {
            imageElement.source = ""
            imageElement.source = "image://editedImages/" + imageID
        })
    }

    function handleAvgPixelUpdated(type, rgb) {
        Qt.callLater(function () {
            if (imageID !== type) {
                return
            }

            avgPixelTextElement.text = rgb

            let rgbValues = rgb.match(/\d+/g)
            avgPixelColorElement.color = Qt.rgba(rgbValues[0] / 255, rgbValues[1] / 255, rgbValues[2] / 255, 1)

            avgPixelElement.visible = true
        })
    }

    Component.onCompleted: {
        ImageManipulator.imageUpdated.connect(handleImageUpdated)
        ImageManipulator.avgPixelUpdated.connect(handleAvgPixelUpdated)
    }
}
