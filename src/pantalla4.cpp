#include "pantalla4.h"
#include "ui_pantalla4.h"
#include "csound.hpp"
#include "globales.h"


pantalla4::pantalla4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla4),
    mostrarHijo(false)
{
    ui->setupUi(this);

    tHilo = new tercerHilo(this);

    stopNow = false;
    f= 47;
    a = 1;
    mF = 100;
    MF = 4000;
    R = 1;
}

pantalla4::~pantalla4()
{
    delete ui;
}

void pantalla4::cerrarHijo()
{
 mostrarHijo= false;
}

void pantalla4::closeEvent(QCloseEvent *)
{
  emit cierrame();
}


void pantalla4::on_pushButton_clicked()
{

tHilo->start();

}

void pantalla4::on_pushButton_2_clicked()
{
tHilo->Stop = true;
}

void pantalla4::on_horizontalSlider_valueChanged(int value)
{

 freq=value*0.00001;
 ui->label_11->setNum(freq);

}

void pantalla4::on_horizontalSlider_2_valueChanged(int value)
{

 amp=value*0.001;

}

void pantalla4::on_pushButton_3_clicked()
{
    close();
}

void pantalla4::on_pushButton_4_clicked()
{
    atrasDialogo = 1  ;
    close();
}

void pantalla4::on_pushButton_6_clicked()
{
    close();
}
