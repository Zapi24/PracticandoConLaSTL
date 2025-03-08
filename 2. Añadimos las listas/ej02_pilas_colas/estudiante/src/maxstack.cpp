/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author
 */

#include "maxstack.h"

void MaxStack::push(int v){

    elem a({v,v});
    if(elements.empty()){

        elements.push(a);
        return;
    }
    else{

        elem curr = elements.front();
        a.maximun = (v<curr.maximun) ? curr.maximun: v;

        queue<elem> aux;
        aux.push(a);
        while(!elements.empty()){

            aux.push(elements.front());
            elements.pop();
        }

        elements=aux;
    }

}
