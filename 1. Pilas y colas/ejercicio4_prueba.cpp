#include <iostream>
#include <stack>
#include <list>

class MultiPilas{
	private:
	
	list<stack<int>> mp;
	
	public:	
	
	//Multitop: obtiene una lista con los topes de todas las pilas
	
	list<int> Multitop(){
	
		list<int> out;
		list<stack<int>>::iterator it;
		
		for(it=mp.begin() ; it!=mp.end() ; ++it){
		
			int tope = (*it).top();
			out.push_back(tope);
		}
		
		return out;
	}
	
	//Multipop: elimina los topes de todas las listas
	
	void Multipop(){
	
		list<stack<int>>::iterator it;
		
		for(it=mp.begin(); it!=mp.end(); ++it){
			if(!(*it).empty()){ //No podemos hacer pop si esta la pila vacia
			
				(*it).pop();
			}		
		}
	}
	
	/*Multipush: dada una lista de enteros añade esos elementos a las pilas. Así el
	elemento primero de la lista de entrada se le añade a la pila primera, el
	segundo a la segunda pila y así sucesivamente.*/
	
	void Multipush(const list<int> & L){
	
		list<stack<int>>::iterator it;
		list<int>::const_iterator jt=L.cbegin();
		
		for(it=mp.begin(); it!=mp.end() || jt!=L.cend(); ++it){
			
			(*it).push(*jt);
			++jt;
		}
	}
	
	int top(list<stack<int> >::iterator it){
	
	
		return (*it).top();
	}
	
	void pop(list<stack<int> >::iterator it){
	
		(*it).pop();
	}

};


int main(){
	
	 MultiPilas multiPilas;
    	list<int> elementos = {1, 2, 3, 4, 5};

    	multiPilas.Multipush(elementos);

    	for (auto it = multiPilas.pilas.begin(); it != multiPilas.pilas.end(); ++it) {
       	 	while (!it->empty()) {
          	  	cout << "Top de pila: " << multiPilas.top(it) << endl;
            		multiPilas.pop(it);
        	}
    	}


	return 0;
}



