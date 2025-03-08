#include <iostream>
#include <set>
#include<map>
using namespace std;

int cuenta_vocales(string str){
	int n=0;
	
	string::iterator it;
	
	for(it=str.begin(); it!=str.end(); ++it){
		if( (*it) == 'a' || (*it) == 'e' || (*it) == 'i' ||(*it) == 'o' || (*it) == 'u' ){
		
			n++;	
		}
	}

	return n;
}


map<string,int> getNumVocales(const set<string>&s){
	
	map<string,int> out;
	set<string>::const_iterator it1;
	int n_vocales;
	
	for(it1 = s.cbegin() ; it1 != s.cend() ; ++it1){
	
		n_vocales=cuenta_vocales(*it1);
		out.emplace((*it1),n_vocales);
	}	
	
	return out;
}


int main(){

	set<string> mis({"aguila", "alondra", "buho","buitre canario", "gavilan", "gaviota", "halcon"});
	map<string,int> mapa = getNumVocales(mis);
	
	for( auto it = mapa.begin(); it!=mapa.end(); ++it){
		cout<<"ANIMAL: " << (*it).first << "   NUMVOCALES: " << (*it).second <<endl;

	}	

	return 0;
}

