#include <cassert>
#include "pantalla1.h"
#include "ui_pantalla1.h"
#include "pantalla2.h"


pantalla1::pantalla1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla1),
    mostrarHijo(false)
{
    ui->setupUi(this);
   //  sHilo = new segundoHilo(this);
   //  sHilo->start();
}

pantalla1::~pantalla1()
{
    delete ui;
}


void pantalla1::cerrarHijo()
{
 mostrarHijo= false;
}

void pantalla1::closeEvent(QCloseEvent *)
{
  emit cierrame();
}

void pantalla1::on_pushButton_clicked(){

      pantalla2 p;
      this->hide();
      QObject::connect(&p,SIGNAL(cierrame()),this,SLOT(cerrarHijo()));
      mostrarHijo = true;
      while (mostrarHijo)
      {
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


void pantalla1::on_pushButton_2_clicked()
{

  close();
}
