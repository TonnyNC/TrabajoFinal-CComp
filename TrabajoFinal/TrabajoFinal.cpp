
// TrabajoFinal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Clases.h"



int main()
{
    int DNI1 = 72930619;
    std::string nombre;

    getline(std::cin, nombre);
    
    usuario Tonny(72930619, nombre);
    std::string Nombre;
    Tonny.Imprimir();
    
}
