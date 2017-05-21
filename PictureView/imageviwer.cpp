#include "imageviwer.h"
#include <QLabel>
#include <QImageReader>
#include <QDebug>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>
imageviwer::imageviwer(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *main_layout;

    QHBoxLayout* tool_layout;
    QPushButton* btn_prev;
    QPushButton* btn_next;
    QPushButton* btn_zoom_in;
    QPushButton* btn_zoom_out;
    QPushButton* btn_rotate_rise;
    QPushButton* btn_rotate_fall;

    image_label = new QLabel();
    image_label->setBackgroundRole(QPalette::Base);
    image_label->setSizePolicy(QSizePolicy::Ignored,
                               QSizePolicy::Ignored);
    image_label->setScaledContents(true);

    totate = 0;
//    picName = "";

    main_layout = new QVBoxLayout(this);
    main_layout->addWidget(image_label);


    btn_prev = new QPushButton();
    btn_prev->setIcon(QIcon("arrow_left.png"));

    btn_next = new QPushButton();
    btn_next->setIcon(QIcon("arrow_right.png"));

    btn_rotate_rise = new QPushButton();
    btn_rotate_rise->setIcon(QIcon("button_rotate_cw.png"));

    btn_rotate_fall = new QPushButton();
    btn_rotate_fall->setIcon(QIcon("button_rotate_ccw.png"));

    btn_zoom_in = new QPushButton();
    btn_zoom_in->setIcon(QIcon("zoom_in.png"));

    btn_zoom_out = new QPushButton();
    btn_zoom_out->setIcon(QIcon("zoom_out.png"));

    QSpacerItem* item_left = new QSpacerItem(75, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem* item_right = new QSpacerItem(75, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

    tool_layout = new QHBoxLayout();
    tool_layout->addSpacerItem(item_left);
    tool_layout->addWidget(btn_prev);
    tool_layout->addWidget(btn_next);
    tool_layout->addWidget(btn_rotate_rise);
    tool_layout->addWidget(btn_rotate_fall);
    tool_layout->addWidget(btn_zoom_in);
    tool_layout->addWidget(btn_zoom_out);
    tool_layout->addSpacerItem(item_right);

    main_layout->addLayout(tool_layout);

    this->setLayout(main_layout);
    this->setStyleSheet("background-color: rgb(160, 75, 59);");

    connect(btn_prev, SIGNAL(clicked(bool)), this, SLOT(on_click_btn_prev()));
    connect(btn_next, SIGNAL(clicked(bool)), this, SLOT(on_click_btn_next()));

    connect(btn_rotate_rise, SIGNAL(clicked(bool)), this, SLOT(on_click_btn_rotatel()));
    connect(btn_rotate_fall, SIGNAL(clicked(bool)), this, SLOT(on_click_btn_rotater()));

    connect(btn_zoom_in, SIGNAL(clicked(bool)), this, SLOT(on_click_zoom_in()));
    connect(btn_zoom_out, SIGNAL(clicked(bool)), this, SLOT(on_click_zoom_out()));
}

imageviwer::~imageviwer()
{

}

bool imageviwer::loadFile(const QString& fileName)
{
    QImageReader reader(fileName);
//    picName = fileName;
    reader.setAutoDetectImageFormat(true);
    const QImage newImage = reader.read();

    setImage(newImage);
    //qDebug() << "file name " <<fileName ;

    return true;
}

void imageviwer::setImage(const QImage& newImage)
{
    image = newImage;
    image_label->setPixmap(QPixmap::fromImage(image));
}

void imageviwer::paintEvent(QPaintEvent *)
{

//    if(totate != 0)
//    {
//        QPainter painter(this);
//        QPixmap pix;
//        pix.load(picName);
//        painter.translate(this->x()+this->width()/2,this->y()+this->height()/2); //让图片的中心作为旋转的中心
//        painter.rotate(totate); //顺时针旋转90度
//        painter.translate(-this->x()-this->width()/2,-this->y()-this->height()/2); //使原点复原
//        painter.drawPixmap(this->rect(),pix);

//        qDebug() <<picName << " rotate " << totate;
//    }
//    qDebug() <<picName << " rotate " << totate;

}

void imageviwer::resizeEvent(QResizeEvent *)
{

}
void imageviwer::on_click_btn_prev()
{

}
void imageviwer::on_click_btn_next()
{

}
void imageviwer::on_click_btn_rotatel()
{
    QMatrix leftmatrix;
    totate += 90;
    if(totate >= 360)
        totate = 0;
    leftmatrix.rotate(totate);

    image_label->setPixmap(QPixmap("1.png").transformed(leftmatrix,Qt::SmoothTransformation));
}
void imageviwer::on_click_btn_rotater()
{
    QMatrix leftmatrix;
    totate -= 90;
    if(totate <= 0)
        totate = 270;
    leftmatrix.rotate(totate);

    QImage imgRotate = image.transformed(leftmatrix);
    image_label->setPixmap(QPixmap::fromImage(imgRotate));
}

void imageviwer::on_click_zoom_in()
{
    int scale = 2;

    QImage imgRotate = image.scaled(this->width()*scale ,this->height()* scale, Qt::KeepAspectRatio);
    image_label->setPixmap(QPixmap::fromImage(imgRotate));

    qDebug() << "on_click_zoom_in";
}
void imageviwer::on_click_zoom_out()
{
    int scale = 2;

    QImage imgRotate = image.scaled(this->width()/scale ,this->height()/ scale, Qt::KeepAspectRatio);
    image_label->setPixmap(QPixmap::fromImage(imgRotate));

    qDebug() << "on_click_zoom_out";
}
