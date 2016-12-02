#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <vector>
using namespace std;
class Persona{
	protected :
		static char extencion[];
		
		vector <int> codigo_alumno_modificar;
		
		
	public :
		
		Persona();
		~Persona();
		virtual void mostrar_datos()=0;
};

#endif
