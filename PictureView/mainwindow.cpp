#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imageviwer.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(30, 30, 1000, 600);

    widget_image_viwer = new imageviwer(this);

    widget_image_viwer->loadFile("1.jpg");
    widget_image_viwer->setGeometry(this->width()/4, this->height()/8, this->width()/2, this->height()*2/3);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::resizeEvent(QResizeEvent *)
{
    widget_image_viwer->setGeometry(this->width()/4, this->height()/8, this->width()/2, this->height()*2/3);
}
