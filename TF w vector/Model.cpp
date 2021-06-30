#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

Sesion::Sesion()
{
	this->Carrito = {};
}

void Sesion::Menu()
{
	
	int temp;
	std::cout << "Desea: \n" << "1. Iniciar sesion \n" << "2. Crear nuevo usuario \n" << "3. Salir \n";
	std::cin >> temp;
	switch (temp)
	{
	case 1:
		this->IniciarSesion();
		break;
	case 2:
		this->CrearUsuario();
		break;
	case 3:
		std::cout << "\n\n\n              Gracias por comprar en GRUPO 5 STORE          \n";
		break;
	default:
		break;
	}


}

void Sesion::IniciarSesion()
{
	std::string NombreTemp;
	std::string DNITemp;

	do {
		std::cout << "Ingrese su Usuario: " << std::endl;
		std::getline(std::cin, NombreTemp);
		std::cout << "Ingrese su Contraseña: " << std::endl;
		std::getline(std::cin, DNITemp);

		if (this->NuevoSistema.VerificarUsuario(NombreTemp, DNITemp)) ;
		else
		{

			std::cout << "--------Usuario o Contraseña INCORRECTA-------" << std::endl;
			std::cout << "----------Vuelva a ingresar sus datos---------" << std::endl;
			Sleep(1000);
			system("cls");

		}

	} while (true);
}

void Sesion::CrearUsuario()
{

	std::string NombreTemp;
	std::string DNITemp;

	do {
		std::cout << "Ingrese su Usuario: " << std::endl;
		std::getline(std::cin, NombreTemp);
		std::cout << "Ingrese su Contraseña: " << std::endl;
		std::getline(std::cin, DNITemp);

		if (this->NuevoSistema.VerificarUsuario(NombreTemp, DNITemp)) break;
		else
		{

			std::cout << "--------Usuario o Contraseña INCORRECTA-------" << std::endl;
			std::cout << "----------Vuelva a ingresar sus datos---------" << std::endl;
			Sleep(1000);
			system("cls");

		}

	} while (true);
}

bool SistemaContable::VerificarUsuario(std::string Nombre, std::string DNI)
{
	for (int i{ 0 }; i < this->Usuarios.size(); i++) {
		if (this->Usuarios[i].getNombre() == Nombre && this->Usuarios[i].getDNI() == DNI) return true;
	}
	return false;
}

Sesion::~Sesion()
{

}


float Sesion::CalcularPrecioFinal()
{
	float precioTemp = 0;
	for (int i{ 0 }; i < this->Carrito.size(); i++)
	{
		precioTemp += this->Carrito[i].getPrecio();
	}

	return precioTemp;
}

void Sesion::CrearBoleta()
{
	//////////////////////////////this->Boleta.setCodigo = Por poner cuadno tenga un usuario en sesion
}

SistemaContable::SistemaContable() 
{

	this->Usuarios = {};
	this->Productos = {};

	std::ifstream archivo("BaseUsuarios.csv");

	if (!archivo.is_open()) std::cout << "ERROR: No se pudo abrir el archivo" << std::endl;

	std::string _Nombre;
	std::string _DNI;

	while (archivo.good())
	{
		std::getline(archivo, _Nombre , ',');
		std::getline(archivo, _DNI , '\n');

		Usuario *Temp = new Usuario(_DNI,_Nombre);

		this->Usuarios.push_back(*Temp);

		delete[] Temp;
	}

	archivo.close();

}

void SistemaContable::AddUsuario(std::string DNI, std::string Nombre)
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

Usuario::Usuario(std::string DNI, std::string Nombre)
{
	this->DNI = DNI;
	this->Nombre = Nombre;
}

std::string Usuario::getNombre()
{
	return this->Nombre;
}
std::string Usuario::getDNI()
{
	return this->DNI;
}

Usuario::~Usuario()
{

}

void Sesion::CrearBoleta()
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

float Producto::getPrecio()
{
	return this->Precio;
}

Boleta::Boleta() 
{
	this->codigo = "00000000";
}

Boleta::~Boleta()
{

}

void Boleta::setCodigo(std::string Codigo) 
{
	this->codigo = Codigo;
}

void Boleta::setPrecioFinal(float PrecioFinal)
{
	this->PrecioFinal = PrecioFinal;
}