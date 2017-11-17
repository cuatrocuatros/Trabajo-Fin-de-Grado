#include "capturador.h"
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
#include <vector>
#include "csound.hpp"
#include "globales.h"
#include "primerHilo.h"
#include "segundoHilo.h"
#include <QThread>
#include <QFile>
#include <QString>
#include <QDebug>
#include <windows.h>
#include <string.h>
#include <QTextStream>
#include <string>
#include <QDir>

using namespace cv;
using namespace std;


capturador::capturador()
    : _vidCap(0)
{

    pHilo = new primerHilo();
    //sHilo = new segundoHilo();

    _vidCap.set(CV_CAP_PROP_FRAME_WIDTH,1980);
    _vidCap.set(CV_CAP_PROP_FRAME_HEIGHT,1080);
//   _vidCap.set(CV_CAP_PROP_BRIGHTNESS,17);
//   _vidCap.set(CV_CAP_PROP_SATURATION,47);

    _kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size2i(3, 3), cv::Point2i(1, 1));
    assert(_vidCap.isOpened());

    // Cargamos el fotograma inicial
    _vidCap >> fActual;

    //Iniciamos hilo musical
    //pHilo->start();

    //Cargamos el nombre de la aplicación y el logo
    image=imread("C:\\Users\\lagoa\\Documents\\Teleco\\TFG\\logo.png");

    // Volteamos el primer fotograma para que aparezca como un espejo
    cv::flip(fActual,fActual,1);
    prepareNextFrame();
}


capturador::~capturador()
{

}


/** Variables puños y manos */
String fist_cascade_name = "fist.xml";
String palm_cascade_name = "palm.xml";
CascadeClassifier fist_cascade;
CascadeClassifier palm_cascade;



void capturador::Manos(){

    pderecha = false;
    pizquierda=false;

    if( !fist_cascade.load( fist_cascade_name ) ){ printf("--(!)Error loading fist cascade\n");  };
    if( !palm_cascade.load( palm_cascade_name ) ){ printf("--(!)Error loading palm cascade\n");  };

    std::vector<Rect> fists;
    std::vector<Rect> palms;

        Mat frame_gray;

        cvtColor( fActual, frame_gray, COLOR_BGR2GRAY );
        equalizeHist( frame_gray, frame_gray );


        // Se detectan puños
        fist_cascade.detectMultiScale( frame_gray, fists, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(200, 200) );

        for( size_t i = 0; i < fists.size(); i++ )
        {
            Point center( fists[i].x + fists[i].width/2, fists[i].y + fists[i].height/2 );
            ellipse( fActual, center, Size( fists[i].width/2, fists[i].height/2), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

            if ((center.x<413)&(center.y>350)){
               cp=cp+1;
               //cout << "puño en la izquierda";
               cout << cp;

               pizquierda = true;
              }

            if ((center.x > 851)&(center.y>350)){
               cout << "puño en la derecha";
               pderecha = true;
              }
        }


        // Se detectan palmas
        palm_cascade.detectMultiScale( frame_gray, palms, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(200, 200) );

        for( size_t i = 0; i < palms.size(); i++ )
        {
            Point center( palms[i].x + palms[i].width/2, palms[i].y + palms[i].height/2 );
            ellipse( fActual, center, Size( palms[i].width/2, palms[i].height/2), 0, 0, 360, Scalar( 0, 0, 255 ), 4, 8, 0 );



//            if ((center.x<413)&(center.y>350)){
//               cp=cp+1;
//               //cout << "puño en la izquierda";
//               cout << cp;

//               pizquierda = true;
//              }

//                      if ((center.x > 851)&(center.y>350)){
//                         cout << "puño en la derecha";
//                         pderecha = true;
//                        }
        }
    }



void capturador::cargaPerfiles(){

    WIN32_FIND_DATA findFileData;
    HANDLE hfind;

    wchar_t*  dir = L"C:/Users/lagoa/Documents/Teleco/TFG/Versiones/TFG VERSION 3/perfiles/*.txt";

    hfind = FindFirstFile(dir, &findFileData);

    if (hfind == INVALID_HANDLE_VALUE){
        //cout << "No se encuentra ningún perfil";
        dimP=0;
    }
    else
    {
        wstring ws(findFileData.cFileName);
        string str(ws.begin(), ws.end());

        str = str.substr(0, str.size() - 4);

        listaPerfiles[0]=str;
        int i = 0;

        while (FindNextFile(hfind,&findFileData) != 0){

                 wstring ws(findFileData.cFileName);
                 string str(ws.begin(), ws.end());

                    str = str.substr(0, str.size() - 4);

                    i+=1;
                    listaPerfiles[i]=str;
        }
        dimP=i+1;
   }
}



void capturador::cargaCanciones(){

    WIN32_FIND_DATA findFileData;
    HANDLE hfind;

    wchar_t*  dir = L"C:/Users/lagoa/Documents/Teleco/TFG/Versiones/TFG VERSION 3/release/*.mp3";

    hfind = FindFirstFile(dir, &findFileData);

    if (hfind == INVALID_HANDLE_VALUE){
        cout << "No se encuentra ninguna canción";
        dimC=0;
    }
    else
    {
        wstring ws(findFileData.cFileName);
        string str(ws.begin(), ws.end());

        str = str.substr(0, str.size() - 4);

        listaCanciones[0]=str;
        int i = 0;

        while (FindNextFile(hfind,&findFileData) != 0){

                 wstring ws(findFileData.cFileName);
                 string str(ws.begin(), ws.end());

                    str = str.substr(0, str.size() - 4);

                    i+=1;
                    listaCanciones[i]=str;
        }
        dimC=i+1;
   }
}



void capturador::Pantallas(){

    switch (contPant){

    case 1:
    {
        //Qué aparece en la pantalla 1
        // Creamos una Current Frame auxiliar para que los dibujos de botones en la pantalla no interfieran en la Diff Frame, representándola después por pantalla
       fActualAux = fActual.clone();
       double alpha = 0.4;

       cv::circle(fActualAux,Point2f(262,528),150,Scalar(255,255,255),2,CV_AA,0);
       cv::circle(fActualAux,Point2f(1000,528),150,Scalar(255,255,255),2,CV_AA,0);

       //Nombre de la aplicación y logo
       resize(image, image, Size(100,100));

               if (!image.empty()) {
                   Mat dstROI = fActualAux(cv::Rect(600, 25, 100, 100));
                   image.copyTo(dstROI);
                  // cv::Mat colorX(image.size(), CV_8UC3, cv::Scalar(56, 89, 245));
                  // cv::addWeighted(colorX, 0, image, 1.0 - 0 , 0.0, image);

               }


       cv::Mat roiA = fActualAux(cv::Rect(775, 30, 75, 75));
       cv::Mat colorA(roiA.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(colorA, 0.5, roiA, 1.0 - 0.5 , 0.0, roiA);
       cv::rectangle(fActualAux,Rect(775, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roi1 = fActualAux(cv::Rect(300, 175, 700, 75));
       cv::Mat color0(roi1.size(), CV_8UC3, cv::Scalar(255, 153, 51));
       cv::addWeighted(color0, 0.5, roi1, 1.0 - 0.5 , 0.0, roi1);
       cv::rectangle(fActualAux,Rect(300, 175, 700, 75),Scalar(0,0,0),3,CV_AA,0);

       if (bSelec) {
           cv::Mat colorx(roi1.size(), CV_8UC3, cv::Scalar(11, 193, 190));
           cv::addWeighted(colorx, 0.7, roi1, 1.0 - 0.7 , 0.0, roi1);
           cv::rectangle(fActualAux,Rect(300, 175, 700, 75),Scalar(0,0,0),3,CV_AA,0);
       }

       cv::Mat roi2 = fActualAux(cv::Rect(100, 175, 75, 75));
       cv::Mat color1(roi2.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color1, alpha, roi2, 1.0 - alpha , 0.0, roi2);
       cv::rectangle(fActualAux,Rect(100, 175, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roi3 = fActualAux(cv::Rect(1100, 175, 75, 75));
       cv::Mat color2(roi3.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color2, alpha, roi3, 1.0 - alpha , 0.0, roi3);
       cv::rectangle(fActualAux,Rect(1100, 175, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::putText(fActualAux,"ELEGIR PERFIL",Point2f(575,220), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"-",Point2f(130,215), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"+",Point2f(1130,215), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"OK",Point2f(800,75), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));

       perfilSuperior= 0;
    }
        break;

    case 2:
    {
        //Qué aparece en la pantalla 2
        // Creamos una Current Frame auxiliar para que los dibujos de botones en la pantalla no interfieran en la Diff Frame, representándola después por pantalla
       fActualAux = fActual.clone();
       double alpha = 0.4;

       cv::circle(fActualAux,Point2f(262,528),150,Scalar(255,255,255),2,CV_AA,0);
       cv::circle(fActualAux,Point2f(1000,528),150,Scalar(255,255,255),2,CV_AA,0);

       cv::Mat roiA = fActualAux(cv::Rect(775, 30, 75, 75));
       cv::Mat colorA(roiA.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(colorA, alpha, roiA, 1.0 - alpha , 0.0, roiA);
       cv::rectangle(fActualAux,Rect(775, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roiAt = fActualAux(cv::Rect(450, 30, 75, 75));
       cv::Mat colorAt(roiAt.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(colorAt, alpha, roiAt, 1.0 - alpha , 0.0, roiAt);
       cv::rectangle(fActualAux,Rect(450, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       if (aSelec) {
           cv::Mat colorx(roiAt.size(), CV_8UC3, cv::Scalar(11, 193, 190));
           cv::addWeighted(colorx, 0.7, roiAt, 1.0 - 0.7 , 0.0, roiAt);
           cv::rectangle(fActualAux,Rect(450, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);
       }

       cv::Mat roi1 = fActualAux(cv::Rect(300, 175, 700, 75));
       cv::Mat color0(roi1.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color0, alpha, roi1, 1.0 - alpha , 0.0, roi1);
       cv::rectangle(fActualAux,Rect(300, 175, 700, 75),Scalar(0,0,0),3,CV_AA,0);

       if (boton==0) {
           cv::Mat colorx(roi1.size(), CV_8UC3, cv::Scalar(255, 153, 51));
           cv::addWeighted(colorx, 0.7, roi1, 1.0 - 0.7 , 0.0, roi1);
           cv::rectangle(fActualAux,Rect(300, 175, 700, 75),Scalar(0,0,0),3,CV_AA,0);

           if (bSelec) {
               cv::Mat colorx(roi1.size(), CV_8UC3, cv::Scalar(11, 193, 190));
               cv::addWeighted(colorx, 0.7, roi1, 1.0 - 0.7 , 0.0, roi1);
               cv::rectangle(fActualAux,Rect(300, 175, 700, 75),Scalar(0,0,0),3,CV_AA,0);
           }
       }

       cv::Mat roi5 = fActualAux(cv::Rect(100, 175, 75, 75));
       cv::Mat color5(roi5.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color5, alpha, roi5, 1.0 - alpha , 0.0, roi5);
       cv::rectangle(fActualAux,Rect(100, 175, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roi6 = fActualAux(cv::Rect(1100, 175, 75, 75));
       cv::Mat color6(roi6.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color6, alpha, roi6, 1.0 - alpha , 0.0, roi6);
       cv::rectangle(fActualAux,Rect(1100, 175, 75, 75),Scalar(0,0,0),3,CV_AA,0);


           cv::putText(fActualAux,"CREAR PERFIL",Point2f(565,220), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
           cv::putText(fActualAux,"-",Point2f(130,215), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
           cv::putText(fActualAux,"+",Point2f(1130,215), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
           cv::putText(fActualAux,"OK",Point2f(800,75), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
           cv::putText(fActualAux,"ESC",Point2f(465,75),FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));

                   int desp = 0;

                   bool fin = false;

                   for(int i =perfilSuperior; (i<dimP) && !fin; i++){

                            cv::Mat roi3 = fActualAux(cv::Rect(300, 251+desp, 700, 75));
                            cv::Mat color3(roi3.size(), CV_8UC3, cv::Scalar(56, 89, 245));
                            cv::addWeighted(color3, alpha, roi3, 1.0 - alpha , 0.0, roi3);
                            cv::rectangle(fActualAux,Rect(300, 251+desp, 700, 75),Scalar(0,0,0),3,CV_AA,0);

                            if (boton==(i+1)) {
                                cv::Mat colorx(roi3.size(), CV_8UC3, cv::Scalar(255, 153, 51));
                                cv::addWeighted(colorx, 0.7, roi3, 1.0 - 0.7 , 0.0, roi3);
                                cv::rectangle(fActualAux,Rect(300, 251+desp, 700, 75),Scalar(0,0,0),3,CV_AA,0);

                                if (bSelec) {
                                    cv::Mat colorx(roi3.size(), CV_8UC3, cv::Scalar(11, 193, 190));
                                    cv::addWeighted(colorx, 0.7, roi3, 1.0 - 0.7 , 0.0, roi3);
                                    cv::rectangle(fActualAux,Rect(300, 251+desp, 700, 75),Scalar(0,0,0),3,CV_AA,0);
                                }

                                  }

                            cv::putText(fActualAux,listaPerfiles[i],Point2f(575,296 + desp),FONT_HERSHEY_TRIPLEX, 1,Scalar(255,255,255));


                            desp+=76;
                            if (i-2==perfilSuperior)fin=true;

                   }

                   if (perfilSuperior+3<dimP) {
                       cv::arrowedLine(fActualAux,Point2f(644,482),Point2f(644,506),Scalar(255,255,255),8,CV_AA,0,0.7);
                   }
    }
        break;

    case 3:
    {
        //Qué aparece en la pantalla 3
        // Creamos una Current Frame auxiliar para que los dibujos de botones en la pantalla no interfieran en la Diff Frame, representándola después por pantalla
       fActualAux = fActual.clone();
       double alpha = 0.4;

       cv::circle(fActualAux,Point2f(262,528),150,Scalar(255,255,255),2,CV_AA,0);
       cv::circle(fActualAux,Point2f(1000,528),150,Scalar(255,255,255),2,CV_AA,0);

       cv::Mat roiA = fActualAux(cv::Rect(775, 30, 75, 75));
       cv::Mat colorA(roiA.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(colorA, alpha, roiA, 1.0 - alpha , 0.0, roiA);
       cv::rectangle(fActualAux,Rect(775, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roiAt = fActualAux(cv::Rect(450, 30, 75, 75));
       cv::Mat colorAt(roiAt.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(colorAt, alpha, roiAt, 1.0 - alpha , 0.0, roiAt);
       cv::rectangle(fActualAux,Rect(450, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       if (aSelec) {
           cv::Mat colorAt(roiAt.size(), CV_8UC3, cv::Scalar(11, 193, 190));
           cv::addWeighted(colorAt, 0.7, roiAt, 1.0 - 0.7 , 0.0, roiAt);
           cv::rectangle(fActualAux,Rect(450, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);
       }

       cv::Mat roi1 = fActualAux(cv::Rect(300, 175, 700, 75));
       cv::Mat color0(roi1.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color0, alpha, roi1, 1.0 - alpha , 0.0, roi1);
       cv::rectangle(fActualAux,Rect(300, 175, 700, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roi2 = fActualAux(cv::Rect(300, 251, 700, 75));
       cv::Mat color2(roi2.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color2, alpha, roi2, 1.0 - alpha , 0.0, roi2);
       cv::rectangle(fActualAux,Rect(300, 251, 700, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roi3 = fActualAux(cv::Rect(100, 175, 75, 75));
       cv::Mat color5(roi3.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color5, alpha, roi3, 1.0 - alpha , 0.0, roi3);
       cv::rectangle(fActualAux,Rect(100, 175, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roi4 = fActualAux(cv::Rect(1100, 175, 75, 75));
       cv::Mat color6(roi4.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color6, alpha, roi4, 1.0 - alpha , 0.0, roi4);
       cv::rectangle(fActualAux,Rect(1100, 175, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       if (boton==0) {
           cv::Mat colorx(roi1.size(), CV_8UC3, cv::Scalar(255, 153, 51));
           cv::addWeighted(colorx, 0.7, roi1, 1.0 - 0.7 , 0.0, roi1);
           cv::rectangle(fActualAux,Rect(300, 175, 700, 75),Scalar(0,0,0),3,CV_AA,0);

           if (bSelec) {
               cv::Mat colorx(roi1.size(), CV_8UC3, cv::Scalar(11, 193, 190));
               cv::addWeighted(colorx, 0.7, roi1, 1.0 - 0.7 , 0.0, roi1);
               cv::rectangle(fActualAux,Rect(300, 175, 700, 75),Scalar(0,0,0),3,CV_AA,0);

            }
       }

       if (boton==1) {
           cv::Mat colorx(roi2.size(), CV_8UC3, cv::Scalar(255, 153, 51));
           cv::addWeighted(colorx, 0.7, roi2, 1.0 - 0.7 , 0.0, roi2);
           cv::rectangle(fActualAux,Rect(300, 251, 700, 75),Scalar(0,0,0),3,CV_AA,0);

           if (bSelec) {
               cv::Mat colorx(roi2.size(), CV_8UC3, cv::Scalar(11, 193, 190));
               cv::addWeighted(colorx, 0.7, roi2, 1.0 - 0.7 , 0.0, roi2);
               cv::rectangle(fActualAux,Rect(300, 251, 700, 75),Scalar(0,0,0),3,CV_AA,0);
            }
       }


       cv::putText(fActualAux,"LANZAR",Point2f(600,220), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"ELIMINAR PERFIL",Point2f(500,296),FONT_HERSHEY_TRIPLEX, 1,Scalar(255,255,255));
       cv::putText(fActualAux,"-",Point2f(130,215), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"+",Point2f(1130,215), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"OK",Point2f(800,75), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"ESC",Point2f(465,75),FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
        }
        break;

    case 4:
       {
        //Qué aparece en la pantalla 4
        // Creamos una Current Frame auxiliar para que los dibujos de botones en la pantalla no interfieran en la Diff Frame, representándola después por pantalla
       fActualAux = fActual.clone();
       double alpha = 0.5;

       cv::circle(fActualAux,Point2f(262,528),150,Scalar(255,255,255),2,CV_AA,0);
       cv::circle(fActualAux,Point2f(1000,528),150,Scalar(255,255,255),2,CV_AA,0);

       cv::Mat roiA = fActualAux(cv::Rect(775, 30, 75, 75));
       cv::Mat colorA(roiA.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(colorA, alpha, roiA, 1.0 - alpha , 0.0, roiA);
       cv::rectangle(fActualAux,Rect(775, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roiAt = fActualAux(cv::Rect(450, 30, 75, 75));
       cv::Mat colorAt(roiAt.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(colorAt, alpha, roiAt, 1.0 - alpha , 0.0, roiAt);
       cv::rectangle(fActualAux,Rect(450, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       if (aSelec) {
           cv::Mat colorAt(roiAt.size(), CV_8UC3, cv::Scalar(11, 193, 190));
           cv::addWeighted(colorAt, 0.7, roiAt, 1.0 - 0.7 , 0.0, roiAt);
           cv::rectangle(fActualAux,Rect(450, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);
       }


       cv::Mat roi1 = fActualAux(cv::Rect(300, 175, 700, 75));
       cv::Mat color0(roi1.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color0, alpha, roi1, 1.0 - alpha , 0.0, roi1);
       cv::rectangle(fActualAux,Rect(300, 175, 700, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roi2 = fActualAux(cv::Rect(300, 251, 700, 75));
       cv::Mat color2(roi2.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color2, alpha, roi2, 1.0 - alpha , 0.0, roi2);
       cv::rectangle(fActualAux,Rect(300, 251, 700, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roi3 = fActualAux(cv::Rect(300, 327, 700, 75));
       cv::Mat color3(roi3.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color3, alpha, roi3, 1.0 - alpha , 0.0, roi3);
       cv::rectangle(fActualAux,Rect(300, 327, 700, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roi4 = fActualAux(cv::Rect(300, 403, 700, 75));
       cv::Mat color4(roi4.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color4, alpha, roi4, 1.0 - alpha , 0.0, roi4);
       cv::rectangle(fActualAux,Rect(300, 403, 700, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roi5 = fActualAux(cv::Rect(100, 175, 75, 75));
       cv::Mat color5(roi5.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color5, alpha, roi5, 1.0 - alpha , 0.0, roi5);
       cv::rectangle(fActualAux,Rect(100, 175, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roi6 = fActualAux(cv::Rect(1100, 175, 75, 75));
       cv::Mat color6(roi6.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color6, alpha, roi6, 1.0 - alpha , 0.0, roi6);
       cv::rectangle(fActualAux,Rect(1100, 175, 75, 75),Scalar(0,0,0),3,CV_AA,0);


       switch (boton){

       case 0:{
           cv::Mat colorx(roi1.size(), CV_8UC3, cv::Scalar(255, 153, 51));
           cv::addWeighted(colorx, 0.7, roi1, 1.0 - 0.7 , 0.0, roi1);
           cv::rectangle(fActualAux,Rect(300, 175, 700, 75),Scalar(0,0,0),3,CV_AA,0);

           if (bSelec) {
               cv::Mat colorx(roi1.size(), CV_8UC3, cv::Scalar(11, 193, 190));
               cv::addWeighted(colorx, 0.7, roi1, 1.0 - 0.7 , 0.0, roi1);
               cv::rectangle(fActualAux,Rect(300, 175, 700, 75),Scalar(0,0,0),3,CV_AA,0);

            }

           break;
       }


       case 1:{
           cv::Mat colorx(roi2.size(), CV_8UC3, cv::Scalar(255, 153, 51));
           cv::addWeighted(colorx, 0.7, roi2, 1.0 - 0.7 , 0.0, roi2);
           cv::rectangle(fActualAux,Rect(300, 251, 700, 75),Scalar(0,0,0),3,CV_AA,0);

           if (bSelec) {
               cv::Mat colorx(roi2.size(), CV_8UC3, cv::Scalar(11, 193, 190));
               cv::addWeighted(colorx, 0.7, roi2, 1.0 - 0.7 , 0.0, roi2);
               cv::rectangle(fActualAux,Rect(300, 251, 700, 75),Scalar(0,0,0),3,CV_AA,0);

            }

           break;
       }


       case 2:{
           cv::Mat colorx(roi3.size(), CV_8UC3, cv::Scalar(255, 153, 51));
           cv::addWeighted(colorx, 0.7, roi3, 1.0 - 0.7 , 0.0, roi3);
           cv::rectangle(fActualAux,Rect(300, 327, 700, 75),Scalar(0,0,0),3,CV_AA,0);

           if (bSelec) {
               cv::Mat colorx(roi3.size(), CV_8UC3, cv::Scalar(11, 193, 190));
               cv::addWeighted(colorx, 0.7, roi3, 1.0 - 0.7 , 0.0, roi3);
               cv::rectangle(fActualAux,Rect(300, 327, 700, 75),Scalar(0,0,0),3,CV_AA,0);

            }

       break;

       }


       case 3:{
           cv::Mat colorx(roi4.size(), CV_8UC3, cv::Scalar(255, 153, 51));
           cv::addWeighted(colorx, 0.7, roi4, 1.0 - 0.7 , 0.0, roi4);
           cv::rectangle(fActualAux,Rect(300, 403, 700, 75),Scalar(0,0,0),3,CV_AA,0);

           if (bSelec) {
               cv::Mat colorx(roi4.size(), CV_8UC3, cv::Scalar(11, 193, 190));
               cv::addWeighted(colorx, 0.7, roi4, 1.0 - 0.7 , 0.0, roi4);
               cv::rectangle(fActualAux,Rect(300, 403, 700, 75),Scalar(0,0,0),3,CV_AA,0);

            }

           break;
       }


    }



     if (adelante==-1)

     {
         cv::putText(fActualAux,listaCanciones[cancionCargada] + " cargada",Point2f(575,150), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(7,10,242));

         pHilo->cancion=listaCanciones[cancionCargada] + ".mp3"; //Aquí cargamos la canción seleccionada en el pHilo de primerHilo
     }

     if (adelante==2){

         QString nombrePerfil = QString::fromStdString(listaPerfiles[perfilCargado]);
         QString Filename = "C:/Users/lagoa/Documents/Teleco/TFG/Versiones/TFG VERSION 3/perfiles/" + nombrePerfil + ".txt";

             QFile mFile(Filename);

             if(!mFile.open(QFile::ReadOnly | QFile::Text)){

                 qDebug() << "No se pudo abrir el archivo para leer";
                 return;
             }

             QTextStream in (&mFile);

             QString linea = in.readLine();



             cv::putText(fActualAux,linea.toStdString() + " cargada",Point2f(575,150), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(7,10,242));

             pHilo->cancion=linea.toStdString(); //Aquí cargamos la canción seleccionada en el pHilo de primerHilo


         linea = in.readLine();
         freq=linea.toDouble();
         //std::string str = std::to_string(freq);

         //cv::putText(fActualAux,str,Point2f(1138,331), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));

         linea = in.readLine();
         amp=linea.toDouble();
         //str = std::to_string(amp);

         //cv::putText(fActualAux,str,Point2f(122,325), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));

             mFile.flush();
             mFile.close();


     }

        std::string str1 = std::to_string(freq);
        std::string str2 = std::to_string(amp);
        cv::putText(fActualAux,str1,Point2f(1138,331), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(7,10,242));
        cv::putText(fActualAux,str2,Point2f(122,325), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(7,10,242));



       cv::circle(fActualAux,Point2f(323, 327),10,Scalar(7,10,242),-1,CV_AA,0);

       cv::putText(fActualAux,"CARGAR MP3",Point2f(575,220), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"VOLUMEN",Point2f(575,296),FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"FRECUENCIA",Point2f(550,372),FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"GUARDAR PERFIL",Point2f(560,448),FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"PAUSE",Point2f(110,215), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"PLAY",Point2f(1110,215), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"OK",Point2f(800,75), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
       cv::putText(fActualAux,"ESC",Point2f(465,75),FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));


       //Poner aqui un if que sepa si vengo de la pantalla3 o de la pantalla5. Si vengo de la pantalla5 primero agarro listacanciones de la cancion superior y meto
       //eso. NOS DIMOS CUENTA DE QUE HACIENDOLO EN LA PANTALLA 5 ANTES DE REGRESAR A LA 4 TAMBIÉN SIRVE...

       cancionSuperior=0;

        }
        break;




    case 5:
    {
        //Qué aparece en la pantalla 5
        // Creamos una Current Frame auxiliar para que los dibujos de botones en la pantalla no interfieran en la Diff Frame, representándola después por pantalla
       fActualAux = fActual.clone();
       double alpha = 0.4;

       cv::circle(fActualAux,Point2f(262,528),150,Scalar(255,255,255),2,CV_AA,0);
       cv::circle(fActualAux,Point2f(1000,528),150,Scalar(255,255,255),2,CV_AA,0);

       cv::Mat roiA = fActualAux(cv::Rect(775, 30, 75, 75));
       cv::Mat colorA(roiA.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(colorA, alpha, roiA, 1.0 - alpha , 0.0, roiA);
       cv::rectangle(fActualAux,Rect(775, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roiAt = fActualAux(cv::Rect(450, 30, 75, 75));
       cv::Mat colorAt(roiAt.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(colorAt, alpha, roiAt, 1.0 - alpha , 0.0, roiAt);
       cv::rectangle(fActualAux,Rect(450, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       if (aSelec) {
           cv::Mat colorx(roiAt.size(), CV_8UC3, cv::Scalar(11, 193, 190));
           cv::addWeighted(colorx, 0.7, roiAt, 1.0 - 0.7 , 0.0, roiAt);
           cv::rectangle(fActualAux,Rect(450, 30, 75, 75),Scalar(0,0,0),3,CV_AA,0);
       }

       cv::Mat roi5 = fActualAux(cv::Rect(100, 175, 75, 75));
       cv::Mat color5(roi5.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color5, alpha, roi5, 1.0 - alpha , 0.0, roi5);
       cv::rectangle(fActualAux,Rect(100, 175, 75, 75),Scalar(0,0,0),3,CV_AA,0);

       cv::Mat roi6 = fActualAux(cv::Rect(1100, 175, 75, 75));
       cv::Mat color6(roi6.size(), CV_8UC3, cv::Scalar(56, 89, 245));
       cv::addWeighted(color6, alpha, roi6, 1.0 - alpha , 0.0, roi6);
       cv::rectangle(fActualAux,Rect(1100, 175, 75, 75),Scalar(0,0,0),3,CV_AA,0);



           cv::putText(fActualAux,"-",Point2f(130,215), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
           cv::putText(fActualAux,"+",Point2f(1130,215), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
           cv::putText(fActualAux,"OK",Point2f(800,75), FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));
           cv::putText(fActualAux,"ESC",Point2f(465,75),FONT_HERSHEY_TRIPLEX, 0.7,Scalar(255,255,255));

                   int desp = 0;

                   bool fin = false;

                   for(int i =cancionSuperior; (i<dimC) && !fin; i++){

                            cv::Mat roi3 = fActualAux(cv::Rect(300, 175+desp, 700, 75));
                            cv::Mat color3(roi3.size(), CV_8UC3, cv::Scalar(56, 89, 245));
                            cv::addWeighted(color3, alpha, roi3, 1.0 - alpha , 0.0, roi3);
                            cv::rectangle(fActualAux,Rect(300, 175+desp, 700, 75),Scalar(0,0,0),3,CV_AA,0);

                            if (boton==(i)) {
                                cv::Mat colorx(roi3.size(), CV_8UC3, cv::Scalar(255, 153, 51));
                                cv::addWeighted(colorx, 0.7, roi3, 1.0 - 0.7 , 0.0, roi3);
                                cv::rectangle(fActualAux,Rect(300, 175+desp, 700, 75),Scalar(0,0,0),3,CV_AA,0);

                                if (bSelec) {
                                    cv::Mat colorx(roi3.size(), CV_8UC3, cv::Scalar(11, 193, 190));
                                    cv::addWeighted(colorx, 0.7, roi3, 1.0 - 0.7 , 0.0, roi3);
                                    cv::rectangle(fActualAux,Rect(300, 175+desp, 700, 75),Scalar(0,0,0),3,CV_AA,0);

                                }

                                  }

                            cv::putText(fActualAux,listaCanciones[i],Point2f(575,220 + desp),FONT_HERSHEY_TRIPLEX, 1,Scalar(255,255,255));


                            desp+=76;
                            if (i-3==cancionSuperior)fin=true;

                   }

                   if (cancionSuperior+4<dimC) {
                       cv::arrowedLine(fActualAux,Point2f(644,482),Point2f(644,506),Scalar(255,255,255),8,CV_AA,0,0.7);
                   }
    }
        break;
    }



}



void capturador::prepareNextFrame()
{

     cargaPerfiles();
     cargaCanciones();
     Manos();
     Pantallas();

     //cout << "Hola";

    // Save the current image
    fAyuda = fActual.clone();

    // Get a new image
    _vidCap >> fActual;

    // Flip it horizontally to appear like a mirror
    cv::flip(fActual,fActual,1);

    // Subtract the two to create a diff image.
    cv::subtract(fActual, fAyuda, fDif);

    // Evaluates the value of a single color channel on each pixel. If it is under
    // a certain threshold, the pixel value will be set to 0. Otherwise it will
    // be maxed out.
        cv::threshold(fDif, fDif, 15, 255, CV_THRESH_BINARY);

    // This helps reduce the background noise that crops up after thresholding.
        cv::morphologyEx(fDif, fDif, CV_MOP_OPEN, _kernel, cv::Point2i(-1, -1), 1);

    // Converts the diff image to grayscale.
        cv::cvtColor(fDif, fDif, CV_BGR2GRAY);



        switch (contPant){


        case 1:{
            // Qué ocurre en la pantalla 1 --------------------------------------------------------------------------------------------------------------------------


            Scalar colour0 = fDif.at<uchar>(Point(813,67));
             if(colour0.val[0]==255)
           {
             go=go+1;
             cout << go;

             }

             if(go>4) go=4;

             if(go==4){

                 bSelec=true;
                 cEspera+=1;

                 if (cEspera==10)
                 {
                adelante=1;
                contPant=2;
                cEspera=0;
                go=0;
                bSelec=false;
                cont=0;
                 }
            }



                if (pderecha && pizquierda){

                    pderecha=false;
                    pizquierda=false;

                    contPant=2;

                }

            break;
        }


        case 2:{
            // Qué ocurre en la pantalla 2 --------------------------------------------------------------------------------------------------------------------------       
            Scalar colour0 = fDif.at<uchar>(Point(813,67));
            if(colour0.val[0]==255)
            {
             go=go+1;
             cout << go;

            }

            if(go>4) go=4;

            if(go==4){


                if(dimP==0){
                    bSelec=true;
                    cEspera+=1;

                    if (cEspera==10){
                        adelante=1;
                        contPant=4;
                        cEspera=0;
                        go=0;
                        bSelec=false;
                        cont=0;
                        boton=0;
                    }
                }

                for(int i =0; i<=dimP; i++){

                   if(boton==i){

                        bSelec=true;
                        cEspera+=1;

                    if (cEspera ==10){

                        perfilCargado = boton -1;
                        adelante=1;
                        if (boton!=0){
                        contPant=3;
                        }
                        else contPant=4;   //AQUI ESTÁ PROGRAMADO PARA QUE DEL BOTÓN CREAR PERFIL VAYA DIRECTAMENTE A LA PANTALLA 4 EN VEZ DE A LA 3
                        cEspera=0;
                        go=0;
                        bSelec=false;
                        cont= 0;
                        boton = 0;

                    }

                    }

              }

           }


            Scalar colour1 = fDif.at<uchar>(Point(485,66));
            if(colour1.val[0]==255)
            {
             back=back+1;
            }

            if(back>4) back=4;

            if(back==4){
                aSelec=true;
                cEspera+=1;
                cout<<cEspera;

                if (cEspera==10)
                {
                adelante=0;
                contPant=1;
                cEspera=0;
                back=0;
                aSelec=false;
                cont= 0;
                boton = 0;
            }

          }


                   Scalar colourM = fDif.at<uchar>(Point(1139, 208));
                   if(colourM.val[0]==255)
                   {
                    cont=cont+1;
                    cout << cont;

                        if (cont >2){
                        cont=2;
                                }
                    }

                   if(cont==2){
                       boton = 1;
                   }

            //       Scalar colourm = _difFrame.at<uchar>(Point(138, 209));
            //       if(colourm.val[0]==255)
            //       {
            //        cont=cont-1;
            //        cout << cont;

            //        if (cont <0){
            //            cont=0;
            //                    }
            //       }

            //       if(cont==0){
            //           boton = 0;
            //       }


            if (pderecha && pizquierda){

                pderecha=false;
                pizquierda=false;

              // contPant = 3;


            }

            else{

                if(pderecha)
                {
                 boton+=1;
                 pderecha = false;


                if (boton==1){

                    if (dimP<1)boton=0;
                }

                if (boton==2){

                    if (dimP<2)boton=0;
                 }

                if (boton==3){

                    if (dimP<3)boton=0;
               }


                 if(boton>3)
                 {

                     if (dimP>3){

                         if((perfilSuperior+2)<dimP-1) perfilSuperior+=1;
                         else {
                             perfilSuperior=0;
                             boton=0;
                         }
                     }

                     else  boton=0;

                 }
                }

                if (pizquierda)
                {

                 boton-=1;
                 pizquierda = false;

                 if (boton<0){

                     boton=0;
                 }

                 if (boton>2){


                     if(dimP>3){

                         if((perfilSuperior)>0) perfilSuperior-=1;
                         else boton=0;

                       }

                    else boton=0;
                }

            }

         }

            break;
        }


        case 3:{
            // Qué ocurre en la pantalla 3 ------------------------------------------------------------------------------------------------------------------------
            Scalar colour0 = fDif.at<uchar>(Point(813,67));
            if(colour0.val[0]==255)
            {
             go=go+1;
             cout << go;

            }

            if(go>4) go=4;

            if(go==4){

                for(int i =0; i<2; i++){

                    if (boton == i){

                        bSelec=true;
                        cEspera+=1;

                    if (cEspera ==10){

                        if (boton==0){

                         adelante=2;
                         contPant=4;


                        }

                        if (boton==1){

                         QString nombrePerfil = QString::fromStdString(listaPerfiles[perfilCargado]);
                         QString Filename = "C:/Users/lagoa/Documents/Teleco/TFG/Versiones/TFG VERSION 3/perfiles/" + nombrePerfil + ".txt";
                         QDir dir;
                         dir.remove(Filename);

                         adelante=-1;
                         contPant=2;

                        }

                        cEspera=0;
                        go=0;
                        bSelec=false;
                        cont= 0;
                        boton = 0;



                    }
                 }
             }
          }


            Scalar colour1 = fDif.at<uchar>(Point(485,66));
            if(colour1.val[0]==255)
            {
             back=back+1;
            }

            if(back>4) back=4;

            if(back==4){
                aSelec=true;
                cEspera+=1;
                cout<<cEspera;

                if (cEspera==10)
                {
                adelante=0;
                contPant=2;
                cEspera=0;
                back=0;
                aSelec=false;
                cont= 0;
                boton = 0;
            }
          }


     //       Scalar colourM = _difFrame.at<uchar>(Point(1139, 208));
     //       if(colourM.val[0]==255)
     //       {
     //        cont=cont+1;
     //        cout << cont;

     //            if (cont >2){
     //            cont=2;
     //                    }
     //        }

     //       if(cont==2){
     //           boton = 1;
     //       }

     //       Scalar colourm = _difFrame.at<uchar>(Point(138, 209));
     //       if(colourm.val[0]==255)
     //       {
     //        cont=cont-1;
     //        cout << cont;

     //        if (cont <0){
     //            cont=0;
     //                    }
     //       }

     //       if(cont==0){
     //           boton = 0;
     //       }

            if (pderecha && pizquierda){

             pderecha=false;
             pizquierda=false;

          // contPant = 4;


             }

            else{

                if(pderecha)
                {
                 boton+=1;
                 pderecha = false;

                 if (boton>1){

                     boton=0;
                 }
                }

                if (pizquierda)
                {

                 boton-=1;
                 pizquierda = false;

                 if (boton<0)

                     boton=1;
                }

            }

            break;
        }



        case 4:{
             // Qué ocurre en la pantalla 4 ----------------------------------------------------------------------------------------------------------------
            //cout << go;
                Scalar colour0 = fDif.at<uchar>(Point(813,67));
                if(colour0.val[0]==255)
                {
                 go=go+1;
                 cout << go;

                }

                if(go>4) go=4;

                if(go==4){

                    if(boton==0){

                        bSelec=true;
                        cEspera+=1;

                        if (cEspera==10){
                            adelante=1;
                            contPant=5;
                            cEspera=0;
                            go=0;
                            bSelec=false;
                            cont=0;
                            boton=0;
                        }
                    }


                            if (boton==2){


                                fix= true;
                                bSelec=true;

                                //cout<< "ACABAS DE SELECCIONAR CAMBIO DE FRECUENCIA EN TIEMPO REAL";

                                if (pizquierda)
                                {

                                freq=freq+0.001;
                                cout<< freq;
                                }

                                if (pderecha)
                                {

                                freq=freq-0.001;
                                }


                                Scalar colour7 = fDif.at<uchar>(Point(324,326));
                                if(colour7.val[0]==255)
                                {
                                 ret=ret+1;
                                }

                                if(ret>4) ret=4;

                                if (ret==4){
                                cEspera=0;
                                go=0;
                                bSelec=false;
                                cont=0;
                                boton=2;
                                ret=0;
                                fix=false;

                                }



                            }



                            if (boton==3){


                                if (cancionCargada == -1 ){


                                    cout<<"No hay ninguna canción cargada";
                                }

                                else{

                                    bSelec=true;
                                    cEspera+=1;

                                    if (cEspera==10){
                                        contPant=2;
                                        cEspera=0;
                                        go=0;
                                        bSelec=false;
                                        cont=0;
                                        boton=0;


                                    QString numPerfil = QString::number(dimP+1);
                                    QString Filename = "C:/Users/lagoa/Documents/Teleco/TFG/Versiones/TFG VERSION 3/perfiles/perfil" + numPerfil+ ".txt";
                                    QFile mFile(Filename);

                                    if(!mFile.open(QFile::WriteOnly | QFile::Text)){

                                        qDebug() << "No se pudo abrir el archivo para escribir";
                                        return;

                                    }

                                    QTextStream out (&mFile);
                                    numPerfil=QString::fromStdString(listaCanciones[cancionCargada]);
                                    out << numPerfil << endl;
                                    out << freq << endl;
                                    out << amp << endl;


                                    mFile.flush();
                                    mFile.close();

                                    }

                            }

                      }

              }


            Scalar colour1 = fDif.at<uchar>(Point(485,66));
            if(colour1.val[0]==255)
            {
             back=back+1;
            }

            if(back>4) back=4;

            if(back==4){
                aSelec=true;
                cEspera+=1;
                cout<<cEspera;

                if (cEspera==10)
                {
                adelante=0;
                contPant=3;
                cEspera=0;
                back=0;
                aSelec=false;
                cont= 0;
                boton = 0;
                music1=0;
                music2=0;
            }
          }





         Scalar colour2 = fDif.at<uchar>(Point(1136, 213));
         if(colour2.val[0]==255)
         {
          music1=music1+1;
          cout << music1;

         }

         if(music1==3){
             cout << " PLAY"<<endl;
             music1=0;
             chi=2;
            pHilo->start();

         }


         Scalar colour3 = fDif.at<uchar>(Point(135, 212));
         if(colour3.val[0]==255)
         {
          music2=music2+1;
          cout << music2;

         }

         if(music2==3){
             cout << " STOP"<<endl;
             music2=0;
             shi=2;
             pHilo->Stop = true;


         }


             if(pderecha&!fix)
             {

              boton+=1;
              pderecha = false;

              if (boton>3)  boton=0;

             }


             if (pizquierda&!fix)
             {

              boton-=1;
              pizquierda = false;

              if (boton<0) boton=3;

             }

         //}


          break;

        }

        case 5:{
            // Qué ocurre en la pantalla 5 --------------------------------------------------------------------------------------------------------------------------
            Scalar colour0 = fDif.at<uchar>(Point(813,67));
            if(colour0.val[0]==255)
            {
             go=go+1;
             cout << go;

            }

            if(go>4) go=4;

            if(go==4){

                for(int i =0; i<dimC; i++){

                   if(boton==i){

                        bSelec=true;
                        cEspera+=1;
                        cancionCargada=boton;

                    if (cEspera ==10){

                        adelante=-1;

                        //Meto en una variable string creada en capturador.h el LISTACANCIONES[cancionSuperior+boton]
                        contPant=4;   //AQUI ESTÁ PROGRAMADO PARA QUE DEL BOTÓN CREAR PERFIL VAYA DIRECTAMENTE A LA PANTALLA 4 EN VEZ DE A LA 3
                        cEspera=0;
                        go=0;
                        bSelec=false;
                        cont= 0;
                        boton = 0;

                    }

                    }

              }

           }


            Scalar colour1 = fDif.at<uchar>(Point(485,66));
            if(colour1.val[0]==255)
            {
             back=back+1;
            }

            if(back>4) back=4;

            if(back==4){
                aSelec=true;
                cEspera+=1;
                cout<<cEspera;

                if (cEspera==10)
                {
                adelante=0;
                contPant=4;
                cEspera=0;
                back=0;
                aSelec=false;
                cont= 0;
                boton = 0;
            }

          }


            if (pderecha && pizquierda){

                pderecha=false;
                pizquierda=false;

             //  contPant = 3;


            }

            else{

                if(pderecha)
                {
                 boton+=1;
                 pderecha = false;




                if (boton==0){

                    if (dimC<1)boton=0;
                }

                if (boton==1){

                    if (dimC<2)boton=0;
                 }

                if (boton==2){

                    if (dimC<3)boton=0;
               }

                if (boton==3){

                    if (dimC<4)boton=0;
               }


                 if(boton>3)
                 {

                     if (dimC>4){

                         if((cancionSuperior+3)<dimC-1) cancionSuperior+=1;
                         else {
                             cancionSuperior=0;
                             boton=0;
                         }
                     }

                     else  boton=0;

                 }
                }

                if (pizquierda)
                {

                 boton-=1;
                 cout<<cancionSuperior<<endl;
                 pizquierda = false;

                 if (boton<0){

                     boton=0;
                     cancionSuperior=0;         //***************************************************************************//
                 }

                 if (boton>3){

                     if(dimC>4){

                         if(cancionSuperior>0) cancionSuperior-=1;
                         else boton=0;

                       }

                    else boton=0;
                }

            }

         }

            break;
        }

    } //Fin del Switch ContPant

}
