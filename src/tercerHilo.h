#ifndef TERCERHILO_H
#define TERCERHILO_H

#include <QThread>
#include "csound.hpp"
#include "globales.h"
#include <string.h>
#include <QString>

using namespace std;

class tercerHilo : public QThread
{
   Q_OBJECT

public:
    explicit tercerHilo(QObject *parent = 0);
    //void DoSetup(QThread &cThread);
    void run();
    bool Stop;

    double  f;
    double  a;
    double mF;
    double MF;
    double R;

    //Declaramos puntero string para la cancion
    string cancion;



signals:

public slots:

//void DoWork();

private:
    bool stopNow;


};

#endif // TERCERHILO_H
