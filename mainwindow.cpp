#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "QMessageBox"
#include "QLabel"
#include "QPixmap"
#include "QFileDialog"
#include "QDir"
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QGraphicsPixmapItem"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::showIt()
{
    QLabel *image = new QLabel();
    image->setPixmap(QPixmap("wilk.jpg"));
    image->show();
    update();
}
*/
void MainWindow::on_actionNowy_triggered()
{

}

void MainWindow::on_actionOtw_rz_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open image file",QDir::currentPath());
    if(!fileName.isEmpty())
    {
        QImage image(fileName);
        if(image.isNull())
        {
            QMessageBox::information(this,"Image Viewer","Error Displaying image");
            return;
        }
        QGraphicsScene* scene = new QGraphicsScene();
        QGraphicsView* view = new QGraphicsView(scene);
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        scene->addItem(item);
        view->show();
    }
}
