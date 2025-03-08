/*Dado un mapa con clave palabra en un documento e informaci�n asociada una lista de pares n�mero de p�gina y l�nea en
la p�gina donde aparece la palabra, crear la funci�n
set<string> getPalabrasPagina(const map<string,list<pair<int,int> > > & m,int pag)
que obtenga un conjunto con todas las palabras que aparecen en una determinada p�gina.
Ej
M={<Inform�tica,{<1,20>,<3,10}>,<Robot,{<3,20>,<10,15>,<4,1>}> ,<Sistema,{<2,10>,<10,5>}>}
Si preguntamos por la pagina 3 obtendr�amos
S={Inform�tica, Robot}*/
#include <iostream>
#include <set>
#include <map>
#include <list>
using namespace std;

set<string> getPalabrasPagina(const map<string,list<pair<int,int> > > & m,int pag){

	set<string> out;  
	map<string,list<pair<int,int>>>::const_iterator it;
	
	for( it = m.cbegin() ; it != m.cend() ; ++it){
		
		list<pair<int,int>> lista = (*it).second;
		list<pair<int,int>>::iterator it2;
		bool condicion=false; 	//Para hacer que pare de buscar la pagina si ya la ha encontrado
		
		for( it2 = lista.begin() ; it2 != lista.cend() && !condicion; ++it2){
			if ((*it2).first == pag || (*it2).second == pag){
			
				condicion=true;
				out.emplace((*it).first);
			}
		}
	}
	
  
  	return out;
}

int main(){
    map<string,list<pair<int,int> > > mimap({{"Inform�tica",{{1,20},{3,10}}},
                                            {"Robot",{{3,20},{10,15},{4,1}}} ,{"Sistema",{{2,10},{10,5}}}});
    set<string> miset= getPalabrasPagina(mimap,3);

    for (auto it = miset.begin(); it!=miset.end();++it)
        cout<<*it<<endl;

}
