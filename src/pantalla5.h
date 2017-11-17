#ifndef PANTALLA5_H
#define PANTALLA5_H

#include <QDialog>

namespace Ui {
class pantalla5;
}

class pantalla5 : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla5(QWidget *parent = 0);
    ~pantalla5();

private:
    Ui::pantalla5 *ui;
};

#endif // PANTALLA5_H
