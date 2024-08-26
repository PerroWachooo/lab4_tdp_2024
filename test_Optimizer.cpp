
#include <iostream>
#include "Optimizer.h"
#include "Problem.h"
#include "Image.h"

using namespace std;

// Este programa prueba el proceso de optimización aplicado a un problema de imágenes.

int main(){
    Image imagen;  // Se crean objetos `Image` para la imagen y la imagen observada
    imagen.cargar_image("image.txt");  // Se carga la imagen desde "image.txt"
    Problem problema = Problem(imagen);  // Se inicializa un objeto `Problem` con la imagen observada

    int N = 256;  // Dimensión de la imagen
    float ftol = 1e-15;  // Tolerancia para el criterio de convergencia
    int max_it = 10;  // Número máximo de iteraciones
    float* p = new float[imagen.tamaño_arreglo];  // Array para almacenar los parámetros de optimización
    
    for (int i = 0; i < imagen.tamaño_arreglo; ++i) {
        p[i] = 0.0f;
    }
    
    Optimizer *optimizer = new Optimizer(problema, p, N*N, ftol, max_it);  // Se crea un objeto `Optimizer`
    optimizer->frprmn();  // Se ejecuta el método de optimización
    //Se imprime el resultado
    for (int i = 0; i < imagen.tamaño_arreglo; ++i) {
        cout<< p[i] <<endl;
    }
    
    return 0;
}

// Este test verifica la implementación del optimizador aplicado a un problema de imagen, utilizando el método de optimización `frprmn`.

// funcion objetivo
float fo(float *x, int n){
    float r = 0.5;
    for (int i = 0; i < n; i++){
        r = r + 0.5 * (x[i] - i) * (x[i] - i) / (i + 1);
    }
    return r;
}

// gradiente de la funcion objetivo
void dfo(float *x, float *xi, int n){
    for (int i = 0; i < n ; i++){
        xi[i] = (x[i] - i) / (i + 1);
    }
}
