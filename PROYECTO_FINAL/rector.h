#ifndef RECTOR_H
#define RECTOR_H
#include <map>
#include <vector>

using namespace std;

class Rector{
	protected:
		vector<int> verificacion_codigos; //para ver que no se repitan
		string nombre_apellido;
		char codigo[40];
		int total_cursos;
		static int total_alumnos;
		
//		vector <string> alumnos;
		//		map<string, double> cursos; //cursos y notas

//		int clave;
//		int salario;
		string carrera;
		
		public:
			Rector();
			bool verificar_codigo(int);
			void almacenar_codigo(int);
////			bool acceso(string, string);	//codigo y clave
////			virtual void get_datos(T);	//nombres ,apellidos, direccion, correo, curso
////			
////			//ADMINISTRATIVO
////			virtual double get_salario();
////			virtual void get_docentes();
////			virtual int *cant_alumnos();
////
////			//DOCENTE
////			virtual string get_curso();
////			
////
////			//ALUMNO
////			virtual void get_notas();
////			virtual int nro_cursos();
////			virtual bool matriculado();
};

#endif
