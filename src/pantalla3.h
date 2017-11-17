#ifndef PANTALLA3_H
#define PANTALLA3_H

#include <QDialog>

namespace Ui {
class pantalla3;
}

class pantalla3 : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla3(QWidget *parent = 0);
    ~pantalla3();

    int atrasDialogo;

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void cerrarHijo();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

signals:
  void cierrame();

private:
    Ui::pantalla3 *ui;
    bool mostrarHijo;
};

#endif // PANTALLA3_H
