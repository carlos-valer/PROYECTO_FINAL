#include <iostream>

using namespace std;

class Facade{
	public :
		template <class T>
		void cambiar_clave(T *,string );
};
template <class T>
void Facade::cambiar_clave(T *persona, string clave){
	persona->set_clave(clave);
}
