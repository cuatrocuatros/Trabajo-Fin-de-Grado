#ifndef PANTALLA4_H
#define PANTALLA4_H

#include <QDialog>
#include "csound.hpp"
#include "tercerHilo.h"

namespace Ui {
class pantalla4;
}

class pantalla4 : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla4(QWidget *parent = 0);
    ~pantalla4();

    int atrasDialogo;

    tercerHilo *tHilo;

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void cerrarHijo();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

signals:
  void cierrame();

private:
    Ui::pantalla4 *ui;
    bool stopNow;
    int f;
    int a;
    int mF;
    int MF;
    int R;
    bool mostrarHijo;
};

#endif // PANTALLA4_H
