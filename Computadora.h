#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Computadora {
private:
	std::string os;
	std::string procesador;
	int almacenamiento;
	int ram;

public:
	/*Constructores*/
	Computadora();
	Computadora(const std::string&, const std::string&, const int&, const int&);

	/*Setters*/
	void setOs(const std::string&);
	void setProcesador(const std::string&);
	void setAlmacenamiento(const int&);
	void setRam(const int&);

	/*Getters*/
	std::string getOs();
	std::string getProcesador();
	int getAlmacenamiento();
	int getRam();


	/*Overloads*/
	friend std::ostream& operator << (std::ostream& out, Computadora& c) {

		out << std::left;
		out << std::setw(20) << c.os;
		out << std::setw(20) << c.procesador;
		out << std::setw(20) << c.almacenamiento;
		out << std::setw(20) << c.ram;
		out << std::endl;

		return out;
	}

	friend std::istream& operator >> (std::istream& in, Computadora& c) {

		std::cout << "Sistema operativo: ";
		std::getline(std::cin, c.os);

		std::cout << "Procesador: ";
		std::getline(std::cin, c.procesador);

		std::cout << "Almacenamiento: ";
		std::cin >> c.almacenamiento;

		std::cout << "RAM: ";
		std::cin >> c.ram;

		return in;
	}

	bool operator == (const Computadora& pc) const{
		return procesador == pc.procesador;
	}
};