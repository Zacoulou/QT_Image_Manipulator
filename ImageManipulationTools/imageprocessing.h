#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <QImage>
#include <string>

namespace ImageProcessing
{
    QImage performProprietaryImageManipulation(QImage img);
    int saveProprietaryImageManipulationToFile(std::string filePath, std::string destDir);
    QImage convertToGrayscale8(QImage img);
    QImage flipVertical(QImage img);
    int calculateAveragePixelValue(QImage img);
}

#endif // IMAGEPROCESSING_H
