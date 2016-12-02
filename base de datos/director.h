#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <iostream>
#include "memento.h"
#include "persona.h"
#include "profesor.h"


class Director : public Persona{
	private :
		string nombres;
		string apellidos;
		int codigo;
		string clave;
		vector <string> estudios;
	
	public :
		Director();
		~Director();
		string get_clave();
		
		void mostrar_datos();
		void set_clave(string);
		void agregar_alumno();
		void agregar_profesor();
		void buscar_alumno(int);
		void buscar_alumno(string);
		void buscar_profesor(int);
		void buscar_profesor(string);
		bool verificar_codigo(int, string);
		
};

#endif
