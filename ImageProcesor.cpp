#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Image.h"
#include "ImageProcesor.h"

using namespace std;

ImageProcesor::ImageProcesor(){};


vector<float> ImageProcesor::minus(vector<float> i1, vector<float> i2){

    vector<float> result;

    for(int i=0; i < i1.size(); i++){
        result.push_back(i1[i]-i2[i]);
    };
    return result;
};


//m : tamaño kernel
vector<float> ImageProcesor::c(vector<float> image, int m, int tamañoFoto){

    vector<float> output(image.size());

    for(int i =0; i < tamañoFoto; i++){
        for(int j=0; j < tamañoFoto; j++){
            float s = 0;
            for(int ikernel = m*-1; ikernel <= m; ikernel++){
                for(int jkernel = m*-1; jkernel <= m; jkernel++){
                    
                    int imgX = j + jkernel;
                    int imgY = i + ikernel;
                    //Si esta dentro de los limites que sume a S
                    if (imgX >= 0 && imgX < tamañoFoto && imgY >= 0 && imgY < tamañoFoto) {
                        s += image[(j+jkernel)+tamañoFoto*(i+ikernel)];  
                    }
                    else{ //Si no, que lo remplaze por un 0
                        s+=0;
                    }     
                }
            }

            s = s/((2*m+1)*(2*m+1)); // (Sumatoria / tamaño del kernel)
            output[j + tamañoFoto*i] = s;   
        }
    }
    return output;
    
};

void ImageProcesor::printArray_index(vector<float> vector_index, int tamaño_img){
    for (int i = 0; i < tamaño_img; ++i) {
        for (int j = 0; j < tamaño_img; ++j) {
            std::cout << vector_index[i * tamaño_img + j] << " ";
        }
        std::cout << std::endl;
    }

}

