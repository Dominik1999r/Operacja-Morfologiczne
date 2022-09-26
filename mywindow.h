#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <iostream>
#include <cmath>

#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QFileDialog>

namespace Ui {
    class MyWindow;
}

enum class TrybMaski
{
    kwadrat, krzyzyk
};

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = 0);

    ~MyWindow();

private:
    Ui::MyWindow *ui;


    QImage *do_wyswietlenia;
    TrybMaski kwadrat_krzyzyk = TrybMaski::krzyzyk;

    int poczX;
    int poczY;

    void czysc();
    void UstawPiksel(QImage* img, int x, int y, QColor kolor);
    void Dylacja(QImage* img);
    void Erozja(QImage* img);

private slots:

    void paintEvent(QPaintEvent*);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_Tryb_maski_editTextChanged(const QString &arg1);
};

#endif // MYWINDOW_H
