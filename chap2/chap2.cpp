/*
Big picture:: 
We will take each of the topic and expand on it.
Excerpts are taken from the Excellent Video.
Thank you "Stephan T. Lavavej"


==================== PART 2 ==================================================================================================



*/
#include <iostream>
#include <ostream>
#include <algorithm>
#include<string>
using namespace std;
#define TEST1 1 
#include <map>
#include <unordered_map>
#include <functional>

#if TEST1
/*	 
     Associative Container: (maintains the key value pair key==> value) --  ordered containers store element in sorted order of key 
		map  - only contains unique keys. have a [] defined
		multimap - same key can be associated with many value (k,v1) (k,v2). Does not have [] defined. use member function find.
		set - do not have [] . element are automatically sorted.
		multiset - do not have []
		
	  c++0x:: (implemented by using hashes) -- more performance -- don't automaitcally sort their elements
		unordered_map
		unordered_mutimap
		unordered_set
		unordered_multiset
		


*/
void foo(const map<int,string> & m){ // m[] will not work
  cout<< m.find(3)->second<<endl;
  // cout << m[3] <<endl;  this will error out 
}

void bar(map<int,string> & m){
  cout << m[4] <<endl; // this is OK see how the argment is passed (no const)
}
int main(){

  map<int,string,greater<int>> m; // automaitcally sorted 
  m[1] = "one"; // nlog(n) time insertion.
  m[2] = "two";
  m[4]= "four";
  m[3]="three";
  m[1] = "ONE";
  cout<< m[2] <<endl;
  // notice keys are printed out in sorted order 	
  for(auto i = m.begin(); i != m.end() ; ++i){ // iterator to map returns pair<int,string> in this case
	cout<< "(" <<  i->first << "," << i->second << ")" << endl;
  }
  //implemented through hashes. // need to provide hash function and equality functoin if want to customize the unordered_map
  unordered_map<int , string> um;
  um[1] = "one"; // contant time insertion (amortized). Worst case O(n)
  um[2] = "two";
  um[4]= "four";
  um[3]="three";
  um[1] = "ONE";
  cout<< um[2] <<endl;
  	
}



#endif
