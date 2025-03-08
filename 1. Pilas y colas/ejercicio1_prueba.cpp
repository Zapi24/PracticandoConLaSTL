//Ejercicio1

#include <iostream>
#include <queue>
#include <list>
using namespace std;

bool isomorficas (queue<int> & C, list<int> & L){
	
	list<int>:: iterator it=L.begin();
	
	if(C.size() != L.size()){
	
		return false;
	}
	
	int frente;
	int boleano=0;
	
	while(!C.empty()){
	
		frente=C.front();
		C.pop();
		
		if(boleano==1 && frente!=*it){ //Encuentra las posiciones pares, donde no coinciden
		
			return false;
		}
		
		++it;
		boleano=(boleano+1)%2;
	}

	return true;
}

int main(){
	
	queue<int> c({1,5,7,9,8,4});
	list<int> l({9,5,3,9,10,4});
	
	if(isomorficas(c,l)){
	
		cout << "Son isomorficas " <<endl;
	}else{
	
		cout << "No son isomorficas " <<endl;
	}


	return 0;
}
