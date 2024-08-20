#ifndef IMAGEPROCESOR_H
#define IMAGEPROCESOR_H


#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"



class ImageProcesor {


    public:

        ImageProcesor();


        vector<float> minus(vector<float> i1, vector<float> i2);

        vector<float> c(vector<float> image, int m, int tamañoFoto);

        void printArray_index(vector<float> vector_index, int tamaño_img);



};





#endif