#include "pantalla5.h"
#include "ui_pantalla5.h"

pantalla5::pantalla5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla5)
{
    ui->setupUi(this);
}

pantalla5::~pantalla5()
{
    delete ui;
}
