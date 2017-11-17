#include "pantalla3.h"
#include "ui_pantalla3.h"
#include "pantalla4.h"


pantalla3::pantalla3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla3),
    mostrarHijo(false)
{
    ui->setupUi(this);
}

pantalla3::~pantalla3()
{
    delete ui;
}

void pantalla3::cerrarHijo()
{
 mostrarHijo= false;
}

void pantalla3::closeEvent(QCloseEvent *)
{
  emit cierrame();
}

void pantalla3::on_pushButton_clicked()
{
    pantalla4 p;
    this->hide();
    QObject::connect(&p,SIGNAL(cierrame()),this,SLOT(cerrarHijo()));
    mostrarHijo = true;
    while (mostrarHijo){
        p.exec();
    }

    if (p.atrasDialogo == 1)
    {
      atrasDialogo =1;
      this->close();
    }
    else
    {
    this->show();
    }

}

void pantalla3::on_pushButton_4_clicked()
{
close();
}

void pantalla3::on_pushButton_3_clicked()
{
    atrasDialogo = 1  ;
    close();
}
