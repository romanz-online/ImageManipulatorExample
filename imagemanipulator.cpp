#include "imagemanipulator.h"

#include <QDebug>

bool ImageManipulator::selectFile(QUrl url)
{
    QImage newImage = QImage(url.toLocalFile());

    if (!newImage.isNull()) {
        m_image = newImage;
        emit imageUpdated();
    }

    return !newImage.isNull();
}

QImage ImageManipulator::getImage(ImageType type)
{
    QImage retImage;

    if (!m_image.isNull()) {
        switch (type) {
        case Original:
            retImage = m_image;
            break;
        case VerticalFlip:
            retImage = verticalFlip(m_image);
            break;
        case Grayscale:
            retImage = grayscale(verticalFlip(m_image));
            break;
        default:
            return QImage();
        }

        emit avgPixelUpdated(type, getAvgPixel(retImage));
    }

    return retImage;
}

QString ImageManipulator::getAvgPixel(QImage img)
{
    int rSum = 0, gSum = 0, bSum = 0, pixelCount = 0;

    for (int y = 0; y < img.height(); y++) {
        for (int x = 0; x < img.width(); x++) {
            QColor pixelColor(img.pixel(x, y));
            rSum += pixelColor.red();
            gSum += pixelColor.green();
            bSum += pixelColor.blue();
            pixelCount++;
        }
    }

    pixelCount = pixelCount > 0 ? pixelCount : 1;

    return QString("RGB(%1, %2, %3)")
        .arg(rSum / pixelCount)
        .arg(gSum / pixelCount)
        .arg(bSum / pixelCount);
}

QImage ImageManipulator::grayscale(QImage src) { return src.convertToFormat(QImage::Format_Grayscale8); }

QImage ImageManipulator::verticalFlip(QImage src) { return src.mirrored(false, true); }
