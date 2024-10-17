#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QImage>

#include "imagemanipulator.h"

class ImageProvider : public QQuickImageProvider
{
public:
    ImageProvider(ImageManipulator* selector);

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;

private:
    ImageManipulator* m_selector;
};

#endif // IMAGEPROVIDER_H
