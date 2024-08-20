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

        float* C(Image image, int kerne_size);

        vector<float> minus(vector<float> I1, vector<float> I2);




};





#endif