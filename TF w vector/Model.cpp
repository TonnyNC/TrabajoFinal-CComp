#include <iostream>
#include <fstream>
#include <vector>

SistemaContable::SistemaContable() 
{

}

void SistemaContable::AddUsuario(int DNI, std::string Nombre)
{
	Usuario nUser(DNI, Nombre);
	this->Usuarios.push_back(nUser);
}

SistemaContable::~SistemaContable()
{

}

Usuario::Usuario()
{
	
}

Usuario::Usuario(int DNI, std::string Nombre)
{
	this->DNI = DNI;
	this->Nombre = Nombre;
	this->Carrito = {};
}

Usuario::~Usuario()
{

}

void Usuario::CrearBoleta()
{

}

Producto::Producto()
{
	std::ifstream Productos;
	Productos.open("BaseProductos.csv");
}

Producto::Producto(int Cantidad)
{
	this->Precio *= Cantidad;
}

Producto::~Producto()
{

}