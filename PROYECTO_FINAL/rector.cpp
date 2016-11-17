#include <iostream>
#include <fstream>
#include "rector.h"

using namespace std;

int Rector::total_alumnos=0;

Rector::Rector(){}

bool Rector::verificar_codigo(int cod){
	ifstream salida;
	salida.open("lista_codigos.txt",ios::in);
	
}

void Rector::almacenar_codigo(int cod){
	ofstream entrada;
	entrada.open("lista_codigos.txt",ios::out|ios::app);
	
	entrada <<cod;
	entrada.close();
}

//bool Rector::acceso(string cod,string clav){
//	if(codigo==cod && clave==clav){
//		return true;
//	}
//	return false;
//}
//
////alumno {100,200}
////profesor{400,500}
////secretario{700,800}
////rector{900}
//
////nombres ,apellidos, direccion, correo, curso
//template <class T>
//void Rector::get_datos(Alumno tipo){
//	if(tipo.codigo>100 && tipo.codigo<200){
//		cout<< tipo.nombres_apellidos <<endl;
//		cout<< tipo.direccion <<endl;
//		cout<< tipo.correo<<endl;
//		cout<< tipo.carrera <<endl;
//		cursos
//	}
//}
//
//
