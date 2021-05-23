#include <iostream>
#include <string.h>

class BasedeDatos {
private:
    usuario* Usuarios;
    int Num_usuarios = 100;
public:
    BasedeDatos();

};

class usuario {
private:
    int DNI;
    std::string Nombre;
public:
    usuario(int, std::string);
    void Imprimir() {
        std::cout << "DNI: " << DNI<<"\n";
        std::cout << "NOMBRE: " << Nombre<<std::endl;
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

BasedeDatos::BasedeDatos() {
    Usuarios = new usuario();
    


}

usuario::usuario(int _DNI, std::string _Nombre) {
    DNI = _DNI;
    Nombre = _Nombre;
}
#pragma once
