#include <pybind11/pybind11.h>
#include "imageprocessing.h"

namespace py = pybind11;

namespace ImageProcessing
{
    QImage convertToGrayscale8(QImage img){
        return img.convertToFormat(QImage::Format_Grayscale8);
    }

    QImage flipVertical(QImage img){
        return img.mirrored(true, true);
    }

    int calculateAveragePixelValue(QImage img){
        unsigned long long pixelSum = 0;

        for (int row = 0; row < img.height(); ++row){
            for (int col = 0; col < img.width(); ++col){
                //Obtain the gray channel of qRGB. This is safe to call even if image is not grayscale
                pixelSum += qGray(img.pixel(col, row));
            }
        }

        int numPixels = (img.height() * img.width());
        int average = pixelSum / numPixels;

        return average;
    }

    QImage performProprietaryImageManipulation(QImage img){
        img = convertToGrayscale8(img);
        img = flipVertical(img);
        return img;
    }

    //Takes in file and performs ProprietaryImageManipulation, then saves to desired destination
    //Returns -1 if process fails to load or save file
    int saveProprietaryImageManipulationToFile(std::string filePath, std::string destDir){
        QImage loadedImg(QString::fromStdString(filePath));

        if (loadedImg.isNull()){ return -1; }

        loadedImg = performProprietaryImageManipulation(loadedImg);

        bool savedSuccessfully = loadedImg.save(QString::fromStdString(destDir));

        if (!savedSuccessfully){ return -1; }

        return calculateAveragePixelValue(loadedImg);
    }


    PYBIND11_MODULE(image_processing_py, m){
        m.def("saveProprietaryImageManipulationToFile", &saveProprietaryImageManipulationToFile);
    }
}
