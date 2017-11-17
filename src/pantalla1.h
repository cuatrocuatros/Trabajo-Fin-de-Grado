#ifndef PANTALLA1_H
#define PANTALLA1_H
#include <QDialog>
#include "primerHilo.h"
#include "segundoHilo.h"

namespace Ui {
class pantalla1;
}

class pantalla1 : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla1(QWidget *parent = 0);
    ~pantalla1();

    //Definimos hilo musical
    // segundoHilo *sHilo;

    int atrasDialogo;

private slots:
    void cerrarHijo();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

protected:
    void closeEvent(QCloseEvent *);

signals:
    void cierrame();

private:
    Ui::pantalla1 *ui;
    bool mostrarHijo;
};

#endif // PANTALLA1_H
