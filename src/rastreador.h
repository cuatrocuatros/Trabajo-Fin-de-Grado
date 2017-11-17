#ifndef RASTREADOR_H
#define RASTREADOR_H

#include <opencv2/opencv.hpp>

/*
 * Interfaz para implementaciones de rastreado. Captura de cámara web
 */

class rastreador
{
public:
    rastreador();

    // Procesa el siguiente fotograma, haciendo los resultados disponibles mediante los ya mencionados getters
    virtual void prepareNextFrame() = 0;

    // Getters obligatorios
    virtual cv::Mat curFrame() const = 0;
    virtual cv::Mat prvFrame() const = 0;
    virtual cv::Mat difFrame() const = 0;
    virtual cv::Mat curFrameAux() const = 0;
};

#endif // RASTREADOR_H
