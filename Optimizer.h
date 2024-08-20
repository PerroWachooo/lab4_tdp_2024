#ifndef OPTIMIZER_H
#define OPTIMIZER_H

// Includes
#include <iostream>
#include <math.h>

// Defines
#define FREEALL delete[] xi; delete[] h; delete[] g;
#define EPS 1.0e-12
#define TOL 3.0e-8

// Defines para el mnbrak
#define GOLD 1.618033988749895
#define GLIMIT 100.0
#define TINY 1.0e-20
#define SHFT(a,b,c,d) (a)=(b);(b)=(c);(c)=(d);

// Defines del nrutils (para mnbrak)
static int iminarg1,iminarg2;
#define SIGN(a,b) ((b) >= 0.0 ? fabs(a) : -fabs(a))
static float maxarg1,maxarg2;
#define FMAX(a,b) (maxarg1=(a),maxarg2=(b),(maxarg1) > (maxarg2) ?\
        (maxarg1) : (maxarg2))

// Defines para brent
#define ITMAX 100
#define CGOLD 0.3819660112501052
#define ZEPS 1.0e-15

using namespace std;

/*
    Clase Optimizer que se encarga de procesar todo el algoritmo de optimizacion de la funcion objetivo.
    Este algoritmo se basa en el metodo del gradiente conjugado con actualización de Fletcher-Reeves.
    El gradiente se calcula con las imagenes de la funcion objetivo y un kernel de la funcion objetivo.
    La idea principal es que el método FRPRMN utiliza linmin, el cual a su vez, utiliza mnbrak y brent.
    Por otra parte, mnbrak y brent utilizan un wrapper llamado f1dim.
    * linmin: es un método de búsqueda de la minima de una función.
    * mnbrak: es un método de acotamiento de un intervalo minimo.
    * brent: es un método que encuentra el minimo de una función con el método de brent.
    * f1dim: wrapper que representa la funcion objetivo.
*/

class Optimizer {
public:
    // require Objective function, initial parameters p (static), and tolerance
    Optimizer(float (*f)(float*,int), void (*df)(float*,float*,int), float* p,int n, float ftol, int max_it); // constructor
    ~Optimizer(); // destructor
    void frprmn(); // función que se encarga de procesar el algoritmo del gradiente conjugado
    void linmin(float* xi); // función que se encarga de buscar la minima de una función
    void mnbrak(float* ax, float* bx, float* cx, float* fa, float* fb, float* fc); // función que se encarga de buscar el intervalo minimo
    float f1dim(float x); // wrapper
    float brent(float ax, float bx, float cx, float tol, float *xmin); // método de brent
    float * getParameter(); // retorna p
private:
    float *p; // vector de parametros la función
    float *xicom; // copia de xi
    float *pcom; // copia de p
    float fret; // error de la función
    int n; // tamaño del vector
    float ftol; // tolerancia
    int max_it; // numero maximo de iteraciones
    int iter; // numero de iteraciones
    float fp; // error del gradiente
    float (*func)(float*,int); // función objetivo
    void (*dfunc)(float*,float*,int); // gradiente de la función objetivo
};
#endif // OPTIMIZER_H