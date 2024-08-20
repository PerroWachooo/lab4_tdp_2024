#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"
#include "ImageProcesor.h"

using namespace std;

ImageProcesor::ImageProcesor(){};


vector<float> ImageProcesor::minus(vector<float> I1, vector<float> I2){

    vector<float> result;

    for(int i=0; i < I1.size(); i++){
        result.push_back(I1[i]-I2[i]);
    };
    return result;
};

