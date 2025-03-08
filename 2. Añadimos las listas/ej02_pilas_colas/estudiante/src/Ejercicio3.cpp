//
// Created by zapi24 on 25/10/23.
//

#include <stack>
#include <list>
#include <iostream>
using namespace  std;

bool estaenLista(int x,const list<int> &L){
	
	list<int>::const_iterator it;
	
	for(it=L.cbegin(); it != L.cend(); ++it){
		if(*it==x){
		
			return true;
		}
	}

	return false;
}


bool es_permutacion(const list<int> &L, const stack<int> & q){ //Como son constantes, debemos crear una pila copia
	
	if(L.size() != q.size()){
	
		return false;
	}
	
	stack<int> aux(q); //Igualo q a aux
	
	while(!aux.empty()){
		
		int v=aux.top();
		aux.pop();
		if(!estaenLista(v,L)){
		
			return false;
		}
	}
	
	return true;
}

int main(){

    list<int> lista({1,2,4,5});
    stack<int> pila({5,4,1,2});

    if(es_permutacion(lista,pila)){
    
    	 cout<<"Es una permutacion"<<endl;
    }
    else{
    
    	cout<<"No es una permutacion"<<endl;
    }
    return 0;
}
