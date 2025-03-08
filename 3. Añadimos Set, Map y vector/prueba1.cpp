
#include <iostream>
#include <set>
using namespace std;


bool soncomplementarios(const set<int> & s1,const set<int> &s2){
	
	if((s2.size() != (s1.size()-1))){
	
		return false; //s2 siempre tiene un tamaño menos que s1
	}
	
	set<int>::const_iterator it1,it2,it_sig;
	
	it1 = s1.cbegin();
	it2 = s2.cbegin();
	
	++it1;
	it_sig = it1;
	--it1;
	
	while( it_sig != s1.cend()){
		if(!(*it1 <= *it2 && *it2 < *it_sig)){
		
			return false;
		}
	
		++it1;
		++it2;
		++it_sig;
	}
	
	return true;
		
}

int main(){
	set<int> c1({1,5,7}),c2({2,6}),c3({2,3});
	
	if(soncomplementarios(c1,c2)){
	
		cout<<"Son complementarios "<<endl;
	}
	else{
	
		cout<<"No son complementarios "<<endl;
	}


	return 0;
}













/*set<int>::const_iterator it1,it2,it_sig,final;
	
	
	if(!(s1.size() != (s2.size()-1))){
		return false;
	}
	
	it1 = s1.cbegin();
	it2 = s2.cbegin();
	final = s1.cend(); --final;
	
	 while ( it1 != final ){ //Cuidado con la ultima iteracion, ya que it_sig siempre apunta una despues de it1
	 
	 	it_sig = it1;
	 	++it_sig;
	 	
	 	if(!( *it1 <= *it2  &&  *it2 < *it_sig)){
	 		cout<< *it1 << " " << *it2 << " " << *it_sig <<endl;
	 		return false;
	 	}
	 	++it1;
	 	++it2;
	 }
	 
	 return true;*/

