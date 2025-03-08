
#include <iostream>
#include <list>
#include<map>
using namespace std;

/* Funcion de equal_range

pair<it1,it2> = equal_range(valor de clave)
it1: donde aparece por primera vez el valor que le preguntamos
it2: uno mas, de donde aparece el ultimo elemento que le estamos preguntando
*/


map<string,list<int>> getMapa(const multimap<string,int> & multim){
	map<string,list<int>> out;
	
	multimap<string,int>::const_iterator it=multim.cbegin();
	pair<multimap<string,int>::const_iterator,multimap<string,int>::const_iterator> ret; //Lo igualaremos al igual_range
	
	while(it != multim.cend()){ //Recorremos el multimap
		
		list<int> lista;
		
		ret = multim.equal_range((*it).first);
		
		for(auto it2 = ret.first ; it2 != ret.second ; ++it2){
			lista.push_back((*it).second);
			++it;
		}
		
		--it; //Retomamos el valor anterior de iteracion, para introducir el string en el map, y no perder el valor
		out.emplace((*it).first,lista);
		++it;
		//lista.clear();
	
	}
		
	return out;
}

int main(){

	multimap<string,int> multimapa({{"ahora",1},{"ahora",3},{"ahora",4},{"aunque",3},{"aunque",5},{"banco",2},{"banco",10},
		{"zanahoria",1},{"zanahoria",2}});
		
	map<string,list<int>> mapa=getMapa(multimapa);			
	/*({"ahora",{1,3,4}},{"aunque",{3,5}},{"banco",{2,10}},{"zanahoria",{1,2}});*/
	
	map<string,list<int>>::iterator it;
	
	for( it = mapa.begin(); it!=mapa.end(); ++it){
		cout<<"Clave: " << (*it).first << "Lista asociada: ";
		
		for(auto it_l = (*it).second.begin(); it_l != (*it).second.end() ; ++it_l){
			
			cout<< *it_l << " ";
		}
		cout<<endl;
	
	}

	return 0;
}






/*pair< multimap<string,int>::const_iterator , multimap<string,int>::const_iterator > repeticiones;
	map<string,list<int>> out;
	list<int> lista;
	
	multimap<string,int>::const_iterator it;
	it = multim.cbegin();
	
	while (it != multim.cend()){ //Recorremos el multimapa
	
		repeticiones = multim.equal_range((*it).first); //Emplace del string
		
		for( auto it2 = repeticiones.first ; it2 != repeticiones.second ; ++it2){
		
			lista.push_back((*it).second);
			++it;
		}
		--it;
		out.emplace((*it).first,lista);
		
		lista.clear();
		++it;
	}
	
	
	return out;	*/

