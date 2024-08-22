#ifndef PROBLEM_H
#define PROBLEM_H


#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"
#include "ImageProcesor.h"



using namespace std;


class Problem{

    public:

        float func;

        float* dfunc;

        Problem();

        Problem(Image obs);

        Image Iobs;

        float* gradiente(float* I, float* I2, int m, int tamaño_img, int tamañoArray);

        float fo(float* I, float* I2, int m, int tamaño_img, int tamañoArray);



};


#endif