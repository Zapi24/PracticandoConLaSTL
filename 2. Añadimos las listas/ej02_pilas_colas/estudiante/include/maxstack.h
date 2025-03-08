/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author
 */

#ifndef MAXSTACK_H
#define MAXSTACK_h

#include "queue"
#include <iostream>
using namespace std;

struct elem{

    int value;
    int maximun;
    friend ostream & operator<<(ostream & os, const elem &e){

        os<<e.value<<" "<<e.maximun<<endl;
        return os;
    }

};

class MaxStack{

private:
    queue<elem> elements;

public:
    MaxStack(): elements(){}
    bool empty()  const {return elements.empty();}
    int size() const{ return elements.size();}
    elem & top(){return elements.front();}
    void pop(){elements.pop();}
    void push (int v);


};

#endif
