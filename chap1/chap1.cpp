/*
Big picture:: 
We will take each of the topic and expand on it.
Excerpts are taken from the Excellent Video.
Thank you "Stephan T. Lavavej"


==================== PART 1 ==================================================================================================



*/
#include <iostream>
#include <ostream>
#include <algorithm>
#include<string>
#define TEST1 1 
#include <vector>
#include <functional>

#if TEST1
/*	 Sequence Container: (maintains the sequence of elements)
		vector
		list
		deque
		forward_list

	 Vector is sequence container, maintain the sequence of elements 
	 contiguous elements
	 Resizing will be needed time to time when you push more elment.
      - do a geometric allocation. new_no_of_element  = k * (previous_no_of_element)
	  -	k is 1.5 in Visual studio.
      - time is insert an element is "amortized time" constant.
	  - Don't do new_no_of_element  = k + (previous_no_of_element). This will give quardratic time of insert.

iterators
	 	v.begin(),v.end() == [x,y) --> v.end() is 1  past the array.
        why is this ? Think of empty vector. its begin and end are same. more easy to model empty vector

		http://stackoverflow.com/questions/6673762/why-is-used-with-iterators

*/
int main(){

  std::vector<int> v; // should be a flexible array and should be contiguous.
  v.push_back(111);
  v.push_back(12);
  v.push_back(131);
  v.push_back(14);

  //v[5] = 100; // undefined behaviour

  std::cout << v.size() <<std::endl;
  for(size_t i = 0; i< v.size(); i++){ // think is v.size() fast enough for all containers... maybe not for list ?
	std::cout<< v[i]<< " "; // is [] operator overloaded for all conitainers?? Not for list.
  }

  // use iterators , more generric  way to do the iterations -- which works for all conitainers.
  std::cout<< std::endl;
  std::vector<int>::iterator i = v.begin() +1 ;
  std::cout<< *i <<std::endl;
  /* All iterators are equality comparable. (defines != et al)
     Only random access iterators are relationally comparable. (like of vector defines < )
     Input iterators, forward iterators, and bidirectional iterators are not relationally comparable. (eg List)
  */
  for(std::vector<int>::iterator i = v.begin(); i != v.end(); ++i){ // notice use of  != rather than < as it is defined for iterators. also notice ++i rather than i++, which is more faster as avoid use of temp
	std::cout<< *i << " ";
  }
  std::cout<< std::endl;
  
  // sort is not stable (equal elements are not gaurenteed to come out in same order as input)
  std::sort(v.begin(),v.end()); // Can i use sort for List? No , List does not support random access iterator.

  /* auto make i same as the one return by v.begin() */
  for(auto i = v.begin(); i != v.end(); ++i){ // need --std=c++0x in while compiling.
	std::cout<< *i << " ";
  }
  std::cout<< std::endl;

  std::vector<std::string> sv;
  
  sv.push_back("cat");
  sv.push_back("antelope");
  sv.push_back("puppy");
  sv.push_back("bear");
  sort(sv.begin(),sv.end(),std::greater<std::string>()); //third argument is function object or lambda expression 
  

  for(auto i = sv.begin(); i != sv.end(); ++i){ // need --std=c++0x in cmd line  while compiling.
  	std::cout<< *i  << " ";
  }
  std::cout<< std::endl;
  
   sort(sv.begin(),sv.end(),
	   [](const std::string& left,const std::string &right){
		 return left.size() < right.size();
  		}
  ); // lambda expression 
  for(auto i = sv.begin(); i != sv.end(); ++i){ // need --std=c++0x in cmd line  while compiling.
  	std::cout<< *i  << " ";
  }
  std::cout<< std::endl;

  stable_sort(sv.begin(),sv.end(),
	   [](const std::string& left,const std::string &right){
		 return left.size() < right.size();
  		}
  ); // mantain the order of equal element. Its a stable version. Less efficient than sort () 
  for(auto i = sv.begin(); i != sv.end(); ++i){ // need --std=c++0x in cmd line  while compiling.
  	std::cout<< *i  << " ";
  }
  std::cout<< std::endl;

  // linear time way to remove the element from vector
  //"remove erase  ideom"
  // dont use erase(). vector shift all the element. total runtime  O(n^2)
  // use std::remove()
  v.erase(remove_if(v.begin(),v.end(),
					[](int e){
					  return (e%2 == 1);
						     })
           ,v.end()
		  );
	
  for(auto i = v.begin(); i != v.end(); ++i){ // need --std=c++0x in cmd line  while compiling.
  	std::cout<< *i  << " ";
  }
  std::cout<< std::endl;



}
#endif
