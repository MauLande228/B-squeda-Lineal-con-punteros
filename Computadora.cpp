#include "Computadora.h"

/*Constructores*/
Computadora::Computadora() : os("No aplica"), procesador("No aplica"), almacenamiento(0), ram(0) {}
Computadora::Computadora(const std::string& os, const std::string& procesador, const int& almacenamiento, const int& ram) {
	this->os = os;
	this->procesador = procesador;
	this->almacenamiento = almacenamiento;
	this->ram = ram;
}

/*Setters*/
void Computadora::setOs(const std::string& os) {
	this->os = os;
}

void Computadora::setProcesador(const std::string& procesador) {
	this->procesador = procesador;
}

void Computadora::setAlmacenamiento(const int& almacenamiento) {
	this->almacenamiento = almacenamiento;
}

void Computadora::setRam(const int& ram) {
	this->ram = ram;
}

/*Getters*/
std::string Computadora::getOs() {
	return os;
}

std::string Computadora::getProcesador() {
	return procesador;
}

int Computadora::getAlmacenamiento() {
	return almacenamiento;
}

int Computadora::getRam() {
	return ram;
}