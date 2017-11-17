#ifndef PANTALLA2_H
#define PANTALLA2_H

#include <QDialog>


namespace Ui {
class pantalla2;
}

class pantalla2 : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla2(QWidget *parent = 0);
    ~pantalla2();

    int atrasDialogo;

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void cerrarHijo();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

signals:
  void cierrame();

private:
    Ui::pantalla2 *ui;
    bool mostrarHijo;
};

#endif // PANTALLA2_H
