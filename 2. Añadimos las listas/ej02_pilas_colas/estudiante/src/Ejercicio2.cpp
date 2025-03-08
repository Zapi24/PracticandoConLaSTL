//
// Created by zapi24 on 25/10/23.
//

#include <queue>
#include <list>
#include <iostream>
using namespace  std;



int Suma(list<int> & L){
	int s=0;
	
	list <int>::iterator it;
	for(it=L.begin();it!=L.end();++it){
	
		s=s+*it;
	}
	
	return s;
}

queue<int> GetSumas(queue<list<int> > & ql){
	queue<int> out;
	
	while(!ql.empty()){
		list<int> aux = ql.front();
		ql.pop(); //Despues de hacer front, el pop nos permite avanzar dentro de la cola
	
		int s=Suma(aux);
		out.push(s);
	}
	
	return out;
}

template <class T>

void Imprimir(queue<T> q){
	while(!q.empty()){
	
		cout<<q.front()<<" ";
		q.pop();
	}
}



int main(){

    queue<list<int>> cola({{1,2,3},{4,5},{3,7,2}});
    
    cout<<"Resultado: ";
    Imprimir(GetSumas(cola));

    
    return 0;
}
