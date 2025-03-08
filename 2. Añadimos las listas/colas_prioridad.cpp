#include <iostream>    
#include <queue>    
#include <string>    
#include <vector>
using namespace std;   
  
int main () {    
  priority_queue<int> q; //Ordena de menor a mayor 
  priority_queue<int, vector<int>, greater<int>> ejemplo;    //Ordena de mayor a menor
  
  
  for(int n : {1,8,5,6,3,4,0,9,7,2,2,2,2 }){
  
  	q.push(n);  
  	ejemplo.push(n);
  }  
     
    
    cout << "Size of the queue: " << q.size() << endl;
    //cout << "Final de la cola: " << q.back() <<endl;
    //cout << "Frente de la cola: " << q.front() <<endl;
    
    
    
  while(!q.empty()) {  
    cout << q.top() << " "; //Muestra el elemento como una pila, es decir, primero el ultimo (saldra de forma inversa) 
    q.pop();  
  } 
  cout<<endl;
  
  while(!ejemplo.empty()){
  
  	cout<< ejemplo.top() << " "; //Muestra el elemento como una pila, es decir, primero el ultimo (saldra de forma inversa) 
  	ejemplo.pop();
  
  }
   
  cout << '\n'; 
  return 0;    
}

