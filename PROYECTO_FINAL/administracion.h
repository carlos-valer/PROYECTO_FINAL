#ifndef SECRETARIO_H
#define SECRETARIO_H
//#include "rector.h"
#include "alumno.h"

class Administracion: public Rector,Alumno{
	
	private :
		vector<Alumno>alumnos;
	
	public :
		Administracion();
		~Administracion();
		
//		void mostrar_datos();
		void registrar_profesor();
		void registrar_alumno(Alumno);
		void mostrar_profesores();
		void mostrar_alumnos();
		

};

#endif
