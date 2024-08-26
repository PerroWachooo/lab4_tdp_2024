#ifndef PROBLEM_H
#define PROBLEM_H

// Importaciones de las librerías estándar necesarias
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"  // Importa la clase `Image`
#include "ImageProcesor.h"  // Importa la clase `ImageProcesor`

using namespace std;

// Clase `Problem`
// Esta clase representa un problema de optimización o procesamiento de imágenes
// que involucra cálculos de gradiente y función objetivo.
class Problem{

    public:

        float func;  // Almacena el valor de la función objetivo

        float* dfunc;  // Puntero a un arreglo que almacena el gradiente de la función objetivo

        /*
         * Método: Constructor -> Problem
         * Descripción: Constructor por defecto de la clase `Problem`.
         * Parámetros:
         * - Ninguno.
         * Retorno:
         * - void.
         */
        Problem();

        /*
         * Método: Constructor -> Problem
         * Descripción: Constructor de la clase `Problem` que inicializa el problema con una imagen observada.
         * Parámetros:
         * - obs: Imagen observada que se utiliza para calcular el gradiente y la función objetivo.
         * Retorno:
         * - void.
         */
        Problem(Image obs);

        Image Iobs;  // Imagen observada utilizada en los cálculos

        /*
         * Método: gradiente
         * Descripción: Calcula el gradiente de la función objetivo para la imagen dada.
         * Parámetros:
         * - I: Imagen sobre la cual se realiza el cálculo del gradiente.
         * - m: Tamaño del kernel utilizado en la convolución.
         * - tamaño_img: Dimensiones de la imagen.
         * - tamañoArray: Tamaño del arreglo que representa la imagen.
         * Retorno:
         * - Puntero a un arreglo que contiene el gradiente calculado.
         */
        float* gradiente(float* I, int m, int tamaño_img, int tamañoArray);

        /*
         * Método: fo
         * Descripción: Calcula el valor de la función objetivo que mide la diferencia entre la imagen procesada y la imagen observada.
         * Parámetros:
         * - I: Imagen sobre la cual se realiza el cálculo de la función objetivo.
         * - m: Tamaño del kernel utilizado en la convolución.
         * - tamaño_img: Dimensiones de la imagen.
         * - tamañoArray: Tamaño del arreglo que representa la imagen.
         * Retorno:
         * - Valor de la función objetivo.
         */
        float fo(float* I, int m, int tamaño_img, int tamañoArray);

};

#endif