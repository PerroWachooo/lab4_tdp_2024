
#include <vector>
#include "Image.h"
#include "ImageProcesor.h"

using namespace std;

// Este programa prueba las operaciones de procesamiento de imágenes, incluyendo la resta de dos imágenes y la operación de convolución.

int main(){
    ImageProcesor proccesor;  // Se crea un objeto `ImageProcesor`
    Image imagen1, imagen2;  // Se crean dos objetos `Image`

    imagen1.cargar_image("image.txt");  // Se carga la primera imagen desde "image.txt"
    imagen2.cargar_image("image.txt");  // Se carga la segunda imagen desde "image.txt"

    float* salida = new float[imagen1.tamaño_arreglo];  // Se crea un array para almacenar la salida de la operación
    salida = proccesor.minus(imagen1.ImageArray, imagen2.ImageArray, imagen1.tamaño_arreglo);  // Se resta imagen2 de imagen1

    // // Comentar para verificar los valores de salida, deberían ser 0 si las imágenes son iguales.
    // for (float num : salida) {
    //     cout << num << endl;
    // }

    int tamaño_kernel = 1;  // Tamaño del kernel para la operación de convolución
    float* salida_conv = proccesor.c(imagen2.ImageArray, tamaño_kernel, imagen2.tamaño_imagen, imagen2.tamaño_arreglo);  // Se aplica convolución

    proccesor.printArray_index(salida_conv, imagen2.tamaño_imagen);  // Se imprime la salida de la convolución

    for (int i = 0; i < imagen1.tamaño_arreglo; i++) {
        std::cout << "I: " << imagen2.ImageArray[i] << " Conv: " << salida_conv[i] << std::endl;  // Se comparan los valores originales y convolucionados
    }

    return 0;
}

// Este test verifica la correcta implementación de las operaciones de resta y convolución en la clase `ImageProcesor`.
