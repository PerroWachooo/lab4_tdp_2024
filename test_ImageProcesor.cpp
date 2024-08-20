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

    // Imprimir los valores lde la salida, debaria ser 0
    for (float num : salida) {
        cout << num << endl;
    }

}
