#ifndef VISOR_H
#define VISOR_H

#include "capturador.h"
#include <string>
#include <thread>
#include <QObject>
#include <QUrl>
#include "csound.hpp"
#include "primerHilo.h"
#include "segundoHilo.h"
#include <sstream>
#include <string>
#include <iostream>

class visor
{
public:
    visor();

    void start();

    primerHilo *mThread;
    segundoHilo *mThread2;

private:
    capturador _wt;
};

#endif // VISOR_H
