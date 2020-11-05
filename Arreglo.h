#pragma once

#include <iostream>
#include <string>


template <class TYPE>
class ArregloDinamico {
private:
	TYPE* arreglo;
	size_t size;
	size_t count;
	const static size_t MAX = 5;

	void expandir();

public:
	ArregloDinamico();
	~ArregloDinamico();

	void insertar_final(const TYPE&);
	void insertar_inicio(const TYPE&);
	void insertar(const size_t&, const TYPE&);

	void eliminar_final();
	void eliminar_inicio();
	void eliminar(const size_t&);

	/*Búsquedas*/
	TYPE* buscar(const TYPE&);
	ArregloDinamico<TYPE*> buscar_todos(const TYPE&);


	size_t getCount();

	TYPE operator [] (size_t pos) {
		return arreglo[pos];
	}

	friend ArregloDinamico<TYPE>& operator << (ArregloDinamico<TYPE>& arreglo, const TYPE& elemento) {
		arreglo.insertar_final(elemento);

		return arreglo;
	}

};

/*Implementacion*/

template <class TYPE>
ArregloDinamico<TYPE>::ArregloDinamico() : arreglo(new TYPE[MAX]), count(0), size(MAX) {}

template <class TYPE>
ArregloDinamico<TYPE>::~ArregloDinamico() {
	delete[] arreglo;
}

template <class TYPE>
void ArregloDinamico<TYPE>::expandir() {
	TYPE* newArray = new TYPE[size + MAX];

	for (size_t i = 0; i < count; i++) {
		newArray[i] = arreglo[i];
	}

	delete[] arreglo;
	arreglo = newArray;
	size += MAX;
}

template <class TYPE>
size_t ArregloDinamico<TYPE>::getCount() {
	return count;
}

template <class TYPE>
void ArregloDinamico<TYPE>::insertar_final(const TYPE& elemento) {
	if (count == size) {
		expandir();
	}

	arreglo[count] = elemento;
	count++;
}

template <class TYPE>
void ArregloDinamico<TYPE>::insertar_inicio(const TYPE& elemento) {
	if (count == size) {
		expandir();
	}

	for (size_t i = count; i > 0; i--) {
		arreglo[i] = arreglo[i - 1];
	}

	arreglo[0] = elemento;
	count++;
}

template <class TYPE>
void ArregloDinamico<TYPE>::insertar(const size_t& pos, const TYPE& elemento) {
	if (pos >= count) {
		std::cout << "Posicion no valida" << std::endl;
		return;
	}

	if (count == size) {
		expandir();
	}

	for (size_t i = count; i > pos; i--) {
		arreglo[i] = arreglo[i - 1];
	}

	arreglo[pos] = elemento;
	count++;
}

template <class TYPE>
void ArregloDinamico<TYPE>::eliminar_final(){
	if (count == 0) {
		std::cout << "El arreglo se encuentra vacio" << std::endl;
		return;
	}

	count--;
}

template <class TYPE>
void ArregloDinamico<TYPE>::eliminar_inicio() {
	if (count == 0) {
		std::cout << "El arreglo se encuentra vacio" << std::endl;
		return;
	}

	for (size_t i = 0; i < count - 1; i++) {
		arreglo[i] = arreglo[i + 1];
	}

	count--;
}

template <class TYPE>
void ArregloDinamico<TYPE>::eliminar(const size_t& pos) {
	if (count == 0) {
		std::cout << "El arreglo se encuentra vacio" << std::endl;
		return;
	}

	for (size_t i = pos; i < count - 1; i++) {
		arreglo[i] = arreglo[i + 1];
	}

	count--;
}

template <class TYPE>
TYPE* ArregloDinamico<TYPE>::buscar(const TYPE& elemento) {
	for (size_t i = 0; i < count; i++) {
		if (elemento == arreglo[i]) {
			return &arreglo[i];
		}
	}

	return nullptr;
}

template <class TYPE>
ArregloDinamico<TYPE*> ArregloDinamico<TYPE>::buscar_todos(const TYPE& elemento) {
	ArregloDinamico<TYPE*> ptrs;

	for (size_t i = 0; i < count; i++) {
		if (elemento == arreglo[i]) {
			ptrs.insertar_final(&arreglo[i]);
		}
	}

	return ptrs;
}