#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <map>
#include "persona.h"

using namespace std;

class Alumno : public Persona{

	private :
		string nombres;
		string apellidos;
		int codigo;
		string clave;
		
		int nro_cursos;
		string carrera;
		map <string, double> curso_nota;
		
	public :

		Alumno();
		~Alumno();
		
		string get_nombres();
		void set_nombres(string);
		
		string get_apellidos();
		void set_apellidos(string);
		
		int get_codigo();
		void set_codigo(int );
		
		string get_clave();
		void set_clave(string);
		
		string get_carrera();
		void set_carrera(string );
		
		int get_nro_cursos();
		
		map <string, double> get_curso_nota();
		void set_curso_nota(map <string, double> );
		
		void mostrar_datos();
		Alumno * cargar_datos(int);
		void guardar_cambios(Alumno *);
		
};

#endif
