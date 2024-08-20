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


      
        Image Iobs;

        float* gradiente(Image I, int m, int tamaño_img);

        float fo(Image I, int m, int tamaño_img);



};


#endif