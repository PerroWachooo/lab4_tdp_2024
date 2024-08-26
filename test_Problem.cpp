
#include <vector>
#include "Problem.h"
#include "Image.h"
#include "ImageProcesor.h"

using namespace std;

// Este programa prueba la implementación del cálculo del gradiente y la función objetivo para un problema de imágenes.

int main(){
    Image imagen, Iobs;  // Se crean objetos `Image` para la imagen y la imagen observada
    imagen.cargar_image("image.txt");  // Se carga la imagen desde "image.txt"
    Iobs.cargar_image("image.txt");  // Se carga la imagen observada desde "image.txt"

    float* p = new float[imagen.tamaño_arreglo];  // Array para almacenar los parámetros del problema
    Problem problema = Problem(Iobs);  // Se inicializa un objeto `Problem` con la imagen observada

    float* grad = problema.gradiente(p, 1, imagen.tamaño_imagen, imagen.tamaño_arreglo);  // Se calcula el gradiente
    float foo = problema.fo(p, 2, imagen.tamaño_imagen, imagen.tamaño_arreglo);  // Se calcula el valor de la función objetivo

    for (int i = 0; i < imagen.tamaño_arreglo; i++) {
        std::cout << "grad[" << i << "] = " << grad[i] << "I: " << imagen.ImageArray[i] << std::endl;  // Se imprime el gradiente y el valor de la imagen original
    }

    cout << "foo: " << foo << endl;  // Se imprime el valor de la función objetivo

    return 0;
}

// Este test verifica la correcta implementación del cálculo del gradiente y de la función objetivo en la clase `Problem`.
