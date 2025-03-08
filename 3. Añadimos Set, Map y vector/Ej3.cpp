
#include <iostream>
#include <set>
#include<map>
using namespace std;




int cuentavocales(const string & s){
	set<char> vocales({'a','e','i','o','u'});
	int contador=0;
	
	for(int i=0;i<s.size();i++){
		if(vocales.find(s[i]) != vocales.end()){
		
			contador++;
		}
	
	}
	
	return contador;
}

map<string,int> getNumVocales(const set<string>&s){
	map<string,int> out;
	set<string>::const_iterator it;
	
	for(it = s.cbegin() ; it != s.cend() ; ++it){
		
		int nv = cuentavocales(*it);
		out.emplace(*it,nv); 		//out.insert(make_pair(*it,nv));
	
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

