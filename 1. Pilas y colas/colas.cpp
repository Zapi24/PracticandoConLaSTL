#include <iostream>    
#include <queue>    
#include <stack>
#include <string>    
using namespace std;   
  
int main() {
    queue<int> myQueue({5,6,7,8,9});

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.emplace(2);

    cout << "Size of the queue: " << myQueue.size() << endl;
    cout << "Final de la cola: " << myQueue.back() <<endl;
    cout << "Frente de la cola: " << myQueue.front() <<endl<<endl;
    //cout << "No se si devuelve algo "<< myQueue.top() <<endl<<endl; NO EXISTE top EN COLAS
    
    cout << "Front element: ";
    queue<int> aux(myQueue);
    queue<int> inversa;
    stack<int> pila;

    while (!myQueue.empty()) {
        int frontElement = myQueue.front();
        cout << frontElement << " ";
        pila.push(frontElement);
        myQueue.pop();
    }
    cout<<endl;
    
    cout << "Back element: ";
    while (!aux.empty()){ //No sirve para recorrer, ya que el pop elimina el elemento del front, no del back
    	int backElement = aux.back();
    	cout << backElement << " ";
    	aux.pop();
    }
    cout<<endl;
    
    //Le damos la vuelta con la pila
    while(!pila.empty()){
    
    	int tope=pila.top();
    	inversa.push(tope);
    	pila.pop();
    }
    
    cout<<"Cola inversa: ";
    while(!inversa.empty()){
    
    	int frente= inversa.front();
    	cout<<frente<<" ";
    	inversa.pop();
    }
    cout<<endl;

    return 0;
}

