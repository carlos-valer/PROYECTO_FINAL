#include <iostream>
#include <conio.h>
#include <windows.h>
#include <conio.h>
#include "alumno.h"
#include "profesor.h"
#include "director.h"
#include "facade.cpp"
#include "menu.h"
#include <windows.h>
using namespace std;

int main () {
	system("color 0A");
	Menu menu;
	Alumno *alumno;
	Profesor *profesor;
	
	Director *director = new Director;
	Facade facade;
	while(true) {
		int codigo;
		string clave;
		cout<<"CODIGO : ";
		cin >> codigo;
		cout<<"CLAVE : ";
		cin >>clave;
		
//		COMPROBAR SI CODIGO Y CLAVE COINCIDEN
	
		
		system("cls");
		
/*--*/ 	if(director->verificar_codigo(codigo,clave)){
	
		if(codigo<200){
			while(true) {
				string opcion;
				menu.menu_alumno();
				cin >> opcion;
				system("cls");
				Alumno *_alumno = new Alumno();
				_alumno=alumno->cargar_datos(codigo);
				
				if(opcion == "1"){
					
					while(true){
						cout << "se muestra nombres ,apellidos, etc"<<endl;
						_alumno->mostrar_datos();
						string opc;
						cout << "1)MODIFICAR CLAVE\t2)VOLVER"<<endl;
						cin >>opc;
						system("cls");
						if(opc=="1"){
							string clave;
							cout << "INGRESE NUEVA CLAVE : ";
							cin >>clave;
							facade.cambiar_clave(_alumno,clave);
							alumno->guardar_cambios(_alumno);
							system("cls");
							cout <<"CLAVE MODIFICADA !!!"<<endl;
							Sleep(1000);
							system("cls");
						}
						else if(opc == "2"){
							break;
						}
						else{cout <<"NO ES UNA OPCION CORRECTA"<<endl;Sleep(1000);system("cls");}
					}
				}
				else if(opcion == "2"){
					break;
				}
				else {
					cout <<"NO ES UNA OPCION"<<endl;
					Sleep(1000);
					system("cls");
				}
			}
		}
		else if(codigo > 300 && codigo < 400){
			Profesor *_profesor;
			_profesor = profesor->cargar_datos_profesor(codigo);
			while(true){
				string opcion;
				menu.menu_profesor();
				cin >> opcion;
				system("cls");
				if(opcion == "1"){
					while(true){
						string opc;
//						cout <<"apellidos nombres curso asignado\nestudios etc"<<endl;
						_profesor->mostrar_datos();
						cout <<"1) CAMBIAR CLAVE\t2)VOLVER ";
						cin >> opc;
						system("cls");
						 
						if(opc=="1"){
							string clave;
							cout << "INGRESE NUEVA CLAVE : ";
							cin >>clave;
							facade.cambiar_clave(_profesor,clave);
							profesor->guardar_cambios(_profesor);
							system("cls");
							cout <<"CLAVE MODIFICADA !!!"<<endl;
							Sleep(1000);
							system("cls");
						}
						else if(opc == "2"){
							break;
						}
						else{cout <<"NO ES UNA OPCION CORRECTA"<<endl;Sleep(1000);system("cls");}
					}
				}
				else if(opcion == "2"){
					while(true){
						string opc;
						_profesor->mostrar_datos();
//						cout <<"alumno nota\nalumno nota\nalumno nota\nalumno nota"<<endl;
						cout << "\n\n1)MODIFICAR NOTA\t2)VOLVER ";	
						cin >> opc;
						system("cls");
						
						if(opc == "1"){
							Alumno *_alumno = new Alumno();
							int cod;
							double nota;
							cout <<"CODIGO DEL ALUMNO : ";
							cin >> cod;
							system("cls");
							cout << "INGRESE NOTA : "<<endl;
							cin >> nota;
							_alumno = alumno->cargar_datos(cod);
							alumno->guardar_cambios(_alumno);
							system("cls");
							cout << "NOTA MODIFICADA !!!";
							Sleep(1000);
							system("cls");
						}
						else if(opc =="2"){
							system("cls");
							break;
						}
						else{
							cout <<"NO ES UNA OPCION CORRECTA";
							Sleep(1000);
							system("cls");
						}
					}
				}
				else if(opcion == "3"){
					system("cls");
					break;
				}
				else {cout <<"\nNO ES UNA OPCION CORRECTA";Sleep(1000);system("cls");}
			}
		}
		else if(codigo == 999){
			
			while(true){
				string opcion;
				menu.menu_director();
				cin >> opcion;
				system("cls");

				if(opcion =="1"){
					while(true){
						string opc;
//						cout << "Se pide datos de alumno para registrarlo"<<endl;
						director->agregar_alumno();
						Sleep(500);
						system("cls");
						cout << "ALUMNO REGISTRADO !!!"<<endl;
						Sleep(1000);
						break;
					}
				}
				if(opcion =="2"){
					while(true){
						string opc;
						cout << "1)POR CODIGO\t2)POR APELLIDOS O NOMBRES\t3)SALIR"<<endl;
						cin >> opc;
						system("cls");
						
						if(opc == "1"){
							int _codigo;
							cout << "INGRESE CODIGO : ";
							cin >> _codigo;
							system("cls");
							if(true){
								string _opc;
								/*cout << "------datos encontrados----"<<endl;*/
								director->buscar_alumno(_codigo);
								cout << "\n\nPRESIONE CUALQUIER TECLA PARA VOLVER ";
								cin >>_opc;
								
								system("cls");
							}
						}
						if(opc == "2"){
							string nombres;
							cout << "INGRESE NOMBRE(S) O APELLIDO(S)" <<endl;
							cin >>nombres;
							system("cls");

							if(true){
								string _opc;
								director->buscar_alumno(nombres);
								cout << "\n\nPRESIONE CUALQUIER TECLA PARA VOLVER ";
								cin >>_opc;
								system("cls");
							}
						}
						if(opc == "3"){system("cls");break;}
					}
				}
				if(opcion =="4"){
					while(true){
						string opc;
						cout << "1)POR CODIGO\t2)POR APELLIDOS O NOMBRES\t3)SALIR"<<endl;
						cin >> opc;
						system("cls");
						
						if(opc == "1"){
							int _codigo;
							cout << "INGRESE CODIGO : ";
							cin >> _codigo;
							system("cls");

							if(true){
								string _opc;

								director->buscar_profesor(_codigo);
								cout << "\n\nPRESIONE CUALQUIER TECLA PARA VOLVER ";
								cin >>_opc;
								
								system("cls");
							}
						}
						if(opc == "2"){
							string nombres;
							cout << "INGRESE NOMBRE(S) O APELLIDO(S)" <<endl;
							cin >>nombres;
							system("cls");
							if(true){
								string _opc;

								director->buscar_profesor(nombres);
								cout << "\n\nPRESIONE CUALQUIER TECLA PARA VOLVER ";
								cin >>_opc;
								system("cls");
							}
						}
						if(opc == "3"){system("cls");break;}
					}
				}
				if(opcion =="3"){
					while(true){
						string opc;
						director->agregar_profesor();
						Sleep(500);
						system("cls");
						cout << "PROFESOR REGISTRADO !!!"<<endl;
						Sleep(1000);
						system("cls");
						break;
					}
				}
				if(opcion =="5"){system("cls");break;}
			}
		}
		
		}
		else{
			cout << "CODIGO Y/O CLAVE INCORRECTOS"<<endl;
			Sleep(1000);
			system("cls");
		}
	
	
	}
	return 0;
}

