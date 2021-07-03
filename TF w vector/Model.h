#pragma once
#ifndef Clases_H
#define Clases_H
#include <iostream>
#include <string>
#include <vector>
#include "Model.cpp"

class Sesion //funcionalidades para la interaccion con el usuario
{
private:
	std::vector<Producto> Carrito;
	Boleta Boleta;
	SistemaContable NuevoSistema;
	int PosicionUs;
public:
	Sesion();
	~Sesion();
	void Menu();
	void IniciarSesion();
	bool VerificarUsuario(std::string, std::string);
	void CrearUsuario();
	void RealizarCompra();
	float CalcularPrecioFinal();
	void CrearBoleta();
	//funcion carrito_comprar_carne...etc
};

class SistemaContable //Guardar y grabar cosas en archivo
{
private:
	std::vector<Usuario> Usuarios;
	std::vector<Producto> Productos;
public:
	SistemaContable();
	~SistemaContable();
	void AddUsuario(std::string, std::string);
	
	Usuario getUsuario(int);
	int getsizeUS();
	Producto getProducto(int);
};

class Usuario
{
private:
	std::string DNI;
	std::string Nombre;
public:
	Usuario();
	Usuario(std::string, std::string);
	std::string getNombre();
	std::string getDNI();
	~Usuario();
};

class Producto
{
private:
	int Codigo;
	std::string Nombre;
	float Precio;
	int Cantidad;
public:
	Producto();
	Producto(int,std::string,float);
	~Producto();
	float getPrecio();
};

class Boleta
{
private:
	std::string codigo;
	float PrecioFinal;
public:
	Boleta();
	~Boleta();
	void setCodigo(std::string);
	void setPrecioFinal(float);
	//guardar en archivo binario
};

#endif