//
// Created by zapi24 on 25/10/23.
//

#include <queue>
#include <list>
#include <iostream>
using namespace  std;

bool isomorficas (queue<int> & C, list<int> & L){
    if(C.size()!=L.size()){

        return false;
    }

    int par=1; //El frente es la posicion 1
    int aux;
    list <int>::iterator it=L.begin();

    while(!C.empty()){

        aux=C.front();
        C.pop();
        if(par==0 && aux!=*it){ //Solo entramos si nos encontramos en una posicion par,

            return false;
        }
        ++it;
        par=(par+1)%2; //Pasamos a par entre 0 y 1

    }
}

int main(){
    queue<int> cola({1,5,7,9,8,4});
    list<int> lista({9,5,3,9,10,4});

    if(isomorficas(cola,lista)){

        cout<<"Son isomorficas"<<endl;
    }
    else{

        cout<<"No son isomorficas"<<endl;
    }
    return 0;
}
