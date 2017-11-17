#ifndef GLOBALES_H
#define GLOBALES_H

// Todas las declaraciones globales


// Método conveccional o visual
extern double v;


// Se activa la canción en la pantalla 4
extern double chi;
extern double shi;


// Parámetros de frecuencia y amplitud de la pantalla4
extern double freq;
extern double amp;

// Variables booleanas desplazamiento entre pantallas  Adelante = 1 vamos avanzando hacia pantallas posteriores.   Adelante = 0 lo contrario
extern double adelante;

// Definimos el tamaño máximo de la lista de perfiles y canciones
#define MAXLISTAPERFILES 50
#define MAXLISTACANCIONES 50


#endif // GLOBALES_H
