#include "imageprovider.h"

ImageProvider::ImageProvider(ImageManipulator *selector)
    : QQuickImageProvider(QQuickImageProvider::Image)
    , m_selector(selector)
{
}

QImage ImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(requestedSize)

    int type = id.toInt(); // default is 0 which just displays original image
    QImage newImage = m_selector->getImage(ImageManipulator::ImageType(type));

    if (size) {
        *size = newImage.size();
    }

    return newImage;
}
