#include "mywindow.h"

#include "ui_mywindow.h"

MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    ui->setupUi(this);

    int szer = ui->rysujFrame->width();
    int wys = ui->rysujFrame->height();
    poczX = ui->rysujFrame->x();
    poczY = ui->rysujFrame->y();

    do_wyswietlenia = new QImage(szer,wys,QImage::Format_RGB32);

    czysc();
}

MyWindow::~MyWindow()
{
    delete ui;
}

void MyWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);

    p.drawImage(poczX,poczY,*do_wyswietlenia);
}

void MyWindow::czysc()
{
    unsigned char *ptr;
    ptr = do_wyswietlenia->bits();
    int szer = do_wyswietlenia->width();
    int wys = do_wyswietlenia->height();
    int i,j;

    for(i=0; i<wys; i++)
    {
        for(j=0; j<szer; j++)
        {
            ptr[szer*4*i + 4*j]=255;
            ptr[szer*4*i + 4*j + 1] = 255;
            ptr[szer*4*i + 4*j + 2] = 255;
        }
    }
}

void MyWindow::Dylacja(QImage *img)
{
    int szer = img->width();
    int wys = img->height();
    QColor bialy;
    bialy.setRgb(255,255,255);
    QColor czarny;
    czarny.setRgb(0,0,0);
    QImage* bufor = new QImage(szer,wys,QImage::Format_RGB32);
    bool nie_bialy = false;

    for(int y = 0; y < wys; y++)
    {
        for(int x = 0; x < szer; x++)
        {
            nie_bialy = false;
            int r,g,b;

            if(kwadrat_krzyzyk == TrybMaski::kwadrat)
            {
               if(x-1 > 0 && x-1 < szer && y > 0 && y < wys)
               {
                       unsigned char *ptr = img -> bits();
                       r = ptr[szer*4*y + 4*(x-1) +2];
                       g = ptr[szer*4*y + 4*(x-1) +1];
                       b = ptr[szer*4*y + 4*(x-1)];

                       if(r != 255 || g !=255 || b != 255)
                       {
                          nie_bialy = true;
                       }
               }
               if(x > 0 && x < szer && y-1 > 0 && y-1 < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*(y-1) + 4*x +2];
                   g = ptr[szer*4*(y-1) + 4*x +1];
                   b = ptr[szer*4*(y-1) + 4*x];

                   if(r != 255 || g !=255 || b != 255)
                   {
                      nie_bialy = true;
                   }
               }
               if(x+1 > 0 && x+1 < szer && y > 0 && y < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*y + 4*(x+1) +2];
                   g = ptr[szer*4*y + 4*(x+1) +1];
                   b = ptr[szer*4*y + 4*(x+1)];

                   if(r != 255 || g !=255 || b != 255)
                   {
                      nie_bialy = true;
                   }
               }
               if(x > 0 && x < szer && y+1 > 0 && y+1 < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*(y+1) + 4*x +2];
                   g = ptr[szer*4*(y+1) + 4*x +1];
                   b = ptr[szer*4*(y+1) + 4*x];

                   if(r != 255 || g !=255 || b != 255)
                   {
                      nie_bialy = true;
                   }
               }
               if(x-1 > 0 && x-1 < szer && y-1 > 0 && y-1 < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*(y-1) + 4*(x-1) +2];
                   g = ptr[szer*4*(y-1) + 4*(x-1) +1];
                   b = ptr[szer*4*(y-1) + 4*(x-1)];

                   if(r != 255 || g !=255 || b != 255)
                   {
                      nie_bialy = true;
                   }
               }

               if(x+1 > 0 && x+1 < szer && y+1 > 0 && y+1 < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*(y+1) + 4*(x+1) +2];
                   g = ptr[szer*4*(y+1) + 4*(x+1) +1];
                   b = ptr[szer*4*(y+1) + 4*(x+1)];

                   if(r != 255 || g !=255 || b != 255)
                   {
                      nie_bialy = true;
                   }
               }
               if(x+1 > 0 && x+1 < szer && y-1 > 0 && y-1 < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*(y-1) + 4*(x+1) +2];
                   g = ptr[szer*4*(y-1) + 4*(x+1) +1];
                   b = ptr[szer*4*(y-1) + 4*(x+1)];

                   if(r != 255 || g !=255 || b != 255)
                   {
                      nie_bialy = true;
                   }
               }
               if(x-1 > 0 && x-1 < szer && y+1 > 0 && y+1 < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*(y+1) + 4*(x-1) +2];
                   g = ptr[szer*4*(y+1) + 4*(x-1) +1];
                   b = ptr[szer*4*(y+1) + 4*(x-1)];

                   if(r != 255 || g !=255 || b != 255)
                   {
                      nie_bialy = true;
                   }
               }

              if(!nie_bialy)
              {
                 UstawPiksel(bufor, x, y, bialy);
              }
              else
              {
                 UstawPiksel(bufor, x, y, czarny);
              }
            }

            if(kwadrat_krzyzyk == TrybMaski::krzyzyk)
            {
                if(x-1 > 0 && x-1 < szer && y > 0 && y < wys)
                {
                        unsigned char *ptr = img -> bits();
                        r = ptr[szer*4*y + 4*(x-1) +2];
                        g = ptr[szer*4*y + 4*(x-1) +1];
                        b = ptr[szer*4*y + 4*(x-1)];

                        if(r != 255 || g !=255 || b != 255)
                        {
                           nie_bialy = true;
                        }
                }
                if(x > 0 && x < szer && y-1 > 0 && y-1 < wys)
                {
                    unsigned char *ptr = img -> bits();
                    r = ptr[szer*4*(y-1) + 4*x +2];
                    g = ptr[szer*4*(y-1) + 4*x +1];
                    b = ptr[szer*4*(y-1) + 4*x];

                    if(r != 255 || g !=255 || b != 255)
                    {
                       nie_bialy = true;
                    }
                }
                if(x+1 > 0 && x+1 < szer && y > 0 && y < wys)
                {
                    unsigned char *ptr = img -> bits();
                    r = ptr[szer*4*y + 4*(x+1) +2];
                    g = ptr[szer*4*y + 4*(x+1) +1];
                    b = ptr[szer*4*y + 4*(x+1)];

                    if(r != 255 || g !=255 || b != 255)
                    {
                       nie_bialy = true;
                    }
                }
                if(x > 0 && x < szer && y+1 > 0 && y+1 < wys)
                {
                    unsigned char *ptr = img -> bits();
                    r = ptr[szer*4*(y+1) + 4*x +2];
                    g = ptr[szer*4*(y+1) + 4*x +1];
                    b = ptr[szer*4*(y+1) + 4*x];

                    if(r != 255 || g !=255 || b != 255)
                    {
                       nie_bialy = true;
                    }
                }

            if(!nie_bialy)
                UstawPiksel(bufor, x, y, bialy);
            else
                UstawPiksel(bufor, x, y, czarny);
        }
    }
    }

    unsigned char *zapis;
    unsigned char *odczyt;
    zapis = bufor->bits();
    odczyt = img->bits();

    for(int y = 0; y < wys; y++)
    {
        for(int x = 0; x < szer; x++)
        {
            odczyt[szer*4*y + 4*x] = zapis[szer*4*y + 4*x]; // Skladowa BLUE
            odczyt[szer*4*y + 4*x + 1] = zapis[szer*4*y + 4*x + 1]; // Skladowa GREEN
            odczyt[szer*4*y + 4*x + 2] = zapis[szer*4*y + 4*x + 2]; // Skladowa RED
        }
    }
}


void MyWindow::Erozja(QImage *img)
{
    int szer = img->width();
    int wys = img->height();
    QImage* temp = new QImage(szer,wys,QImage::Format_RGB32);

     QColor bialy;
     bialy.setRgb(255,255,255);

    bool czy_bialy = false;


    for(int y = 0; y < wys; y++)
    {
        for(int x = 0; x < szer; x++)
        {
            czy_bialy = false;

            int r,g,b;

            if(kwadrat_krzyzyk == TrybMaski::kwadrat)
            {
               if(x-1 > 0 && x-1 < szer && y > 0 && y < wys)
               {
                       unsigned char *ptr = img -> bits();
                       r = ptr[szer*4*y + 4*(x-1) +2];
                       g = ptr[szer*4*y + 4*(x-1) +1];
                       b = ptr[szer*4*y + 4*(x-1)];

                       if(r == 255 && g ==255 && b == 255)
                       {
                          czy_bialy = true;
                       }
               }
               if(x > 0 && x < szer && y-1 > 0 && y-1 < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*(y-1) + 4*x +2];
                   g = ptr[szer*4*(y-1) + 4*x +1];
                   b = ptr[szer*4*(y-1) + 4*x];

                   if(r == 255 && g ==255 && b == 255)
                   {
                      czy_bialy = true;
                   }
               }
               if(x+1 > 0 && x+1 < szer && y > 0 && y < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*y + 4*(x+1) +2];
                   g = ptr[szer*4*y + 4*(x+1) +1];
                   b = ptr[szer*4*y + 4*(x+1)];

                   if(r == 255 && g ==255 && b == 255)
                   {
                      czy_bialy = true;
                   }
               }
               if(x > 0 && x < szer && y+1 > 0 && y+1 < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*(y+1) + 4*x +2];
                   g = ptr[szer*4*(y+1) + 4*x +1];
                   b = ptr[szer*4*(y+1) + 4*x];

                   if(r == 255 && g ==255 && b == 255)
                   {
                      czy_bialy = true;
                   }
               }
               if(x-1 > 0 && x-1 < szer && y-1 > 0 && y-1 < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*(y-1) + 4*(x-1) +2];
                   g = ptr[szer*4*(y-1) + 4*(x-1) +1];
                   b = ptr[szer*4*(y-1) + 4*(x-1)];

                   if(r == 255 && g ==255 && b == 255)
                   {
                      czy_bialy = true;
                   }
               }
               if(x+1 > 0 && x+1 < szer && y+1 > 0 && y+1 < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*(y+1) + 4*(x+1) +2];
                   g = ptr[szer*4*(y+1) + 4*(x+1) +1];
                   b = ptr[szer*4*(y+1) + 4*(x+1)];

                   if(r == 255 && g ==255 && b == 255)
                   {
                      czy_bialy = true;
                   }
               }
               if(x+1 > 0 && x+1 < szer && y-1 > 0 && y-1 < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*(y-1) + 4*(x+1) +2];
                   g = ptr[szer*4*(y-1) + 4*(x+1) +1];
                   b = ptr[szer*4*(y-1) + 4*(x+1)];

                   if(r == 255 && g ==255 && b == 255)
                   {
                      czy_bialy = true;
                   }
               }
               if(x-1 > 0 && x-1 < szer && y+1 > 0 && y+1 < wys)
               {
                   unsigned char *ptr = img -> bits();
                   r = ptr[szer*4*(y+1) + 4*(x-1) +2];
                   g = ptr[szer*4*(y+1) + 4*(x-1) +1];
                   b = ptr[szer*4*(y+1) + 4*(x-1)];

                   if(r == 255 && g ==255 && b == 255)
                   {
                      czy_bialy= true;
                   }
               }

               if(czy_bialy)
               {
                  UstawPiksel(temp, x,y,bialy);
               }
            }

            if(kwadrat_krzyzyk == TrybMaski::krzyzyk)
            {
                if(x-1 > 0 && x-1 < szer && y > 0 && y < wys)
                {
                        unsigned char *ptr = img -> bits();
                        r = ptr[szer*4*y + 4*(x-1) +2];
                        g = ptr[szer*4*y + 4*(x-1) +1];
                        b = ptr[szer*4*y + 4*(x-1)];

                        if(r == 255 && g ==255 && b == 255)
                        {
                           czy_bialy = true;
                        }
                }
                if(x > 0 && x < szer && y-1 > 0 && y-1 < wys)
                {
                    unsigned char *ptr = img -> bits();
                    r = ptr[szer*4*(y-1) + 4*x +2];
                    g = ptr[szer*4*(y-1) + 4*x +1];
                    b = ptr[szer*4*(y-1) + 4*x];

                    if(r == 255 && g ==255 && b == 255)
                    {
                       czy_bialy = true;
                    }
                }
                if(x+1 > 0 && x+1 < szer && y > 0 && y < wys)
                {
                    unsigned char *ptr = img -> bits();
                    r = ptr[szer*4*y + 4*(x+1) +2];
                    g = ptr[szer*4*y + 4*(x+1) +1];
                    b = ptr[szer*4*y + 4*(x+1)];

                    if(r == 255 && g ==255 && b == 255)
                    {
                       czy_bialy = true;
                    }
                }
                if(x > 0 && x < szer && y+1 > 0 && y+1 < wys)
                {
                    unsigned char *ptr = img -> bits();
                    r = ptr[szer*4*(y+1) + 4*x +2];
                    g = ptr[szer*4*(y+1) + 4*x +1];
                    b = ptr[szer*4*(y+1) + 4*x];

                    if(r == 255 && g ==255 && b == 255)
                    {
                       czy_bialy = true;
                    }
                }

            if(czy_bialy)
            {
               UstawPiksel(temp, x,y,bialy);
            }
        }
    }
    }

    unsigned char *zapis;
    unsigned char *odczyt;
    zapis = temp->bits();
    odczyt = img->bits();

    for(int y = 0; y < wys; y++)
    {
        for(int x = 0; x < szer; x++)
        {
            odczyt[szer*4*y + 4*x] = zapis[szer*4*y + 4*x]; // Skladowa BLUE
            odczyt[szer*4*y + 4*x + 1] = zapis[szer*4*y + 4*x + 1]; // Skladowa GREEN
            odczyt[szer*4*y + 4*x + 2] = zapis[szer*4*y + 4*x + 2]; // Skladowa RED
        }
    }
}


void MyWindow::UstawPiksel(QImage* img, int x, int y,QColor bialy)
{
    unsigned char *ptr;
    int szer = img->width();
    int wys = img->height();
    if(x >= szer || y >= wys || x < 0 || y < 0)
        return;
    ptr = img->bits();
    ptr[szer*4*y + 4*x] = bialy.blue();
    ptr[szer*4*y + 4*x+1] = bialy.green();
    ptr[szer*4*y + 4*x+2] = bialy.red();
}



void MyWindow::on_pushButton_clicked()
{
    QString obrazek = QFileDialog::getOpenFileName(this, "Otwórz obraz", "../DominikCielicki_operacjeMorfologiczne/obrazy", "Pliki graficzne (*.png *.jpg *.bmp)");
        if (!(obrazek.isNull()))
        {
            QImage* img = new QImage(obrazek);
            QColor bialy;
            bialy.setRgb(255,255,255);
            QColor czarny;
            czarny.setRgb(0,0,0);
            int szer = img->width();
            int wys = img->height();

            int r,g,b;
            for(int y = 0; y < wys; y++)
            {
                for(int x = 0; x < szer; x++)
                {
                    unsigned char *ptr = img->bits();
                    int szer = img->width();
                    int wys = img->height();
                    if(x <= szer || y <= wys || x > 0 || y > 0)

                    b = ptr[szer*4*y + 4*x];
                    g = ptr[szer*4*y + 4*x+1];
                    r = ptr[szer*4*y + 4*x+2];

                    if((b+g+r)/3 <= 128)
                        UstawPiksel(img, x, y, czarny);
                    else
                        UstawPiksel(img, x, y, bialy);
                }
            }
            do_wyswietlenia = img;
        }
}

void MyWindow::on_pushButton_2_clicked()
{
    Dylacja(do_wyswietlenia);
    update();
}

void MyWindow::on_pushButton_3_clicked()
{
    Erozja(do_wyswietlenia);
    update();
}

void MyWindow::on_pushButton_4_clicked()
{
    Erozja(do_wyswietlenia);
    Dylacja(do_wyswietlenia);
    update();
}
void MyWindow::on_pushButton_5_clicked()
{
    Dylacja(do_wyswietlenia);
    Erozja(do_wyswietlenia);
    update();
}

void MyWindow::on_Tryb_maski_editTextChanged(const QString &arg1)
{
    if(arg1 == "krzyzyk")
    {
       kwadrat_krzyzyk = TrybMaski::krzyzyk;
    }
    else if (arg1 == "kwadrat")
    {
        kwadrat_krzyzyk = TrybMaski::kwadrat;
    }
}

void MyWindow::on_pushButton_6_clicked()
{
    czysc();
    update();
}
