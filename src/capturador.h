#ifndef CAPTURADOR_H
#define CAPTURADOR_H

#include "rastreador.h"
#include <opencv2/opencv.hpp>
#include <cassert>
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "primerHilo.h"
#include "segundoHilo.h"
#include "csound.hpp"
#include <thread>
#include <QObject>
#include <QUrl>
#include <QThread>
#include <QFile>
#include <QString>
#include <QDebug>
#include <globales.h>
#include <string>


/*
 * Permite rastrear movimiento
 */
class capturador : public rastreador
{
public:
    capturador();
    ~capturador();

    //Declaramos los punteros a los threads de sonido
    primerHilo *pHilo;
    //segundoHilo *sHilo;

    // Procesa el siguiente fotograma, haciendo los resultados disponibles mediante los ya mencionados getters
    void prepareNextFrame();

    // Frame getters
    cv::Mat curFrame() const { return fActual; }
    cv::Mat prvFrame() const { return fAyuda; }
    cv::Mat difFrame() const { return fDif; }
    cv::Mat curFrameAux() const { return fActualAux; }


    // Leer archivo
    //void Write(QString Filename);


    // Escribir archivo
    //void Read(QString Filename);


    // Cargar perfiles
    void cargaPerfiles();

    // Cargar canciones
    void cargaCanciones();

    // Qué perfiles están en pantalla
    int perfilSuperior;

    // Qué canciones están en pantalla
    int cancionSuperior;


    // Qué canción está cargada
    int cancionCargada = -1;

    // Qué perfil está cargado
    int perfilCargado = -1;


    // Pantallas
    void Pantallas();


    // Manos y puños
    void Manos();


    // Verificadores de música
    int haySonido1();
    bool haySonido2();


    //Contador veces que se mueve la mano por un pixel para pulsar un boton del menú
    int ret = 0;
    int go = 0;
    int back = 0;
    int music1 = 0;
    int music2 = 0;
    int cont= 0;
    int boton= 0;


    // Array de strings con la lista de todos los perfiles
    std::string listaPerfiles[MAXLISTAPERFILES];

    // Array de strings con la lista de todos los canciones
    std::string listaCanciones[MAXLISTACANCIONES];

    // Tamaño de la dimensión del array de perfiles
    int dimP;

    // Tamaño de la dimensión del array de canciones
    int dimC;

    // Selector de pantalla
    int contPant = 1;


private:
    // Makes a boolean printable
    std::string boolToString(bool value) { return (value) ? "true" : "false"; }

    // Captura Cámara Web
    cv::VideoCapture _vidCap;

    // Almacenamiento de fotogramas
    cv::Mat fActual;
    cv::Mat fAyuda;
    cv::Mat fDif;
    cv::Mat _kernel;
    cv::Mat fActualAux;
    cv::Mat image;

    // Fijar opcion cuarta pantalla
    bool fix = false;

    // Verificadores de puños
    bool pderecha= false;
    bool pizquierda=false;

    // Verificador de selección
    bool bSelec=false; //de botón
    bool aSelec=false; //de atrás

    // Contador tiempo puños
    int cp = 0;

    // Contador tiempo espera
    int cEspera = 0;

};

#endif // CAPTURADOR_H
