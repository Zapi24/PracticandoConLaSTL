


#include <iostream>
#include <set>
using namespace std;


bool soncomplementarios(const set<int> & s1,const set<int> &s2){
	
	if(s2.size() != s1.size()-1 ){
	
	
		return false;
	}
	
	set<int>::const_iterator it1,it2,it_sig,final;
	
	it1=s1.cbegin();
	it2=s2.cbegin();
	final = s1.cend();	--final;
	
	while(it1 != final){
	
		it_sig = it1;
		++it_sig;
		
		if(!(*it1<=*it2 && *it2<*it_sig)){
			
			cout<< *it1 << " " << *it2 << " " << *it_sig <<endl;
			return false;
		}
		
		++it1;
		++it2;	
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

