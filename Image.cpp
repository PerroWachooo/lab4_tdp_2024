#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"


using namespace std;


Image::Image (){};


void Image::cargar_image(string filenmae){

    ifstream inputFile;

    inputFile.open(filenmae);
    if (!inputFile) {
        std::cout << "No se pudo abrir el archivo.";
        return;
    }

    float value;
    while (inputFile >> value) {
        ImageArray.push_back(value);
    }

    inputFile.close();

    // Imprimir los valores leídos (opcional)
    //printArray();

}


void Image::printArray(){
    // Imprimir los valores leídos (opcional)
    for (float num : ImageArray) {
        cout << num << endl;
    }
}
