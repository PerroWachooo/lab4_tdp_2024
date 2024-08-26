#ifndef IMAGEPROCESOR_H
#define IMAGEPROCESOR_H

// Importaciones de las librerías estándar necesarias
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"  

// Clase `ImageProcesor`
// Esta clase proporciona métodos para realizar operaciones de procesamiento sobre imágenes,
// tales como resta de imágenes, convolución, y la impresión de arreglos de imágenes.
class ImageProcesor {

    public:

        /*
         * Método: Constructor -> ImageProcesor
         * Descripción: Constructor por defecto de la clase `ImageProcesor`.
         * Parámetros:
         * - Ninguno.
         * Retorno:
         * - void.
         */
        ImageProcesor();

        /*
         * Método: minus
         * Descripción: Realiza la resta elemento por elemento entre dos arreglos de imágenes.
         * Parámetros:
         * - i1: Puntero al primer arreglo de la imagen.
         * - i2: Puntero al segundo arreglo de la imagen.
         * - tamaño_img: Tamaño del arreglo que representa la imagen.
         * Retorno:
         * - Puntero a un nuevo arreglo que contiene los resultados de la resta entre los elementos de `i1` y `i2`.
         */
        float* minus(float* i1, float* i2, int tamaño_img);

        /*
         * Método: c (convolución)
         * Descripción: Aplica un filtro de convolución sobre la imagen utilizando un kernel cuadrado de tamaño (2*m+1)x(2*m+1).
         * Parámetros:
         * - image: Puntero al arreglo que contiene los datos de la imagen.
         * - m: Tamaño del kernel utilizado en la convolución.
         * - tamañoFoto: Dimensiones de la imagen (ej: 256x256).
         * - tamañoArray: Tamaño del arreglo que representa la imagen.
         * Retorno:
         * - Puntero a un nuevo arreglo que contiene los resultados de la convolución.
         */
        float* c(float* image, int m, int tamañoFoto, int tamañoArray);

        /*
         * Método: printArray_index
         * Descripción: Imprime los valores de un arreglo bidimensional de la imagen en la consola.
         * Parámetros:
         * - vector_index: Puntero al arreglo que contiene los datos de la imagen.
         * - tamaño_img: Dimensiones de la imagen (ej: 256x256).
         * Retorno:
         * - void.
         */
        void printArray_index(float* vector_index, int tamaño_img);

};

#endif
