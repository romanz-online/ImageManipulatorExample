import QtQuick 2.15

Text {
    text: ""
    color: "white"
    property int imageID;

    function handleImageUpdated() {
        Qt.callLater(function () {
            text = ImageManipulator.getPixelAverage(imageID)
        })
    }

    Component.onCompleted: {
        ImageManipulator.imageUpdated.connect(handleImageUpdated)
    }
}
