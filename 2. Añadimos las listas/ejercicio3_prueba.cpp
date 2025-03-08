//Ejercicio3

#include <iostream>
#include <stack>
#include <list>
using namespace std;

bool mismo_n_enteros(int n, const list<int> & L){

	int numero=0; //No se puede repetir mas de una vez
	list<int> :: const_iterator it;
	
	for(it=L.cbegin();it!=L.cend() && numero <= 1;++it){ //Parara, si encuentra mas de un numero, es decir, se repite
		if(*it == n ){
			
			numero++;
		}
	}

	if(numero == 1){
		
		return true;
	}else{
	
		return false;
	}
}

bool es_permutacion(const list<int> & L, const stack<int> & q){

	stack<int> aux(q);
	bool mismo_numero=true ;
	
	
	if(L.size()!=aux.size()){
	
		return false; //Tienen que tener el mimso tamanio 
	}
	
	//Primero tenemos que ver que dentro de la pila, no se repita ningun valor, si se repite alguno, no es permutacion directamente
	
	while(aux.size()>1){ //No nos interesa que nos compare si solo le queda un entero
		stack<int> pila_copia(aux);
		pila_copia.pop(); //Desecho el primer valor, ya que no quiero que me coja el mismo que voy a comprobar
		
		int tope=aux.top();
		aux.pop();
		while(!pila_copia.empty()){
			if(tope == pila_copia.top()){ //Detectamos, que hay un valor que se repite, por lo que no pueden ser permutacion
			
				return false;
			}
			pila_copia.pop();
		}
	}
	
	 stack<int> aux2(q);//Recupero el valor de q
	
	while(!aux2.empty() && mismo_numero){ //Se sale en el caso, en el que detecte que se repite, es decir, no son permutacion
		int tope=aux2.top();
		aux2.pop(); //Para desechar el top, y recorrer todos los elementos de la pila
		
		mismo_numero=mismo_n_enteros(tope,L); //Devuelve false si encuentra mas de una vez el mismo entero
		
	}
	
	return mismo_numero; 

}

int main(){
	
	const list<int> L({5,4,1,2});
	const stack<int> q({1,2,4,5});
	
	if(es_permutacion(L,q)){
	
		cout<<"Son permutacion. "<<endl;
	}
	else{
	
		cout<<"No son permutacion "<<endl; 
	}
	

	return 0;
}
