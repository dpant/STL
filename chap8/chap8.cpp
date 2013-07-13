/* 
  Big picture:: 
  We will take each of the topic and expand on it.
  Excerpts are taken from the Excellent Video.
  Thank you "Stephan T. Lavavej"


=========================================================== PART 8 ==================================================================



*/
#include <iostream>
#include <regex>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define TEST1
/*	
	gcc does not have full support for regular express. VC10 have it.
	
    STL algorithms
	regex_match --> have to match whole string
	regex_search --> can match substring.
    regex_replace

std::regex is typedef of std::basic_regex<char>
std::wregex is typedef of std::basic_regex<wchar>
C++ regex will work with any bidirectional iterator.

Bit of a Note: escaping the character.

You have to use \\d for digit. since the c++ compiler when it see 
\d it interpret as a special character (escape char) so passing \\d
will pass the correct thing to the regex oject.
*/

#ifdef TEST1
int main(){
  regex r("a(b+)(c+)d");	// construct the regex object r. can use raw string to avoid problem in escaping
  for(string s;getline(cin,s);){
	smatch m; // m[0] is special matches the whole matched pattern usefull for regex_search
    cout << s << endl;
	const bool b = regex_match(s,m, r);
	cout << b <<endl;
	if(b){
	  cout << m[0] << endl;
	  cout << m[1] << endl;
	  cout<<  m[2] << endl;
	}
	cout <<endl;
  }

}

#endif
