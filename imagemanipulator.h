#ifndef IMAGEMANIPULATOR_H
#define IMAGEMANIPULATOR_H

#include <QObject>
#include <QUrl>
#include <QImage>

class ImageManipulator : public QObject
{
    Q_OBJECT
public:
    enum ImageType {
        Original,
        VerticalFlip,
        Grayscale
    };
    Q_ENUM(ImageType)

    ImageManipulator() {};

    Q_INVOKABLE bool selectFile(QUrl url);

    QImage getImage(ImageType type);

signals:
    void imageUpdated();
    void avgPixelUpdated(ImageType type, const QString& rgb);

private:
    QImage m_image;

    QImage grayscale(QImage src);
    QImage verticalFlip(QImage src);
    QString getAvgPixel(QImage img);
};

#endif // IMAGEMANIPULATOR_H
