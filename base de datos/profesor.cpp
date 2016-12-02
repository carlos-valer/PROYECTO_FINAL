#include "profesor.h"
#include "memento.h"

Profesor::Profesor(){
	nombres="";
	apellidos="";
	codigo=0;
	clave="";
	correo="";
	curso_asignado="";
}
Profesor::~Profesor(){}

string Profesor::get_nombres(){
	return this->nombres;
}
void Profesor::set_nombres(string nombres){
	this->nombres=nombres;
}

string Profesor::get_apellidos(){
	return this->apellidos;
}
void Profesor::set_apellidos(string apellidos){
	this->apellidos=apellidos;
}
int Profesor::get_codigo(){
	return this->codigo;
}
void Profesor::set_codigo(int codigo){
	this->codigo=codigo;
}
string Profesor::get_clave(){
	return this->clave;
}
void Profesor::set_clave(string clave){
	this->clave=clave;
}

string Profesor::get_correo(){
	return correo;
}
void Profesor::set_correo(string correo){
	this->correo = correo;
}

string Profesor::get_curso_asignado(){
	return this->curso_asignado;
}
void Profesor::set_curso_asignado(string curso){
	this->curso_asignado=curso;
}

vector <string> Profesor::get_estudios(){
	return this->estudios;
}
void Profesor::set_estudios(vector <string> estudios){
	this->estudios=estudios;
}

Profesor *Profesor::cargar_datos_profesor(int codigo){
	char cod[10];
	sprintf(cod,"%d",codigo);
	strcat(cod, extencion);
	ifstream salida;
	salida.open(cod, ios::in);
	Profesor *profesor;
	if(salida.fail()){}
	else{
		string linea;
		vector <string> lista;
		while(!salida.eof()){
			getline(salida, linea);
			lista.push_back(linea);
		}
		
	}
	
}
void Profesor::guardar_cambios(Profesor *profesor){
	ofstream entrada;
	entrada.open("temp.txt",ios::out);
	entrada << profesor->get_codigo()<<endl;
	entrada << profesor->get_apellidos()<<endl;
	entrada << profesor->get_nombres()<<endl;
	entrada << profesor->get_correo()<<endl;
	entrada << profesor->get_curso_asignado()<<endl;
	
	for(int i=0; profesor->get_estudios().size() ;i++){
		entrada << profesor->get_estudios()[i] << endl;
	}
	entrada.close();
	int _codigo=profesor->get_codigo();
	char cod[10];
	sprintf(cod,"%d",_codigo);
	strcat(cod,extencion);
	
	remove(cod);
	rename("temp.txt",cod);
}
void Profesor::mostrar_datos(){
	cout <<"APELLIDOS "<<apellidos<<endl;
	cout <<"NOMBRES "<<nombres<<endl;
	cout <<"CODIGO "<<codigo<<endl;
	cout <<"CURSO ASIGNADO "<<curso_asignado<<endl;
	cout <<"ESTUDIOS :"<<endl;
	for(int i=0;i<estudios.size();i++){
		cout <<estudios[i]<<endl;	
	}
}
void Profesor::mostrar_lista_alumnos(){
	ifstream salida;
	char curso[20];
	int i;
	for(i=0;i<curso_asignado.size();i++){
		curso[i]=curso_asignado[i];
	}
	curso[i]='\0';
	strcat(curso,extencion);
	
	salida.open(curso, ios::in);
	if(salida.fail()){}
	else{
		string linea;
		int pos=1;
		while(salida.eof()){
			cout << pos++ <<")  ";
			getline(salida, linea);
	
			for(int i=0; i<linea.size() ; i++){
				if(linea[i]=='-'){
					linea[i]=' ';
				}
			}
			cout<<linea<<endl;
		}
	}
}




