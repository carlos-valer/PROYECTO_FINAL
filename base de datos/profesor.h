#ifndef PROFESOR_H
#define PROFESOR_H

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include "persona.h"

using namespace std;

class Profesor : Persona{
	
	private :
		string nombres;
		string apellidos;
		int codigo;
		string clave;
		string correo;
		string curso_asignado;
		vector <string> estudios;
		map <int , string > lista_alumnos;
		vector <double> notas;
	
	public :
		Profesor();
		~Profesor();
		
		string get_correo();
		void set_correo(string);
		
		string get_nombres();
		void set_nombres(string);
		
		string get_apellidos();
		void set_apellidos(string);
		
		int get_codigo();
		void set_codigo(int );
		
		string get_clave();
		void set_clave(string);
		
		string get_curso_asignado();
		void set_curso_asignado(string );
		
		vector <string> get_estudios();
		void set_estudios(vector <string> );
		
		void mostrar_lista_alumnos(); 
		void mostrar_datos();
		Profesor *cargar_datos_profesor(int);
		void guardar_cambios(Profesor *);

};


#endif
