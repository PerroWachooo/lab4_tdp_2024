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



float* Problem::gradiente(float* I, float* I2, int m, int tamaño_img, int tamañoArray){
    ImageProcesor p;
    float* x = new float[tamaño_img];

    x = p.c(p.minus(p.c(I, m, tamaño_img,tamañoArray),I2, tamañoArray), m, tamaño_img, tamañoArray);


    this->dfunc=x;

    return x;


}


float Problem::fo(float* I, float* I2, int m, int tamaño_img, int tamañoArray){
    ImageProcesor p;
    float sumatoria = 0;
    float* conv = new float[tamañoArray];
    
    conv = p.c(I,m,tamaño_img, tamañoArray);

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