#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

#include "Image.h"
#include "Problem.h"
#include "Optimizer.h"
#include "ImageProcesor.h"

using namespace std;

int main(){


// Se declaran variables para uso general
    int option = 1;
    time_t start, end;

    // Se crea un ciclo para que el usuario pueda elegir entre las opciones
    while (option != 2){
         // Se declaran e inicializan variables de posicion y tamanio
      
        string filename;
        ifstream inputFile;


        std::cout << "Seleccione una opción: \n";
        std::cout << "1. Seleccionar Archivo\n";
        std::cout << "2. Salir\n";

        std::cin >> option;

        // Se crea un switch para manejar las opciones
        switch (option){
            case 1:{
                cout << "Nombre de archivo: ";
                cin >> filename;
                cout << "Leyendo archivo " << filename << endl;

                Image img; 
                img.cargar_image(filename);

                Problem problema = Problem(img);
                int N = 256;  // Dimensión de la imagen
                float ftol = 1e-15;  // Tolerancia para el criterio de convergencia
                int max_it = 10;  // Número máximo de iteraciones
                float* p = new float[img.tamaño_arreglo];  // Array para almacenar los parámetros de optimización

                for (int i = 0; i < img.tamaño_arreglo; ++i) {
                    p[i] = 0.0f;
                }
                Optimizer *optimizer = new Optimizer(problema, p, N*N, ftol, max_it);  // Se crea un objeto `Optimizer`
                

                // Se inicia el tiempo
                clock_t start = clock();
                
                cout<<"Se empieza procesa el algoritmo"<<endl;
                optimizer->frprmn();  // Se ejecuta el método de optimización    
               
                // Se termina el tiempo
                clock_t end = clock();
                
                double time = double(end - start) / CLOCKS_PER_SEC;

                    

                //Se imprime el resultado
                for (int i = 0; i < img.tamaño_arreglo; ++i) {
                    cout<< p[i] <<endl;
                }

                img.grabar_image(p,"salida.txt");

                // Se imprime el tiempo de ejecucion
                cout << "\nTiempo de ejecución: " << time << " segundos\n" << endl;
                break;
            
            }
            
            
            
            case 2:{
                //Se quiere salir del programa
                cout << "Saliendo del programa\n";
                break;
            }
           
            
            
            default:
                cout << "Opción no válida\n";
                break;
        }
    }








}