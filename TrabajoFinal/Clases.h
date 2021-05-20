#include <iostream>
#include <string.h>

class usuario {
private:
    int DNI;
    char* Nombre = new char[64];
public:
    usuario(int _DNI, char* _Nombre) {
        DNI = _DNI;
        Nombre = _Nombre;
    }
};

class canasta {
private:
    //producto Objetos[];
public:
    canasta() {

    }
};

class producto {
private:
    char Nombre[64];
    char Codigo[8];
public:
};

class perecible : public producto {
private:
    int dias_de_vida;
public:
};

class NoPerecible : public producto {
private:
    char fecha_de_caducidad[10];
public:
};
#pragma once
