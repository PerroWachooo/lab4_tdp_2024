#include <vector>
#include "Problem.h"
#include "Image.h"
#include "ImageProcesor.h"

using namespace std;


int main(){


    Image imagen, Iobs;
    imagen.cargar_image("image.txt");
    Iobs.cargar_image("image.txt");

    Problem problema = Problem(Iobs);

    float* grad = problema.gradiente(imagen.ImageArray, imagen.ImageArray, 1, imagen.tamaño_imagen, imagen.tamaño_arreglo);

    float foo = problema.fo(imagen.ImageArray, imagen.ImageArray, 2 ,imagen.tamaño_imagen, imagen.tamaño_arreglo);

    for (int i = 0; i < imagen.tamaño_arreglo; i++) {
    std::cout << "grad[" << i << "] = " << grad[i] << "I: "<< imagen.ImageArray[i]<<::endl;
    }

    cout<<"foo: "<< foo <<endl;

    //imagen.printArray();
        
    
}