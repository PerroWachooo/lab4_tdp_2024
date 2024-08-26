#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"
#include "ImageProcesor.h"

using namespace std;

/*
 * Método: Constructor -> ImageProcesor
 * Descripción: Constructor por defecto de la clase `ImageProcesor`.
 * Parámetros:
 * - Ninguno.
 * Retorno:
 * - void.
 */
ImageProcesor::ImageProcesor(){}

/*
 * Método: minus
 * Descripción: Realiza la resta elemento por elemento entre dos arreglos de imágenes.
 * Parámetros:
 * - i1: Puntero al primer arreglo de la imagen.
 * - i2: Puntero al segundo arreglo de la imagen.
 * - tamañoArray: Tamaño del arreglo que representa la imagen.
 * Retorno:
 * - Puntero a un nuevo arreglo que contiene los resultados de la resta entre los elementos de `i1` y `i2`.
 */
float* ImageProcesor::minus(float* i1, float* i2, int tamañoArray){

    float* result = new float[tamañoArray];  // Asigna memoria para el resultado

    // Resta cada elemento de los arreglos `i1` e `i2`
    for(int i = 0; i < tamañoArray; i++){
        result[i] = i1[i] - i2[i];
    }
    return result;  // Retorna el arreglo resultante
}

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
float* ImageProcesor::c(float* image, int m, int tamañoFoto, int tamañoArray){

    float* output = new float[tamañoArray];  // Asigna memoria para el resultado de la convolución

    // Recorre cada píxel de la imagen
    for(int i = 0; i < tamañoFoto; i++){
        for(int j = 0; j < tamañoFoto; j++){
            float s = 0;  // Acumula la sumatoria de la convolución
            // Recorre cada elemento del kernel
            for(int ikernel = m * -1; ikernel <= m; ikernel++){
                for(int jkernel = m * -1; jkernel <= m; jkernel++){
                    
                    int imgX = j + jkernel;
                    int imgY = i + ikernel;
                    // Si el píxel desplazado está dentro de los límites de la imagen, suma el valor correspondiente
                    if (imgX >= 0 && imgX < tamañoFoto && imgY >= 0 && imgY < tamañoFoto) {
                        s += image[(j + jkernel) + tamañoFoto * (i + ikernel)];  
                    } else {
                        // Si no, suma 0 (tratamiento de bordes)
                        s += 0;
                    }     
                }
            }
            s = s / ((2 * m + 1) * (2 * m + 1));  // Normaliza el valor de `s` dividiendo por el tamaño del kernel
            output[j + tamañoFoto * i] = s;  // Asigna el valor calculado al arreglo de salida
        }
    }
    return output;  // Retorna el arreglo resultante de la convolución
}

/*
 * Método: printArray_index
 * Descripción: Imprime los valores de un arreglo bidimensional de la imagen en la consola.
 * Parámetros:
 * - vector_index: Puntero al arreglo que contiene los datos de la imagen.
 * - tamaño_img: Dimensiones de la imagen (ej: 256x256).
 * Retorno:
 * - void.
 */
void ImageProcesor::printArray_index(float* vector_index, int tamaño_img){
    for (int i = 0; i < tamaño_img; ++i) {
        for (int j = 0; j < tamaño_img; ++j) {
            std::cout << vector_index[i * tamaño_img + j] << " ";  // Imprime cada valor seguido de un espacio
        }
        std::cout << std::endl;  // Imprime una nueva línea al final de cada fila
    }
}

