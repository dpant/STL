/* 
  Big picture:: 
  We will take each of the topic and expand on it.
  Excerpts are taken from the Excellent Video.
  Thank you "Stephan T. Lavavej"


  =========================================================== PART 7 ==================================================================



*/
#include <iostream>
#include <iterator>
#include <ostream>
#include <algorithm>
#include <vector>
using namespace std;
#define TEST2
/*	 
    STL algorithms
  	binary_search  -- make sure the array is sorted otherwise undefined behaviour
    lower_bound -- give you the index of the element found. input elements should be sorted.
    upper_bound - give you the index past the element found. input elements should be sorted.
    equal_range - will give you the pair of iterator (indicating range) . input elements should be sorted.
    strick weak ordering requirement:
       your comparision function should have strict weak ordering requiment satistified. think like implemneting
       < operator rather than <= . so X op X should return FALSE in your comparision function
       other wise STL algorithm behaviour is undefined.
     sort() - is not stable by default due to performance issue in stable_sort()
     stable_sort() is stable but less efficient than sort()
     parital_sort() sort top n element of the array.
	minmax_element() find the greatest and the smallest element. more efficient than running min and max seperately. complexity 1.5N ??
    min_elment()
    max_element()
    next_permutation()
	transform(first,last,result,op)
    random() ..
    

*/

#ifdef TEST1
int main(){
  vector<int> v;
  int arr[] = {10,20,30,40,50};
  v.push_back(5);
  v.push_back(7);
  int arr2[] = {110,111,112,113};
  // cout << endl << "Binary Search -  "  << binary_search(v.begin() ,v.end(),11) <<endl; // returns bool 
  copy(arr,arr + sizeof(arr)/sizeof(arr[0]),back_inserter(v));  // back_inserter makes space starting from the end of vector v
  for(auto i = v.begin(); i != v.end(); ++i){
	cout << *i << endl;
  }

  //returns the iterator to the element if it found. IF ELEMENT NOT FOUND RETURN THE INDEX BEFORE WHICH YOU CAN INSERT THE element and still make the container sorted 
  cout << endl << "Binary Search -  "  << binary_search(v.begin() ,v.end(),10) <<endl; // returns bool // make sure the array is sorted
  auto i = lower_bound (v.begin(),v.end(),50); 
  cout << endl << "found element at location index - " <<  i - v.begin() <<endl;

  // RANGE INSERSTIONS .insert RANGE OF ELEMENT just before the v.end() -- more efficient than copy as does vector reallocation all  at once
  v.insert(v.end(),arr2,arr2+sizeof(arr2)/sizeof(arr2[0])); 
  copy(v.begin(),v.end(),ostream_iterator<int>(cout, " "));
  cout <<endl;


  //sort 
  // Think at the end of sort (and at the time of sort) invariant "greater<int>(x,y) == true" is always mantained.
  sort(v.begin(),v.end(), greater<int>()); //sort in decending order user greater functor (function object)
  copy(v.begin(),v.end(),ostream_iterator<int>(cout, " "));
  cout <<endl;

}

#endif
/*
     sort() - is not stable by default due to performance issue in stable_sort()
     stable_sort() is stable but less efficient than sort()
     parital_sort() sort top n element of the array. [ think how can you implement partial_sort() ] 

 */
#ifdef TEST2
#include <memory>

class myClass{ /* class where i will apply sorting based on data member */
public :
  myClass(int i):data(i){}
  int data;
  ~myClass(){
  }
};
class myComp{ /* functor */
public :
  bool operator()(myClass l,myClass r){
	return l.data > r.data;
  }
  bool operator()(shared_ptr<myClass> l,shared_ptr<myClass> r){
	return l->data > r->data;
  }
};
/* 
   Demonstrate sorting of vector (based on object  member) 
   see how we use () at the end of myComp.
   if myComp would have written as plane old function we wont write paran at the end

*/
int main(){
  vector<shared_ptr<myClass>> v;
  for (int i =0 ; i< 100 ; i ++){ /* put in acending order later we will sort in decending order */
	v.push_back(make_shared<myClass>(i));
  } 

  for(auto i = v.begin(); i != v.end() ; i++){
	cout << (*i)->data << "  ";
  }

  partial_sort(v.begin(),v.begin()+10,v.end(),myComp());	// just make first 10 element in sorted order
  cout<< endl << "After Partial Sorting of 10 elements ..." <<endl;
  for(auto i = v.begin(); i != v.end() ; i++){
	cout << (*i)->data << "  ";
  }
  cout <<endl;


  sort(v.begin(),v.end(),myComp());	
  cout<< endl << "After Sorting..." <<endl;
  for(auto i = v.begin(); i != v.end() ; i++){
	cout << (*i)->data << "  ";
  }
  cout <<endl;


  //stable sort
  stable_sort(v.begin(),v.end(),myComp());	
  cout<< endl << "After stable Sorting..." <<endl;
  for(auto i = v.begin(); i != v.end() ; i++){
	cout << (*i)->data << "  ";
  }
  cout <<endl;
  return 0;

}
#endif
