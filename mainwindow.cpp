#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "imageprocessing.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuTransform->setEnabled(false);
    ui->menuImage->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_Image_triggered()
{
    QString searchHeader = "Load Image";
    QString startSearchDir = "/";
    QString searchFilter = "Images (*.png *.jpg)";
    QString filePath = QFileDialog::getOpenFileName(this, searchHeader, startSearchDir, searchFilter);

    if (filePath.isEmpty())  {
        return;
    }

    QImage loadedImg(filePath);
    m_img = loadedImg;
    ui->lbl_Image->setScaledContents(true);
    ui->lbl_Image->setPixmap(QPixmap::fromImage(m_img));

    ui->menuTransform->setEnabled(true);
    ui->menuImage->setEnabled(true);
}

void MainWindow::on_actionGrayscale_triggered()
{
    m_img = ImageProcessing::convertToGrayscale8(m_img);
    ui->lbl_Image->setPixmap(QPixmap::fromImage(m_img));
}

void MainWindow::on_actionFlip_Vertical_triggered()
{
    m_img = ImageProcessing::flipVertical(m_img);
    ui->lbl_Image->setPixmap(QPixmap::fromImage(m_img));
}

void MainWindow::on_actionProperties_triggered()
{
    int avgPixelVal = ImageProcessing::calculateAveragePixelValue(m_img);

    QMessageBox::information(this, "Properties",
                             "Width:  " + QString::number(m_img.width()) + "\n" +
                             "Height: " + QString::number(m_img.height()) + "\n" +
                             "Avg Pixel Value: " + QString::number(avgPixelVal));
}

