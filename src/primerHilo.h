#ifndef PRIMERHILO_H
#define PRIMERHILO_H

#include <QThread>
#include "csound.hpp"
#include "globales.h"
#include <string.h>
#include <QString>

using namespace std;

class primerHilo : public QThread
{
   Q_OBJECT

public:
    explicit primerHilo(QObject *parent = 0);
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

#endif // PRIMERHILO_H
