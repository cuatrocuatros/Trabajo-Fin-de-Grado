#include "pantalla2.h"
#include "ui_pantalla2.h"
#include "pantalla3.h"


pantalla2::pantalla2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla2),
    mostrarHijo(false)
{
    ui->setupUi(this);
}

pantalla2::~pantalla2()
{
    delete ui;
}


void pantalla2::cerrarHijo()
{
 mostrarHijo= false;
}

void pantalla2::closeEvent(QCloseEvent *)
{
  emit cierrame();
}


void pantalla2::on_pushButton_clicked()
{
    pantalla3 p;
    this->hide();
    QObject::connect(&p,SIGNAL(cierrame()),this,SLOT(cerrarHijo()));
    mostrarHijo = true;
    while (mostrarHijo){
        p.exec();
    }
    if (p.atrasDialogo == 1)
    {
      atrasDialogo=1;
      this->close();
    }
    else
    {
    this->show();
    }

}

void pantalla2::on_pushButton_2_clicked()
{

}

void pantalla2::on_pushButton_3_clicked()
{
    close();
}

void pantalla2::on_pushButton_4_clicked()
{
    atrasDialogo = 1  ;
    close();
}
