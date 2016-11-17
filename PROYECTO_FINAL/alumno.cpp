#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include "alumno.h"
//#include "rector.h"
using namespace std;

//FALTA CARRERA

Alumno::Alumno(){}

Alumno::Alumno(char *cod){
	strcpy(codigo,cod);
}


Alumno::~Alumno(){}

static int convert(string str){
	int n=0;
	
	for(int i=0;i<str.size();i++){
		n+=pow(10,str.size()-1-i)*(str[i]-'0');
	}
	return n;
}
//------------------------------------------------------
void Alumno::mostrar_datos(){
	system("cls");
	string linea1,linea2;
	int index;
	
	ifstream salida;
	
	salida.open(codigo,ios::in);
	getline(salida,linea1);
	cout<<"\t\tNOMBRES Y APELLIDOS = "<<linea1<<endl;
	getline(salida,linea2);
	cout<<"\t\tCODIGO = "<<linea2<<endl;
}

//------------------------------------------------------
void Alumno::mostrar_cursos(){
	system("cls");
	string linea,num;
	int n_cursos=0,index;
	double prom=0.0;
	ifstream salida;
	salida.open(codigo,ios::in);
	
	while(!salida.eof()){
		getline(salida,linea);
		if(linea.find("-")==0){
			
			index=linea.find("=");
			num=linea.substr(index+2,2);
			prom+=convert(num);
			n_cursos++;
//			cout<<"CURSO\t\tNOTA"<<"\n\n";
			cout<<"\t\t"<<linea.substr(2)<<endl;  
//convertir a mayusculas los nombres de los cursos
		}
	}
	
	cout<<"\n\n\t\t-------------------------------------"<<endl;
	prom/=n_cursos;
	total_cursos=n_cursos;
	cout<<"\n\t\tCANTIDAD DE CURSOS = "<<total_cursos<<endl;
	cout<<"\t\tPROMEDIO DE NOTAS = "<<prom;
}
//------------------------------------------------------
void Alumno::dar_nombreApellido(string nom){
	nombre_apellido=nom;
}


//------------------------------------------------------
void Alumno::dar_codigo(char *cod){
	strcpy(codigo,cod);
}


