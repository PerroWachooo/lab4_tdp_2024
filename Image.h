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

        Image();

        void cargar_image(string filename);

        void grabar_image(vector<float> arreglo, string nombreArchivo);

        void printArray();





};

#endif