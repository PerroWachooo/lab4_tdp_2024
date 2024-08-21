#include <vector>

#include "Image.h"
#include "ImageProcesor.h"

using namespace std;



int main(){
    ImageProcesor proccesor;
    Image imagen1;
    Image imagen2;

    imagen1.cargar_image("image.txt");
    imagen2.cargar_image("image.txt");


    vector<float> salida = proccesor.minus(imagen1.ImageArray, imagen2.ImageArray);

    // // Imprimir los valores lde la salida, debaria ser 0
    // for (float num : salida) {
    //     cout << num << endl;
    // }

    vector<float> imagen3 = {
        1, 2, 3, 
        5, 4, 3, 
        1, 2, 3, 
    };

    
    int tamaño_img3 = 256;
    int tamaño_kernel=1;

    vector<float> salida_conv = proccesor.c(imagen2.ImageArray,tamaño_kernel,tamaño_img3);

    proccesor.printArray_index(salida_conv,tamaño_img3);

    for (int i = 0; i < 256; i++) {
        std::cout << "I: " << imagen2.ImageArray[i] << "Conv: " << salida_conv[i] << std::endl;
    }




}
