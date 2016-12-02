#include "memento.h"


void Memento::guardar_alumno(Alumno *alumno)
{
	ofstream entrada;
	char codigo[10];
	sprintf(codigo, "%d", alumno->get_codigo());
	strcat(codigo,extencion);
	
	map <string, double > lista;
	lista = alumno->get_curso_nota();
	
	map <string, double >::iterator it;
//	ALMACENANDO ALUMNO
	entrada.open(codigo,ios::out | ios::app);
	
	entrada << alumno->get_codigo() <<endl;
	entrada << alumno->get_apellidos() <<endl;
	entrada << alumno->get_nombres() <<endl;
	entrada << alumno->get_carrera() <<endl;
	
	for(it = lista.begin(); it!=lista.end() ;it++){
		entrada << it->first <<" "<<it->second <<endl;
	}
	entrada.close();
	
	ofstream matriculados, codigos;
	
	matriculados.open("lista_matriculados.txt",ios::out | ios::app);
	codigos.open("codigo_clave.txt",ios::out | ios::app);
	
	matriculados << alumno->get_codigo() <<"-";
	matriculados << alumno->get_apellidos() <<" "<< alumno->get_nombres() <<"-";
	matriculados << alumno->get_carrera() << endl;
	
	codigos << alumno->get_codigo() <<" "<< alumno->get_clave()<<endl;
	
	matriculados.close();
	codigos.close();
	
//	alumno->get_c
	map <string, double> lista_cursos = alumno->get_curso_nota();
	map <string, double>::iterator it1;
	
	vector <string> cursos;
	vector <double> notas;
	for(it1 = lista_cursos.begin();it1 != lista_cursos.end(); it1++){
		cursos.push_back(it1->first);
		notas.push_back(it1->second);
	}
	
	for(int i=0;i<cursos.size();i++){
		int j;
		char nombre_curso[30];
		for(j=0;j<cursos[i].size();j++){
			nombre_curso[i] = cursos[i][j];
		}
		nombre_curso[j]='\0';
		strcat(nombre_curso, extencion);
		
		ofstream curso;
		curso.open(nombre_curso, ios::out | ios::app);
		curso << alumno->get_codigo() << "-";
		curso << alumno->get_apellidos() <<alumno->get_nombres() <<"-";
		curso << notas[i] << endl;
		curso.close();
	}
}

vector <int> Memento::cargar_codigos()
{
	ifstream salida;
	salida.open("codigo_clave.txt", ios::in);
	if(salida.fail()){return codigos;}
	else{
		int codigo;
		string clave;
		
		salida >> codigo;
		while(!salida.eof()){
			salida >> clave;
			codigos.push_back(codigo);
			salida >> codigo;
		}
	}
	return codigos;
}

vector <string> Memento::cargar_alumnos()
{
	ifstream salida;
	salida.open("lista_matriculados.txt",ios::in);
	
	if(salida.fail()){
		cout << "NO HAY ALUMNOS MATRICULADOS" <<endl;
		return alumnos;
	}
	else{
		char c;
		string linea;
		
		while(!salida.eof()){
			c=salida.get();
			if(c=='-'){
				c ='\t';
				linea.push_back(c);
			}
			else if(c=='\n'){
				alumnos.push_back(linea);
				linea.clear();
			}
			else{
				linea.push_back(c);
			}
		}
		return alumnos;
	}
}


void Memento::guardar_profesor(Profesor *profesor)
{
	char codigo[10];
	sprintf(codigo, "%d", profesor->get_codigo());
	strcat(codigo,extencion);
	
	ofstream entrada,lista_profesores, codigo_clave;
	
	entrada.open(codigo, ios::out | ios::app);
	lista_profesores.open("lista_profesores.txt",ios::out | ios::app);
	codigo_clave.open("codigo_clave.txt", ios::out | ios::app);
	
	entrada << profesor->get_codigo()<<endl;
	entrada << profesor->get_apellidos()<<endl;
	entrada << profesor->get_nombres()<<endl;
	entrada << profesor->get_correo()<<endl;
	entrada << profesor->get_curso_asignado()<<endl;
	
	lista_profesores << profesor->get_codigo() <<"-";
	lista_profesores << profesor->get_apellidos() <<" ";
	lista_profesores << profesor->get_nombres() <<"-";
	lista_profesores << profesor->get_curso_asignado() <<endl;
	
	codigo_clave << profesor->get_codigo() << " " << profesor->get_clave()<<endl;
	
	for(int i=0; profesor->get_estudios().size() ;i++){
		entrada << profesor->get_estudios()[i] << endl;
	}
	entrada.close();
	lista_profesores.close();
	codigo_clave.close();
}


vector <string> Memento::cargar_profesores()
{
	
	ifstream salida;
	salida.open("lista_profesores.txt", ios::in);
	
	if(salida.fail()){
		cout << "PROFESOR NO ENCONTRADO"<<endl;
	}
	else{
		char c;
		string linea;
		
		while(!salida.eof()){
			c=salida.get();
			if(c=='-'){
				c ='\t';
				linea.push_back(c);
			}
			else if(c=='\n'){
				profesores.push_back(linea);
				linea.clear();
			}
			else{
				linea.push_back(c);
			}
		}
	}
	return profesores;
}
//asdfsad
