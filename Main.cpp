#include <stdlib.h>
#include "Arreglo.h"
#include "Computadora.h"

int main() {
	ArregloDinamico<Computadora> equipo;

	Computadora pc1("Windows", "AMD Ryzen 5", 512, 8);
	Computadora pc2("MacOS", "Intel core i5", 256, 8);
	Computadora pc3("Windows", "AMD Ryzen 7", 512, 16);
	Computadora pc4("Linux", "Intel core i3", 512, 8);
	
	equipo << pc1 << pc2 << pc3 << pc4 << pc1 << pc1 << pc1;
///////////////////////////////////////////////////////////////////////////////
	Computadora pc5("MacOS", "Intel core i5", 256, 8);
	Computadora* pc = equipo.buscar(pc5);

	if (pc != nullptr) {
		std::cout << *pc << std::endl;
	}
	else {
		std::cout << "Computadora inexistente" << std::endl;
	}
///////////////////////////////////////////////////////////////////////////////
	std::cout << "***************************************************" << std::endl; 
	Computadora pc6("Windows", "AMD Ryzen 5", 128, 16);

	ArregloDinamico<Computadora*> ptrs = equipo.buscar_todos(pc6);

	if (ptrs.getCount() > 0) {
		for (size_t i = 0; i < ptrs.getCount(); i++) { 
			Computadora* c = ptrs[i];
			std::cout << *c << std::endl;
		}
	}
	else {
		std::cout << "Sin coincidencias" << std::endl;
	}

	/*Computadora* pc = equipo.buscar(pc5);

	if (pc != nullptr) {
		std::cout << *pc << std::endl;
	}
	else {
		std::cout << "Computadora inexistente" << std::endl;
	}*/

	system("pause");
	return 0;
}