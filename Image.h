#ifndef IMAGE_H
#define IMAGE_H

// Importación de librerías estándar necesarias para la clase `Image`
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Declaración de la clase `Image`.
// Esta clase maneja datos de imágenes representados como arreglos de números flotantes.
class Image{

    public:

        float* ImageArray;  // Arreglo que almacena los datos de la imagen
        int tamaño_arreglo; // Tamaño del arreglo de la imagen (ej: 65536)
        int tamaño_imagen;  // Dimensiones de la imagen (ej: 256x256)
        int tamaño_kernel;  // Tamaño del kernel para operaciones de convolución

        // Constructor de la clase `Image`.
        Image();

        // Método para cargar los datos de una imagen desde un archivo.
        void cargar_image(string filename);
        
        // Método para guardar los datos de la imagen en un archivo.
        void grabar_image(float* arreglo, string nombreArchivo);

        // Método para establecer el tamaño de la imagen.
        void set_tamaño_imagen(int tamaño_imagen);

        // Método para establecer el tamaño del kernel.
        void set_tamaño_kernel(int tamaño_kernel);

        // Método para imprimir los valores del arreglo de la imagen.
        void printArray();

};

#endif