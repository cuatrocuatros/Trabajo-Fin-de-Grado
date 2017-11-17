#include "segundoHilo.h"
#include <QtCore>
#include <stdio.h>
#include "csound.hpp"
#include "csPerfThread.hpp"
#include <iostream>
#include "globales.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <QThread>
#include <vector>
#include <string>


segundoHilo::segundoHilo(QObject *parent)  :
    QThread(parent)
{
   stopNow = false;
}

using namespace std;



//void segundoHilo::DoSetup(QThread &dThread){

//    connect(&dThread,SIGNAL(started()), this,SLOT(DoWork()));

//}



void segundoHilo::  run()          //DoWork()
{

    freq=0.01;
    amp= 0.5;
    Stop=false;

    //Create an instance of Csound
    Csound* csound = new Csound();

    //compile instance of csound.
    csound->Compile(const_cast<char*>("hilomusical.csd"));
    //setup performance thread
    CsoundPerformanceThread* perfThread = new CsoundPerformanceThread(csound);

    //start Csound performance
    perfThread->Play();

    //keep the application running while performance is ongoing and checks for incoming frequencies
    //from the user
    while(perfThread->GetStatus() == 0 && (!Stop))
    {
//        cout << "Enter an amplitude value and press enter (enter a negative value to quit):";
//        cin >> amp;
//        cout << "Enter a frequency and press enter (enter a negative value to quit):";
//        cin >> freq;

        //SetChannel() sends values to a channel called "freq" and a channel called "amp". See example7.csd
        //tp see how chnget retrieves these values
        if(freq>=0 && amp >= 0)
            {
            csound->SetChannel("freq", freq);
            csound->SetChannel("amp", amp);


            }
       // else
       // {
          //  cout << "Stopping Csound";
          //

        //}
    }

    if (Stop==true){

     perfThread->Stop();
    //free thread object
    delete perfThread;
    //free Csound object
    delete csound;
    }


}

