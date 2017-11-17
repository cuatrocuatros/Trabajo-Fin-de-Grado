#include "visor.h"
#include <cassert>
#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <dos.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include<vector>
#include "csound.hpp"
#include "globales.h"
#include "primerHilo.h"
#include "segundoHilo.h"
#include <QThread>


using namespace cv;
using namespace std;


visor::visor()
{

}

void visor::start()
{
    char key = ' ';

    //cout << "Hola";  //Esto sale una vez

    //Definimos el primer Object, el primer Thread pertenecientes a MyThread
//    QThread cThread;
//    primerHilo cObject;

//    cObject.DoSetup(cThread);
//    cObject.moveToThread(&cThread);



    //Definimos el primer Object, el primer Thread pertenecientes a mythread2
//    QThread dThread;
//    segundoHilo dObject;

//    dObject.DoSetup(dThread);
//    dObject.moveToThread(&dThread);


    //Definimos el segundo Object, segundo Thread pertenecientes a MyThread
//    QThread dThread;
//    MyThread dObject;

//    dObject.DoSetup(dThread);
//    dObject.moveToThread(&dThread);


    //http://docs.opencv.org/2.4/modules/highgui/doc/user_interface.html?highlight=namedwindow#void%20resizeWindow(const%20string&%20winname,%20int%20width,%20int%20height)

    cv::namedWindow("Current frame",CV_WINDOW_NORMAL);
    cv::resizeWindow("Current frame", 1200,800);
    cv::moveWindow("Current frame",200,20);
    //cv::namedWindow("Diff frame",CV_WINDOW_NORMAL);
    //cv::resizeWindow("Diff frame", 1200,800);
    //cv::moveWindow("Diff frame",200,20);

    do {



        //cout<<chi;


//        if (_wt.haySonido1()==2){

//         cThread.start();
//         cThread.exit();
//        }



//        if (_wt.haySonido2()==true){

//         dThread.start();
//         dThread.exit();
//      // cThread.disconnect();

//        }




        // Muestra la información por pantalla
        cv::imshow("Current frame", _wt.curFrameAux());
        //cv::imshow("Diff frame", _wt.difFrame());


        // Espera hasta que no se apriete una "q"
        key = cvWaitKey(1);


        // Prepara el siguiente fotograma
        _wt.prepareNextFrame();
    } while (key != 'q');
}
