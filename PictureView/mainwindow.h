#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class imageviwer;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *);

private:
    Ui::MainWindow *ui;
    imageviwer *widget_image_viwer;

};

#endif // MAINWINDOW_H
