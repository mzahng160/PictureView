#ifndef IMAGEVIWER_H
#define IMAGEVIWER_H

#include <QWidget>
#include <QImage>

class QLabel;

class imageviwer : public QWidget
{
    Q_OBJECT
public:
    explicit imageviwer(QWidget *parent = 0);
    ~imageviwer();

    bool loadFile(const QString& fileName);

protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);

signals:

public slots:
    void on_click_btn_prev();
    void on_click_btn_next();

    void on_click_btn_rotatel();
    void on_click_btn_rotater();

    void on_click_zoom_in();
    void on_click_zoom_out();

private:
    void setImage(const QImage& newImage);

    QImage image;
    QLabel *image_label;
//    QString picName;

    int totate;
//    int scale;
};

#endif // IMAGEVIWER_H
