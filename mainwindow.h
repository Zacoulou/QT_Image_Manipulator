#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionLoad_Image_triggered();

    void on_actionGrayscale_triggered();

    void on_actionFlip_Vertical_triggered();

    void on_actionProperties_triggered();

private:
    Ui::MainWindow *ui;
    QImage m_img;
};
#endif // MAINWINDOW_H
