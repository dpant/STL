/* 
  Big picture:: 
  We will take each of the topic and expand on it.
  Excerpts are taken from the Excellent Video.
  Thank you "Stephan T. Lavavej"


  =========================================================== PART 6 ==================================================================



*/
#include <iostream>
#include <ostream>
#include <algorithm>
#include <vector>
using namespace std;
#define TEST1 1 
/*	 
    STL algorithms
    use lamda's they are more readable ! and more efficient its a candidate for inlining 
    use handwrittend function object for recurstion and more compilcated stuff.       

*/

/* function object */
bool even (int n){ /* callback */
  return n %2 == 0;
}
#ifdef TEST1
int main(){
  vector<int> v;
  v.push_back(11);
  v.push_back(22);
  v.push_back(33);
  v.push_back(44);
  v.push_back(55);
  cout << count(v.begin(),v.end(),22) <<endl;
  cout << count_if(v.begin(),v.end(),even) <<endl;
  cout << count_if(v.begin(),v.end(),
				   [](int n ){ return n%2 == 0;}  
				   ) <<endl;  /* use lamda's as functors */
  vector<int> copyto(5); // must allocate otherwise the iterator will runover past the memory
   // remember the thrid argument (output iterator) should point to container having sufficient space to 
   // accomodate copy. otherwise undefined behaviour (crash et al)
  copy(v.begin(),v.end(),copyto.begin()); 

  
}

#endif

