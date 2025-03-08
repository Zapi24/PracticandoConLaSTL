//Pilas

/*#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> myStack({5,6,7,8,9});

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Size of the stack: " << myStack.size() << endl;
    //cout << "Prueba front: " << myStack.front() <<endl; NO EXISTE front EN PILAS
    //cout<< "Prueba back: " << myStack.back() <<endl; NO EXISTE back EN PILAS

    while (!myStack.empty()) {
        int topElement = myStack.top();
        cout << "Top element: " << topElement << endl;
        myStack.pop();
    }

    return 0;
}*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> myStack({"hola", "adios", "nacho", "carpeta"});

    myStack.push("casa");
    myStack.push("jardín");

    cout << "Size of the stack: " << myStack.size() << endl;

    while (!myStack.empty()) {
        string topElement = myStack.top();
        cout << "Top element: " << topElement << endl;
        myStack.pop();
    }

    return 0;
}

