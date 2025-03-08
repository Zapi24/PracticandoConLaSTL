/*Dado un multiset de enteros obtener un mapa con clave el entero en el multiset y con información asociada el número de veces que aparece. La función sería:
map<int,int> getFrecuencia(const multiset<int> &ms)
Ej
Ms={1,1,1,1,3,3,3,2,2,6,6,6}
Map={<1,4>,<3,3>,<2,2>,<6,3>}
*/

#include <iostream>
#include <set>
#include <map>
using namespace std;

map<int,int> getFrecuencia(const multiset<int> & ms){
    
    map<int,int> out;
    
    pair< multiset<int>::const_iterator , multiset<int>::const_iterator > ret;
    multiset<int>::const_iterator it = ms.cbegin();
    int contador=0;
    
    while( it != ms.cend() ){
  
  	ret = ms.equal_range(*it);
  	
  	for(auto it2 = ret.first ; it2 != ret.second ; ++it2){
  	
  		contador++;
  		++it;
  	}
  	
  	--it; 
  	out.emplace(*it,contador);
  	contador=0;
  	++it;
    } 
   
    return out;
}
int main(){

 multiset<int> MS({1,1,1,1,3,3,3,2,2,6,6,6}); // en el multiset se colocaran ordenados

 map<int,int> mimap=getFrecuencia(MS);
 
 
 for (auto it=mimap.begin();it!=mimap.end();++it){
 
    cout<<(*it).first<<" "<<(*it).second<<endl;
 }

}
