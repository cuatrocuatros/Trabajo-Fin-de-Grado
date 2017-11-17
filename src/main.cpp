#include "pantalla0.h"
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
#include <vector>
#include "csound.hpp"
#include "globales.h"
#include "primerHilo.h"
#include "segundoHilo.h"
#include <QThread>
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>


//void Write(QString Filename){


//QFile mFile(Filename);

//if(!mFile.open(QFile::WriteOnly | QFile::Text)){

//    qDebug() << "No se pudo abrir el archivo para escribir";
//    return;

//}

//QTextStream out (&mFile);
//out << "Hello World";

//mFile.flush();
//mFile.close();

//}

//void Read(QString Filename){

//    QFile mFile(Filename);

//    if(!mFile.open(QFile::ReadOnly | QFile::Text)){

//        qDebug() << "No se pudo abrir el archivo para leer";
//        return;
//    }

//    QTextStream in (&mFile);
//    QString mText = in.readAll();

//    qDebug() << mText;

//    mFile.flush();
//    mFile.close();
//}


int main(int argc, char *argv[]) {

    //QString mFilename = "C:/Users/lagoa/Documents/Teleco/TFG/Versiones/TFG VERSION 3/perfiles/myfile.txt";
    //Write(mFilename);
    //Read(mFilename);

   QApplication a(argc, argv);

    // Show some instructions
    std::cout << "HEY THERE" << std::endl;
    //std::cout << "  't' toggles thresholding" << std::endl;
    //std::cout << "  'm' toggles morphing transformation" << std::endl;
    //std::cout << "  'g' toggles greyscale conversion" << std::endl;
    //std::cout << "  'q' quits" << std::endl;
    //std::cout << std::endl;


    // Comprobamos si elegimos el método de interacción convencional o visual
    pantalla0 p;
    p.show();



    return a.exec();

}

