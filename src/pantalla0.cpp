#include "pantalla0.h"
#include "ui_pantalla0.h"
#include "globales.h"
#include "visor.h"
#include "pantalla1.h"


pantalla0::pantalla0(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla0),
    mostrarHijo(false)
{
    ui->setupUi(this);

    //Iniciamos hilo musical
    sHilo = new segundoHilo(this);
    //sHilo->start();
}

pantalla0::~pantalla0()
{
    delete ui;
}


void pantalla0::cerrarHijo()
{
  mostrarHijo = false;
}

void pantalla0::on_pushButton_clicked()
{
    pantalla1 p;
    this->hide();
    QObject::connect(&p,SIGNAL(cierrame()),this,SLOT(cerrarHijo()));
    mostrarHijo = true;
    while (mostrarHijo){
        p.exec();
    }
    this->show();
}

void pantalla0::on_pushButton_2_clicked()
{
 hide();
 // Atrapa posibles excepciones de OpenCV que puedan surgir
 try {

     visor tv;
     tv.start();
 } catch (cv::Exception& e) {
     std::cerr << e.what();
 }

}
