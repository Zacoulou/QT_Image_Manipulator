#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_Image_triggered()
{
    QString searchHeader = "Load Image";
    QString startSearchDir = "/home";
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
    m_img = m_img.convertToFormat(QImage::Format_Grayscale8);
    ui->lbl_Image->setPixmap(QPixmap::fromImage(m_img));
}


void MainWindow::on_actionFlip_Vertical_triggered()
{
    m_img.mirror(true, true);
    ui->lbl_Image->setPixmap(QPixmap::fromImage(m_img));
}

void MainWindow::on_actionProperties_triggered()
{
    unsigned long long pixelSum = 0;

    for (int row = 0; row < m_img.height(); ++row){
        for (int col = 0; col < m_img.width(); ++col){
            pixelSum += qGray(m_img.pixel(col, row));
        }
    }

    int numPixels = (m_img.height() * m_img.width());
    int mean = pixelSum / numPixels;

    QMessageBox::information(this, "Properties",
                             "Width:  " + QString::number(m_img.width()) + "\n" +
                             "Height: " + QString::number(m_img.height()) + "\n" +
                             "Avg Pixel Value: " + QString::number(mean));
}

