#include "director.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

Director::Director()
{
	nombres="IVAN JESUS";
	apellidos="TUPAC VALDIVIA";
	codigo=999;
	clave="9999";
	estudios.push_back("Doctor en Ingeniería Electrica, Pontificia Universidade Católica do Rio de Janeiro");
	estudios.push_back("Magíster en Ingeniería Eléctrica, Pontifícia Universidade Católica do Rio de Janeiro");
	estudios.push_back("Bachiller en Ingeniería Electrónica, Universidad Nacional de San Agustín");
	
	ofstream entrada;
	entrada.open("codigo_clave.txt",ios::out);
	entrada << codigo<< " "<<clave<<endl;
}

void Director::mostrar_datos()
{
	cout << "APELLIDOS : "<<apellidos<<endl;
	cout << "NOMBRES : "<<nombres << endl;
	cout << "CODIGO : "<<codigo<< endl;
	cout << "ESTUDIOS : " << endl;
	for(int i=0; i<estudios.size() ;i++){
		cout <<"- "<<estudios[i]<<endl;
	}
}
string Director::get_clave()
{
	return clave;
}
void Director::set_clave(string clave)
{
	this->clave = clave;
}

void Director::agregar_alumno()
{
	Memento memento;
	string _nombres, _apellidos, _carrera, _clave; 
	int _codigo;
	map <string, double> curso_nota;
	
	Alumno *alumno = new Alumno();
	
	cout << "APELLIDOS : ";
	cin.ignore();
	getline(cin, _apellidos);
	cout << "NOMBRES : ";
	getline(cin, _nombres);
	cout << "CARRERA : ";
	getline(cin, _carrera);
	cout << "CLAVE : ";
	getline(cin, _clave);
	cout << "CODIGO GENERADO : ";
	if(memento.cargar_codigos().empty()){
		_codigo = 101/*100 + rand() % (201-100)*/;
	}
	else{
		_codigo = 101 /*+ rand() % (201-100)*/;
		int i=0;
		while(i < memento.cargar_codigos().size()){
			if(memento.cargar_codigos()[i]==_codigo){
				_codigo++ /*=*/ /*100 + rand() % (201-100)*/;
				i=0;
			}
			else{i++;}
		}
	}

	cout << _codigo;
	vector <string> cursos;
	cursos.push_back("COMUNICACION");
	cursos.push_back("ESTRUCTURAS DISCRETAS");
	cursos.push_back("IVU");
	cursos.push_back("MATEMATICA");
	cursos.push_back("MET. DEL ESTUDIO");
	cursos.push_back("PROGRAMACION");
	
	cout << "SELECCIONE CURSOS A MATRICULARSE: "<<endl;
	string opcion;
	do{
		int rpta;
		for(int i=0; i<cursos.size() ;i++){
			cout<<i+1<<") "<<cursos[i]<<endl;
		}
		cout << endl;
		cin >> rpta;
		
		curso_nota[cursos[rpta-1]]=0.0;
		cursos.erase(cursos.begin()+(rpta-1));
		cout <<"\n\nSALIR?(s/n) ";
		cin >>opcion;
	}while(!cursos.empty() || opcion=="s");
	
	alumno->set_apellidos(_apellidos);
	alumno->set_nombres(_nombres);
	alumno->set_codigo(_codigo);
	alumno->set_clave(_clave);
	alumno->set_curso_nota(curso_nota);
	
	memento.guardar_alumno(alumno);
}
void Director::agregar_profesor(){
	Memento memento;
	string _nombres, _apellidos, _clave, _correo, _curso_asignado;
	int _codigo;
	vector <string> _estudios;
	
	cout << "APELLIDOS : ";
	getline(cin, _apellidos);
	cout << "NOMBRES : ";
	getline(cin, _nombres);
	cout << "CORREO : ";
	getline(cin, _correo);
	cout << "CLAVE : ";
	getline(cin, _clave);
	cout << "CURSO ASIGNADO : ";
	getline(cin, _curso_asignado);
	
	cout << "ESTUDIOS : "<<endl;
	while(true){
		string linea;
		cout << "- ";
		if(linea =="exit"){
			break;
		}
		else{ getline(cin, linea); _estudios.push_back(linea);cout <<endl;}
	}
	
	if(memento.cargar_codigos().empty()){
		_codigo = 300 + rand() % (401-300);
	}
	else{
		_codigo = 300 + rand() % (401-300);
		int i=0;
		while(i < memento.cargar_codigos().size()){
			if(memento.cargar_codigos()[i]==_codigo){
				_codigo = 300 + rand() % (401-300);
				i=0;
			}
			else{i++;}
		}
	}
	
	Profesor* profesor;
	
	profesor->set_apellidos(_apellidos);
	profesor->set_nombres(_nombres);
	profesor->set_codigo(_codigo);
	profesor->set_clave(_clave);
	profesor->set_curso_asignado(_curso_asignado);
	profesor->set_estudios(_estudios);
	profesor->set_correo(_correo);
	
	memento.guardar_profesor(profesor);
}

void Director::buscar_alumno(int _codigo){
	char cod[30];
	Memento memento;
	memento.cargar_alumnos();
	sprintf(cod, "%d", _codigo);
	for(int i=0 ; i<memento.cargar_alumnos().size() ;i++){
		int index = memento.cargar_alumnos()[i].find(cod);
		if(index >=0){
			cout << memento.cargar_alumnos()[i]<<endl;
		}
	}
}

void Director::buscar_alumno(string _nombre){
	Memento memento;
	memento.cargar_alumnos();

	for(int i=0 ; i<memento.cargar_alumnos().size() ;i++){
		int index = memento.cargar_alumnos()[i].find(_nombre);
		if(index >=0){
			cout << memento.cargar_alumnos()[i]<<endl;
		}
	}
}

void Director::buscar_profesor(int _codigo){
	char cod[30];
	Memento memento;
	memento.cargar_profesores();
	sprintf(cod, "%d", _codigo);
	for(int i=0 ; i<memento.cargar_profesores().size() ;i++){
		int index = memento.cargar_profesores()[i].find(cod);
		if(index >=0){
			cout << memento.cargar_profesores()[i]<<endl;
		}
	}
}

void Director::buscar_profesor(string _nombre)
{
	Memento memento;
	memento.cargar_profesores();

	for(int i=0 ; i<memento.cargar_profesores().size() ;i++){
		int index = memento.cargar_profesores()[i].find(_nombre);
		if(index >=0){
			cout << memento.cargar_profesores()[i]<<endl;
		}
	}
}

bool Director::verificar_codigo(int codigo, string clave)
{
	ifstream salida;
	salida.open("codigo_clave.txt",ios::in);
	
	if(salida.fail()){ return false;}
	else{
		int _codigo;
		string _clave;
		
		salida >> _codigo;
		while(!salida.eof()){
			salida >> _clave;
			
			if(_codigo == codigo && _clave ==clave){ return true;}
			
			else{return false;}
			salida >> _codigo;
		}
	}
}
