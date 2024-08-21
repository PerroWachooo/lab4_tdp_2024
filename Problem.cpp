#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"
#include "ImageProcesor.h"
#include "Problem.h"


Problem::Problem(){};

Problem::Problem(Image Iobs){

    this->Iobs=Iobs;
}



float* Problem::gradiente(vector<float> I, vector<float> I2, int m, int tamaño_img){
    ImageProcesor p;

    vector<float> x = p.c(p.minus(p.c(I, m, tamaño_img),I2), m, tamaño_img);

    float* result = new float[x.size()];
    std::copy(x.begin(), x.end(), result);
    this->dfunc=result;

    return result;


}


float Problem::fo(vector<float> I, vector<float> I2,int m, int tamaño_img){
    ImageProcesor p;
    float sumatoria = 0;
    vector<float> conv = p.c(I,m,tamaño_img);

    for(int i=0; i<tamaño_img;i++){
        for(int j=0; j<tamaño_img;j++){
            float x = conv[j + (tamaño_img-1)*i] - I2[j + (tamaño_img-1)*i];
            
            sumatoria += x*x;
        }
    }
    
    sumatoria = sumatoria * 0.5;
    this->func=sumatoria;
    return (sumatoria);
}