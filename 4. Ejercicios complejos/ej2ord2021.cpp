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
#include <map>
#include <vector>
#include <list>

using namespace std;

vector<list<string>> palabreria(map<string, list<pair<int,int>> > m){
	
	vector<list<string>> out;
	
	
	map<string, list<pair<int,int>>>::iterator it;
	list<pair<int,int>>::iterator its;
	
	it = m.begin();
	
	while( it != m.end()){
	
		list<pair<int,int>> lista = (*it).second;
		
		for( its = lista.begin() ; its != lista.end() ; ++its){
		
			 	if( (*its).first  > out.size()){
			
					out.resize((*its).first);
				}
			
			out[(*its).first -1 ].push_back((*it).first);
		}
	
	
		++it;
	}
	
	vector<list<string>>::iterator itv;
	
	for( itv = out.begin() ; itv != out.end() ; ++itv){
	
		(*itv).unique();
	}
	
	return out;
}

int main(){
	
	map<std::string, list<pair<int, int>>> libro{
        {"informática", {{1, 10}, {2, 10}, {3, 41}}},
        {"telemática", {{1, 2}, {1, 21}, {2, 50}, {3, 31}}},
        {"robótica", {{3, 30}, {4, 5}}}
    };
        					
        vector<list<string>> vectorDeListas = palabreria(libro);
        
        for (const auto& lista : vectorDeListas) {
        	cout << "Lista: ";
        	for (const auto& elemento : lista) {
            		cout << elemento << " ";
        	}
        	cout << endl;
    	}
	

	return 0;
}


