#ifndef PANTALLA0_H
#define PANTALLA0_H
#include <QDialog>
#include "primerHilo.h"
#include "segundoHilo.h"

namespace Ui {
class pantalla0;
}

class pantalla0 : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla0(QWidget *parent = 0);
    ~pantalla0();

    //Definimos el puntero del hilo musical
     segundoHilo *sHilo;

private slots:
    void cerrarHijo();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::pantalla0 *ui;
    bool mostrarHijo;
};

#endif // PANTALLA0_H
