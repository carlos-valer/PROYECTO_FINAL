#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
#include <vector>
#include "rector.h"

using namespace std;
class Alumno : public Rector{
	private:
		map< string,vector<double> > cursos;
		
	
	public:
		Alumno();
		Alumno(char *);
		~Alumno();

		void dar_codigo(char *);
		void dar_nombreApellido(string);
		void mostrar_datos();
		void mostrar_cursos();
};
#endif
