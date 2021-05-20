
// TrabajoFinal.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string.h>
#include "Clases.h"



int main()
{
    int DNI1 = 72930619;
    char nombre[] = {'t','o','n','n','y','\0'};
    
    std::cout << "DNI: " << DNI1 << "\n";
    std::cout << "Tamanho: " << sizeof(DNI1) << "\n";
    std::cin >> DNI1;
    usuario Tonny(72930619, nombre);
    std::string Nombre;
    Tonny.Imprimir();
    
}
