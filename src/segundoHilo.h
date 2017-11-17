#ifndef SEGUNDOHILO_H
#define SEGUNDOHILO_H

#include <QThread>
#include "csound.hpp"
#include "globales.h"

class segundoHilo : public QThread
{
   Q_OBJECT

public:
    explicit segundoHilo (QObject *parent = 0);
    //void DoSetup(QThread &dThread);
    void run();
    bool Stop;

signals:

public slots:

//void DoWork();

private:
    bool stopNow;
};

#endif // SEGUNDOHILO_H
