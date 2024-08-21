#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"


using namespace std;


Image::Image (){};

void Image::set_tamaño_imagen(int tamaño_imagen){

    this->tamaño_imagen = tamaño_imagen;
}

void Image::set_tamaño_kernel(int tamaño_kernel){

    this->tamaño_kernel = tamaño_kernel;
}




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


}


void Image::grabar_image(vector<float> arreglo, string nombreArchivo) {
    
   
    cout << "Ingrese el nombre del archivo para guardar los datos: ";
    getline(std::cin, nombreArchivo);  // Solicita el nombre del archivo al usuario
    
    std::ofstream outFile(nombreArchivo);  // Crea y abre el archivo para escritura

    if (!outFile) {
        cout << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    for (float valor : arreglo) {
        outFile << valor << std::endl;  // Escribe cada elemento del vector en una nueva línea
    }

    outFile.close();  // Cierra el archivo

    cout << "Imagen guardada correctamente en " << nombreArchivo << endl;

}



void Image::printArray(){
    // Imprimir los valores leídos (opcional)
    for (float num : ImageArray) {
        cout << num << endl;
    }
}
