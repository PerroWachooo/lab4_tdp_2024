#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"
#include "ImageProcesor.h"
#include "Problem.h"


float* Problem::gradiente(Image I, int m, int tamaño_img){
    ImageProcesor p;

    vector<float> x = p.c(p.minus(p.c(I.ImageArray, m, tamaño_img),Iobs.ImageArray), m, tamaño_img);

    float* result = new float[x.size()];
    std::copy(x.begin(), x.end(), result);

    return result;


}


float Problem::fo(Image I, int m, int tamaño_img){
    ImageProcesor p;
    float sumatoria = 0;
    vector<float> conv = p.c(I.ImageArray,m,tamaño_img);

    for(int i=0; i<tamaño_img;i++){
        for(int j=0; j<tamaño_img;j++){
            float x = conv[j + (tamaño_img-1)*i] - Iobs.ImageArray[j + (tamaño_img-1)*i];
            
            sumatoria += x*x;
        }
    }

    return (sumatoria = 0,5 * sumatoria);

}