#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"
#include "ImageProcesor.h"
#include "Problem.h"

/*
 * Método: Constructor -> Problem
 * Descripción: Este constructor vacío se utiliza para inicializar un objeto `Problem` sin parámetros.
 * Parámetros:
 * - Ninguno.
 * Retorno:
 * - void.
 */
Problem::Problem(){};

/*
 * Método: Constructor -> Problem
 * Descripción: Este constructor se utiliza para inicializar un objeto `Problem` con una imagen observada (`Iobs`).
 * Parámetros:
 * - Iobs: Imagen observada que será utilizada en los cálculos del problema.
 * Retorno:
 * - void.
 */
Problem::Problem(Image Iobs){
    this->Iobs = Iobs;  // Asigna la imagen observada al objeto `Problem`
}

/*
 * Método: gradiente
 * Descripción: Calcula el gradiente de la función objetivo para la imagen dada.
 * Parámetros:
 * - I: Imagen sobre la cual se realiza el cálculo del gradiente.
 * - m: Parámetro que representa el tamaño del kernel utilizado en la convolución.
 * - tamaño_img: Dimensiones de la imagen.
 * - tamañoArray: Tamaño del arreglo que representa la imagen.
 * Retorno:
 * - Puntero a un arreglo que contiene el gradiente calculado.
 */
float* Problem::gradiente(float* I, int m, int tamaño_img, int tamañoArray){
    ImageProcesor p;
    float* x = new float[tamaño_img];  // Asigna memoria para el gradiente calculado

    // Realiza la convolución y la resta entre la imagen procesada y la imagen observada
    x = p.c(p.minus(p.c(I, m, tamaño_img, tamañoArray), Iobs.ImageArray, tamañoArray), m, tamaño_img, tamañoArray);

    this->dfunc = x;  // Almacena el gradiente calculado en la variable `dfunc`

    return x;  // Retorna el gradiente calculado
}

/*
 * Método: fo
 * Descripción: Calcula el valor de la función objetivo, que mide la diferencia entre la imagen procesada y la imagen observada.
 * Parámetros:
 * - I: Imagen sobre la cual se realiza el cálculo de la función objetivo.
 * - m: Parámetro que representa el tamaño del kernel utilizado en la convolución.
 * - tamaño_img: Dimensiones de la imagen.
 * - tamañoArray: Tamaño del arreglo que representa la imagen.
 * Retorno:
 * - Valor de la función objetivo.
 */
float Problem::fo(float* I, int m, int tamaño_img, int tamañoArray){
    ImageProcesor p;
    float sumatoria = 0;
    float* conv = new float[tamañoArray];  // Asigna memoria para la imagen convolucionada
    
    conv = p.c(I, m, tamaño_img, tamañoArray);  // Realiza la convolución de la imagen

    // Calcula la diferencia cuadrática acumulada entre la imagen convolucionada y la imagen observada
    for(int i = 0; i < tamaño_img; i++){
        for(int j = 0; j < tamaño_img; j++){
            float x = conv[j + (tamaño_img-1)*i] - Iobs.ImageArray[j + (tamaño_img-1)*i];
            sumatoria += x * x;  // Suma la diferencia cuadrada
        }
    }
    
    sumatoria = sumatoria * 0.5;  // Ajusta la sumatoria según la función objetivo
    this->func = sumatoria;  // Almacena el valor calculado de la función objetivo
    return sumatoria;  // Retorna el valor de la función objetivo
}
