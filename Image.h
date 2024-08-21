#ifndef IMAGE_H
#define IMAGE_H


#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

class Image{

    public:

        vector<float> ImageArray;
        int tamaño_imagen;
        int tamaño_kernel;

        Image();

        void cargar_image(string filename);
        
        void grabar_image(vector<float> arreglo, string nombreArchivo);

        void set_tamaño_imagen(int tamaño_imagen);

        void set_tamaño_kernel(int tamaño_kernel);

        void printArray();





};

#endif