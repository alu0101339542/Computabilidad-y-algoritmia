// Standard Template Library example using a class.

#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <fstream>


using namespace std;

// The Set STL template requires overloading operators =, == and <.
int read_set_from_input(string inpset, vector<int> & elements){
  int num;
  stringstream s_stream(inpset); //create string stream from the string

  while(s_stream.good()) {
    string substr;
    getline(s_stream, substr, ','); //get first string delimited by comma
    stringstream elem(substr);
    elem >> num;
    elements.push_back(num);
  }
  return elements.size();
}

int lee(istream & input){
  string line;
  vector<int> set1, set2;
  int set1sz, set2sz;

  std::getline(input, line);
  //std::stringstream linestream(line);
  // Search the first set
  std::size_t posini1 = line.find("{");      // position of "{" in str
  std::size_t posfin1 = line.find("}");

  std::string tmpstr = line.substr (posini1+1,(posfin1-1)-(posini1));  
  set1sz=read_set_from_input(tmpstr, set1);

 // Search the second set
  std::size_t posini2 = line.rfind("{");      // position of "{" in str
  std::size_t posfin2 = line.rfind("}");

  std::string tmpstr2 = line.substr (posini2+1,(posfin2-1)-(posini2)); 
  set2sz=read_set_from_input(tmpstr2, set2);

// Search the operation

  std::string tmpstr3 = line.substr (posfin1+2,(posini2-2)-(posfin1+1)); 

  if (! tmpstr3.compare("+"))
    cout << "Union " << "{" << tmpstr << "} U {" << tmpstr2 <<"}" << endl;
  else if (! tmpstr3.compare("*"))
    cout << "Intersection " << "{" << tmpstr << "} N {" << tmpstr2 <<"}" << endl;
  else
    cout << "operation " << tmpstr3 << "not sopported" <<endl;
  
/*
  while(s_stream.good()) {
    string substr;
    getline(s_stream, substr, ','); //get first string delimited by comma
    stringstream elem(substr);
    elem >> num;
    // hacer algo con el numero

  }
*/

}

int main(){
  int num;
  int tot=0;
  string line;
  ifstream inFile;
    
  inFile.open("input.txt");
  if (!inFile) {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }
  lee(inFile);

 // cout << "introduce cadena" << endl;
/*  std::getline(std::cin, line);
  //std::stringstream linestream(line);
  
  std::size_t pos = line.find("{");      // position of "{" in str
  //std::size_t posfin = line.length()-1;
  std::size_t posfin = line.find("}");

  std::string str3 = line.substr (pos+1,posfin-1);  
  stringstream s_stream(str3); //create string stream from the string

  while(s_stream.good()) {
    string substr;
    getline(s_stream, substr, ','); //get first string delimited by comma
    stringstream geek(substr);
    geek >> num;
    // hacer algo con el numero
  }
*/
}
