#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <QImage>

namespace ImageProcessing
{
    QImage convertToGrayscale8(QImage img);
    QImage flipVertical(QImage img);
    int calculateAveragePixelValue(QImage img);
}

#endif // IMAGEPROCESSING_H
