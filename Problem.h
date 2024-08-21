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

        float* gradiente(vector<float> I, vector<float> I2, int m, int tamaño_img);

        float fo(vector<float> I,vector<float> I2, int m, int tamaño_img);



};


#endif