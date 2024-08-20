#include <iostream>
#include "Optimizer.h"
using namespace std;



// funcion objetivo
float fo(float *x, int n){
    float r = 0.5;
    for (int i = 0; i < n; i++){
        r = r + 0.5 * (x[i] - i) * (x[i] - i) / (i + 1);
    }
    return r;
} 

// gradiente de la funcion objetivo
void dfo(float *x, float *xi, int n){
    for (int i = 0; i < n ; i++){
        xi[i] = (x[i] - i) / (i + 1);
    }
}

int main(){
    int N = 256;
    int a = 0;
    float ftol = 1e-15;
    int max_it = 10000;
    float *x = new float[N * N];
    for(int i = 0; i < N*N; i++){
        x[i] = 0;
    }
    Optimizer *optimizer = new Optimizer(&fo, &dfo, x, N*N, ftol, max_it); // Constructor optimizer
    optimizer->frprmn();
    for(int i = 0; i < N*N; i++){
        cout << x[i] << endl;
    }
}