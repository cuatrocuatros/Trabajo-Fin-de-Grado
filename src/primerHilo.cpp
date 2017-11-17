#include "primerHilo.h"
#include <QtCore>
#include <stdio.h>
#include "csound.hpp"
#include "csPerfThread.hpp"
#include <iostream>
#include "globales.h"
#include <QThread>
#include <QString>


primerHilo::primerHilo(QObject *parent)  :
    QThread(parent)
{
//    f= 47;
//    a = 1;
//    mF = 100;
//    MF = 4000;
//    R = 1;
//    freq=44100;
}

using namespace std;

//void primerHilo::DoSetup(QThread &cThread){

//    connect(&cThread,SIGNAL(started()), this,SLOT(DoWork()));

//}



void primerHilo:: run()       //DoWork()
{


    freq=0.02;
    amp= 0.5;

    Stop=false;

    //Create an instance of Csound
    Csound* csound = new Csound();

    //compile instance of csound.
    csound->Compile(const_cast<char*>("leermp3v1.csd"));
    //setup performance thread
    CsoundPerformanceThread* perfThread = new CsoundPerformanceThread(csound);

    //start Csound performance
    perfThread->Play();

    csound->SetChannel("cancion",const_cast<char*>("tacabro.mp3"));
    //csound->SetChannel("cancion",const_cast<char*>(cancion.c_str()));


    //keep the application running while performance is ongoing and checks for incoming frequencies
    //from the user
    while(perfThread->GetStatus() == 0 && (!Stop))
    {

          //csound->SetChannel("cancion",const_cast<char*>("tacabro.mp3"));
          //csound->SetChannel("freq", freq);

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
        else
        {
            cout << "Stopping Csound";


        }
    }

    if (Stop==true){

     perfThread->Stop();
    //free thread object
    delete perfThread;
    //free Csound object
    delete csound;
    }

}
