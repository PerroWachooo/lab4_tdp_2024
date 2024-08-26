

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"

using namespace std;

// Constructor de la clase `Image`.
// Inicializa el tamaño del arreglo de la imagen y asigna memoria para almacenar los datos de la imagen.
Image::Image (){
    this->tamaño_arreglo = 65536;  // Define el tamaño del arreglo de la imagen (65536 elementos)
    this->ImageArray = new float[tamaño_arreglo];  // Asigna memoria para el arreglo de la imagen
    this->tamaño_imagen = 256;  // Define el tamaño de la imagen (256x256)
}

// Establece el tamaño de la imagen.
// Este método permite modificar el tamaño de la imagen después de crear el objeto.
void Image::set_tamaño_imagen(int tamaño_imagen){
    this->tamaño_imagen = tamaño_imagen;  // Actualiza el tamaño de la imagen
}

// Establece el tamaño del kernel.
// Este método permite definir el tamaño del kernel para operaciones posteriores (e.g., convolución).
void Image::set_tamaño_kernel(int tamaño_kernel){
    this->tamaño_kernel = tamaño_kernel;  // Actualiza el tamaño del kernel
}

// Carga la imagen desde un archivo.
// Este método lee los datos de la imagen desde un archivo de texto y los almacena en `ImageArray`.
void Image::cargar_image(string filename){

    ifstream inputFile;

    inputFile.open(filename);  // Abre el archivo especificado por `filename`
    if (!inputFile) {
        std::cout << "No se pudo abrir el archivo.";  // Muestra un mensaje de error si el archivo no se puede abrir
        return;
    }

    int count = 0;
    float* Array = new float[tamaño_arreglo];  // Asigna memoria temporal para leer los datos

    float value;
    while (inputFile >> value && count < tamaño_arreglo) {
        Array[count] = value;  // Lee los valores del archivo y los almacena en el arreglo
        count++;
    }
    this->ImageArray = Array;  // Asigna el arreglo leído a `ImageArray`
    inputFile.close();  // Cierra el archivo
    cout << "Imagen Creada con exito " << endl;  // Muestra un mensaje indicando que la imagen se cargó correctamente
}

// Guarda la imagen en un archivo.
// Este método escribe los datos de la imagen desde un vector en un archivo de texto.
void Image::grabar_image(float* arreglo, string nombreArchivo) {

    
    std::ofstream outFile(nombreArchivo);  // Crea y abre el archivo para escritura

    if (!outFile) {
        cout << "Error al abrir el archivo para escritura." << endl;  // Muestra un mensaje de error si el archivo no se puede abrir
        return;
    }

    for (int i = 0; i < tamaño_arreglo; i++) {
        outFile << arreglo[i] << std::endl;  // Escribe cada elemento del vector en una nueva línea
    }

    outFile.close();  // Cierra el archivo

    cout << "Imagen guardada correctamente en " << nombreArchivo << endl;  // Muestra un mensaje indicando que la imagen se guardó correctamente
}

// Imprime el arreglo de la imagen.
// Este método imprime todos los valores almacenados en `ImageArray` en la consola.
void Image::printArray(){
    for(int i = 0; i < tamaño_arreglo; i++){
        cout << ImageArray[i] << endl;  // Imprime cada valor del arreglo en una nueva línea
    }
}
