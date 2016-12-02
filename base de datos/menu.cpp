#include "menu.h"

using namespace std;
void Menu::menu_alumno(){
	cout << "\t ALUMNO" << "\n\n";
	cout << "1) MOSTRAR DATOS" << endl;
	cout << "2) SALIR" << endl;
	cout << "\n\nOPCION : ";
}

void Menu::menu_profesor(){
	cout << "\t PROFESOR" << "\n\n";
	cout << "1) MOSTRAR DATOS" << endl;
	cout << "2) LISTA DE ALUMNOS" << endl;
	cout << "3) SALIR" << endl;
	cout << "\n\nOPCION : ";
}

void Menu::menu_director(){
	cout << "\t DIRECTOR" << "\n\n";
	cout << "1) INSCRIBIR ALUMNO" << endl;
	cout << "2) BUSCAR ALUMNO" << endl;
	cout << "3) CONTRATAR PROFESOR" << endl;
	cout << "4) BUSCAR PROFESOR" << endl;
	cout << "5) SALIR" << endl;
	cout << "\n\nOPCION : ";
}
