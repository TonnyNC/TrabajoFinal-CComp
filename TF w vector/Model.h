#pragma once
#ifndef Clases_H
#define Clases_H
#include <iostream>
#include <string>
#include <vector>
#include "Model.cpp"


class SistemaContable
{
private:
	std::vector<Usuario> Usuarios;
	std::vector<Producto> Productos;
public:
	SistemaContable();
	~SistemaContable();
	void AddUsuario(int, std::string);
};


class Usuario
{
private:
	int DNI;
	std::string Nombre;
	std::vector<Producto> Carrito;
public:
	Usuario();
	Usuario(int, std::string);
	~Usuario();
	void CrearBoleta();
};

class Producto
{
private:
	int Codigo;
	float Precio;
public:
	Producto();
	Producto(int);
	~Producto();
};
#endif