#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <vector>

Sesion::Sesion()
{
	this->Carrito = {};
	int posicionUs = 0;
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

bool Sesion::VerificarUsuario(std::string Nombre, std::string DNI)
{
	for (int i{ 0 }; i < this->NuevoSistema.getsizeUS(); i++) {
		if (this->NuevoSistema.getUsuario(i).getNombre() == Nombre && this->NuevoSistema.getUsuario(i).getDNI() == DNI) 
		{
			this->PosicionUs ++;
			return true;
		}
	}
	return false;
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

		if (this->VerificarUsuario(NombreTemp, DNITemp)) break;
		else
		{

			std::cout << "--------Usuario o Contraseña INCORRECTA-------" << std::endl;
			std::cout << "----------Vuelva a ingresar sus datos---------" << std::endl;
			Sleep(1000);
			system("cls");

		}

	} while (true);

	this->RealizarCompra();
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

		if (this->VerificarUsuario(NombreTemp, DNITemp)) break;
		else
		{

			std::cout << "--------Usuario o Contraseña INCORRECTA-------" << std::endl;
			std::cout << "----------Vuelva a ingresar sus datos---------" << std::endl;
			Sleep(1000);
			system("cls");

		}

	} while (true);
}

void Sesion::RealizarCompra()
{

	char primera_respuesta;

	do
	{
		std::cout << "Buenas, viene a comprar algo? (A.Si / B.No): ";
		std::cin >> primera_respuesta;
	} while ((primera_respuesta != 'A') && (primera_respuesta != 'B'));

	if (primera_respuesta == 'A')
	{
		//productos(primera_Respuesta);
	}

	if (primera_respuesta == 'B')
	{
		std::cout << "Gracias, que tenga un buen dia. \n";
	}
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

	this->Boleta.setCodigo(this->NuevoSistema.getUsuario(this->PosicionUs).getDNI()); //Pone el DNI del cliente como codigo de boleta

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

	std::ifstream archivo("BaseProductos.csv");

	if (!archivo.is_open()) std::cout << "ERROR: No se pudo abrir el archivo Productos" << std::endl;

	int _codigo;
	std::string _codigotemp;
	std::string _Nombre_producto;
	float _precio;
	std::string _preciotemp;
	int cantidad = 0;

	// SSTREAM :: ISTRINGSTREAM(string) >> float/int

	while (archivo.good())
	{
		std::getline(archivo, _codigotemp, ',');
		std::getline(archivo, _Nombre_producto, ',');
		std::getline(archivo, _preciotemp, '\n');

		std::istringstream(_codigotemp) >> _codigo;
		std::istringstream(_preciotemp) >> _precio;

		Producto* Temp = new Producto(_codigo, _Nombre_producto, _precio);


		this->Productos.push_back(*Temp);

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

Usuario SistemaContable::getUsuario(int indice)
{
	return this->Usuarios[indice];
}


int SistemaContable::getsizeUS()
{
	return this->Usuarios.size();
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

Producto::Producto()
{
	
}

Producto::Producto(int Codigo,std::string Nombre,float Precio)
{
	this->Codigo = Codigo;
	this->Nombre = Nombre;
	this->Precio = Precio;
	this->Cantidad = 0;
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