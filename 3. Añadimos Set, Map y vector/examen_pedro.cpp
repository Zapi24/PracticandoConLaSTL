#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;


bool en_todos(const vector<set<int>> &V) {

	vector<set<int>>::const_iterator it=V.cbegin();
	
	set<int> set_inicial = *it; //Sacamos el set inicial para buscar todos sus elementos, en los demas sets de vector
	set<int>::iterator its=set_inicial.begin();
	
	int entero;
	
	while(its != set_inicial.end()){
		entero = *its;
		int contador=0;
		
		for( it=V.cbegin() ; it != V.cend() ; ++it){
		
			auto it2 = (*it).find(entero);
			if( it2 != (*it).end()){ //Si es distinto, significa que lo ha encontrado
		
				contador++;
			}
		}
		if(contador == V.size()){ //Implica que el elemento, lo ha encontrado dentro de todos los sets
		
			return false;
		}
			
		++its;
	}
	
	return true;	
}

int main() {
    vector<set<int>> mv({{0, 2, 3, 4}, {0, 1, 5, 7}, {2, 3, 5, 6, 7}});

    if (en_todos(mv)) {
        cout << "Devuelve true, no hay ningún elemento que esté en todos" << endl;
    } else {
        cout << "Devuelve false, el elemento está en todos" << endl;
    }

    return 0;
}
