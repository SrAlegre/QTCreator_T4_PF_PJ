#include "sobre.h"
#include "ui_sobre.h"

Sobre::Sobre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sobre)
{
    ui->setupUi(this);
    QPixmap pix("D:/Biblioteca/Documents/QT Creator/T4_1/foto.jpeg");
    int w=ui->label_picture->width();
    int h=ui->label_picture->height();
    ui->label_picture->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_picture->setVisible(true);
}

Sobre::~Sobre()
{
    delete ui;
}
