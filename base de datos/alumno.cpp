#include "alumno.h"
#include <map>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
Alumno::Alumno(){
	nombres = "";
	apellidos = "";
	codigo = 0;
	clave = 111;
	nro_cursos = 0;
	carrera = "";
}
Alumno::~Alumno(){}

//void cambiar_clave(Alumno *alumno, int clave){
//	alumno->clave = clave;
//}


string Alumno::get_nombres()
{
	return nombres;
}
void Alumno::set_nombres(string nombres)
{
	this->nombres=nombres;
}

string Alumno::get_apellidos()
{
	return apellidos;
}
void Alumno::set_apellidos(string apellidos)
{
	this->apellidos=apellidos;
}

int Alumno::get_codigo()
{
	return codigo;
}
void Alumno::set_codigo(int codigo)
{
	this->codigo=codigo;
}

string Alumno::get_clave()
{
	return clave;
}
void Alumno::set_clave(string clave)
{
	this->clave=clave;
}

string Alumno::get_carrera()
{
	return carrera;
}
void Alumno::set_carrera(string carrera)
{
	this->carrera=carrera;
}

int Alumno::get_nro_cursos(){
	return curso_nota.size();
}

map <string, double> Alumno::get_curso_nota()
{
	return curso_nota;
}
void Alumno::set_curso_nota(map <string, double>curso_nota)
{
	this->curso_nota=curso_nota;
}

void Alumno::mostrar_datos()
{
	
	cout << "APELLIDOS : "<<apellidos<<endl;
	cout << "NOMBRES : "<<nombres<<endl;
	cout << "CARRERA : "<<carrera<<endl;
	cout << "\nCURSO\t\t\tNOTA"<<endl;
	
	map <string, double >lista=curso_nota;
	map <string, double >::iterator it;
	
	for(it=lista.begin(); it!=lista.end() ;it++){
		cout<<it->first<<"\t\t"<<it->second<<endl;
	}
}
Alumno *Alumno::cargar_datos(int _codigo){
	ifstream salida;
	char cod[20];
	sprintf(cod,"%d",_codigo);
	strcat(cod,extencion);
	Alumno *alumno;
	vector <string> lista;
	salida.open(cod, ios::in);
	if(salida.fail()){}
	
	else{
		map <string, double >cursos_notas;
		while(!salida.eof()){
			string linea;
			getline(salida, linea);
			lista.push_back(linea);
		}
		alumno->set_codigo(_codigo);
		alumno->set_apellidos(lista[1]);
		alumno->set_nombres(lista[2]);
		alumno->set_carrera(lista[3]);
		
		lista.erase(lista.begin()+3);
		for(int i=0; i< lista.size();i++){
			string n;
			int index = lista[i].find(" ");
			string curso = lista[i].substr(0,index);
			n=lista[i].substr(index+1,lista[i].size());
			int pos,num=0;
			
			for(int i=0; i<n.size() ;i++){
				if(n[i]=='.'){
					pos=i;
				}
				else{
					num=10*num+(n[i]-'0');
				}
			}
			
			double nota = num/pow(10, (n.size()-pos-1));
			cursos_notas[curso]=nota;
		}
		alumno->set_curso_nota(cursos_notas);
	}
	return alumno;
	
}
void Alumno::guardar_cambios(Alumno *alumno){
	ofstream entrada;
	
	entrada << alumno->get_codigo() <<endl;
	entrada << alumno->get_apellidos() <<endl;
	entrada << alumno->get_nombres() <<endl;
	entrada << alumno->get_carrera() <<endl;
	map <string, double > lista;
	lista = alumno->get_curso_nota();
	map <string, double >::iterator it;
	
	for(it = lista.begin(); it!=lista.end() ;it++){
		entrada << it->first <<" "<<it->second <<endl;
	}
	entrada.close();
	
	int _codigo=alumno->get_codigo();
	char cod[10];
	sprintf(cod,"%d",_codigo);
	strcat(cod,extencion);
	
	remove(cod);
	rename("temp.txt",cod);
}
