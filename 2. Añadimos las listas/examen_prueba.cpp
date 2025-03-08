//Haz una funcion que dada una cola, devuelva la misma, de forma inversa y sin valores repetidos

#include <iostream>
#include <queue>
#include <stack>
using namespace std;


bool insertar(int n, queue<int> q){

	while(!q.empty()){
		int frente=q.front();
		q.pop();
		if( n == frente){
			
			return false; //Ya se ha introducido el numero, no hay que insertarlo de vuelta
		}
	}

	return true;
}


queue<int> cola_inversa(const queue<int> & q){

	queue<int> aux(q),out;
	stack<int> pila;
	
	
	//Metemos la cola en la pila
	
	while(!aux.empty()){
	
		pila.push(aux.front());
		aux.pop();
	}
	
	//Metemos de vuelta la cola en la pila, y tenemos cuidado de no meter valores repetidos
	
	while(!pila.empty()){
		if(insertar(pila.top(),out)){
		
			out.push(pila.top());
			
		}
		pila.pop();
	}
	
	
	return out;
}



int main(){

	queue<int> mi_cola({1,2,2,2,2,3,3,4,5,6,7,8,9});
	
	mi_cola=cola_inversa(mi_cola);
	
	while(!mi_cola.empty()){
	
		int frente=mi_cola.front();
		mi_cola.pop();
		cout<< frente << " ";
	}
	cout<<endl;



	return 0;
}

