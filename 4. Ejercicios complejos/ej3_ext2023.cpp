/* Ej3 Extraordinaria 2023

3. (1 punto) Implementar una función
	bool permutalista (list<int> & L1, list<int> & L2)
que devuelva true si L1 y L2 tienen la misma cantidad de elementos y los elementos de L1
son una permutación de los de L2

P.ej: si L1={1,23,21,4,2,3,0} y L2={21,1,3,2,4,23,0} devolvería TRUE pero si L1={1,3,5} y L2={1,5,4} devolvería FALSE


Si hay elementos repetidos tienen que estar el mismo número de veces en las 2 listas para
poder ser TRUE. No pueden usarse estructuras auxiliares, el algoritmo puede ser
destructivo y no conservar las listas iniciales y no puede usarse ningún algoritmo de
ordenación.

*/

#include <iostream>
#include <list>
using namespace std;

int num_veces(list<int> & l, int n){ //Cuenta el numero de veces que aparece 

	int veces = 0;
	list<int> :: iterator it;
	
	for( it = l.begin() ; it != l.end() ; ++it){
		if( *it == n){
		
			veces++;
		}
	}
	
	return veces;
}

bool permutalista (list<int> & L1, list<int> & L2){

	if(L1.size() != L2.size()){	//Tienen que tener el mismo tam
	
		return false;
	} 
	
	list<int> :: iterator it1 = L1.begin();
	while(it1 != L1.end()){
	
		int n1,n2;
		n1 = num_veces(L1,*it1);	//Cuenta el num de veces que esta el numero en l1
		n2 = num_veces(L2, *it1);	//Lo mismo con l2
		
		if( n2 == 0 || n1 != n2){ //Si no lo encuentra, o no lo encuentra el mismo num de veces, no son permutacion
		
			return false;
		}
		++it1;
	}
	return true;
}

int main(){
	
	list<int> l1 = {1, 23, 21, 4, 2, 3, 1};
    	list<int> l2 = {21, 1, 3, 2, 4, 23, 0};
	
	if(permutalista(l1,l2)){
	
		cout << "DEVUELVE TRUE " << endl;
	}
	else{
	
		cout << " DEVUELVE FALSE " << endl;
	}

	return 0;
}


