#ifndef MEMENTO_H
#define MEMENTO_H

#include "persona.h"
#include "alumno.h"
#include "profesor.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <map>
//
//// VER SI RECIBE FUNCIONES FRIEND
////friend class en alumno.h
//
//
using namespace std;
//
class Memento 
{
	private :
		char extencion[10]=".txt";
		vector <string> alumnos;
		vector <string> profesores;
		vector <int >codigos;
		
		public :			
			void guardar_alumno(Alumno *);
			vector <string> cargar_alumnos();
			vector <int> cargar_codigos();
			void guardar_profesor(Profesor *);
			vector <string> cargar_profesores();
};

#endif
