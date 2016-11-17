#include<iostream>
#include <stdlib.h>
#include <string>
#include <fstream> //manejo de aarchivos
#include <stdio.h>
#include <conio.h>
#include <windows.h> 
#include "alumno.h"
using std::endl;
using std::cout;
using std::cin;

void dar_color(int x) 
{ 
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),x); 
}


void menu_profesor(){
	
	int rpta;
	string nombre;
	cout<<"\t===============OPCIONES==============="<<endl;
	cout<<"\t|                                    |"<<endl;
	cout<<"\t|         1)ALUMNOS                  |"<<endl;
	cout<<"\t|         2)DATOS                    |"<<endl;
	cout<<"\t|         3)MODIFICAR NOTAS          |"<<endl;	
	cout<<"\t|                                    |"<<endl;	
	cout<<"\t======================================"<<endl;
//	cin>>rpta;
//	switch(rpta){
//		case 1:lista_alumnos();break;
//		case 2:mostrar_datos();break;
//		case 2:cout<<"nombre de alumno: ";
//			   cin>>nombre;
//			   if(buscar_alumno(nombre)){
//				   mostrar_nombre
//			   }
//		
//		
//	}
}
void menu_alumno(){
	cout<<"\t\t===============OPCIONES==============="<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t|              1)DATOS               |"<<endl;
	cout<<"\t\t|              2)CURSOS              |"<<endl;
	cout<<"\t\t|              3)SALIR               |"<<endl;
	cout<<"\t\t|                                    |"<<endl;
	cout<<"\t\t======================================"<<"\n\n\n";
	
	cout<<"\t\tSELECCIONE UNA OPCION: ";
}

//HACER LISTAS EN PROTECTED CLASE BASE QUE ALMACENEN ALUMNOS,PROF,ETC
//Y HACER PUSH_BACK CADA VEZ QUE SE CREE UN ALUMNOS,PROF,ETC

int main () {
	ifstream archivo;
	string rpta;
	char nombre[20];
	HANDLE color;
//	------------INGRESO----------------
//		color(color "fondo"-"letra")
	system("color 0A");
	
	do{
		char cod[40],clav[40];
		char e[5]=".txt";

		cout<<"\t\tCODIGO: ";
		cin>>cod;
		cout<<"\n\t\tCLAVE:  ";
		cin>>clav;

		strcat(cod,clav);
		strcat(cod,e);
		archivo.open(cod,ios::in);
		strcpy(nombre,cod);
		system("cls");
		if(archivo.fail()){
			cout<<"\t\tCODIGO Y CLAVE INCORRECTOS"<<"\n\n";
			cout<<"\t\tVOLVER A INGRESAR?(s/n): ";
			cin>>rpta;
			system("cls");
		}
		else{
			cout<<"\t\tBIENVENIDO!!!"<<endl;
			Sleep(1500); 
			system("cls");
			break;
		}
	}while(rpta=="s");
//	-----------------FIN INGRESO-----------------
	
	
	Alumno alumno;
	alumno.dar_codigo(nombre);
	bool continuar=true;
	
	while(continuar){
		
		while(true){
			int opc,opc1;
			menu_alumno();
			cin>>opc;
			
			switch(opc){
				case 1: alumno.mostrar_datos();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n";
						cout<<"\t\t1)VOLVER\t\t\t2)SALIR";
						cin>>opc1;
						system("cls");
						break;
				case 2: alumno.mostrar_cursos();
						cout<<"\n\n\n\n\n\n\n\n\n\n\n";
						cout<<"\t\t1)VOLVER\t\t\t2)SALIR";
						cin>>opc1;
						system("cls");
						break;
				case 3: break;
			}
			if (opc==3){continuar=false;break;}
			if(opc1==1){break;}
			else if(opc1==2){continuar=false;break;}
		}
	}
	
	
	system("PAUSE");
	return 0;
}
