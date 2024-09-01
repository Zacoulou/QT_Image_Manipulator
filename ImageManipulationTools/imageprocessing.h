#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <QImage>

namespace ImageProcessing
{
    QImage performProprietaryImageManipulation(QImage img);
    QImage convertToGrayscale8(QImage img);
    QImage flipVertical(QImage img);
    int calculateAveragePixelValue(QImage img);
}

#endif // IMAGEPROCESSING_H
