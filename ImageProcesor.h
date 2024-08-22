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


        float* minus(float* i1, float* i2, int tamaño_img);

        float* c(float* image, int m, int tamañoFoto, int tamañoArray);

        void printArray_index(float* vector_index, int tamaño_img);



};





#endif