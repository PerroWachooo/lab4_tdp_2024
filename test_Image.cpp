#include "Image.h"

// Este programa prueba la carga de una imagen desde un archivo y la impresión de su contenido.
// Se carga la imagen desde "image.txt" y luego se imprime cada valor en el array de la imagen.

int main(){
    Image imagen;  // Se crea un objeto `Image`
    imagen.cargar_image("image.txt");  // Se carga la imagen desde el archivo "image.txt"
    imagen.printArray();  // Se imprime el contenido del array de la imagen
    imagen.grabar_image(imagen.ImageArray, "salida.txt");
    return 0;
}

// Este test verifica que la imagen se cargue correctamente y que los valores se impriman de manera adecuada.
