//Ejercicio2

#include <iostream>
#include <queue>
#include <list>
using namespace std;

queue<int> GetSumas(queue<list<int>> & ql){
	queue<int> out;
	int suma=0;
	
	
	while(!ql.empty()){
		
		list<int> lista_frente(ql.front());
		ql.pop();
		
		list<int>::iterator it;
		
		for(it=lista_frente.begin() ; it!=lista_frente.end() ; ++it){
		
			suma = suma + *it;
		}
		
		out.push(suma);
		suma=0;
	}

	return out;
}

int main(){
	
	queue<list<int>> ql({{1,2,3},{4,5},{3,7,2}});
	queue<int> q(GetSumas(ql));
	
	while(!q.empty()){
	
		int frente=q.front();
		q.pop();
		cout<< frente << " ";
	}
	cout<<endl;
	
	return 0;
}
