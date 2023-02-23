/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 *
 * @author Daniel Perez Lozano
 * @email alu0101339542@ull.edu.es
 * @date 23 Oct 2020
 * @brief This program does basic set operations. That will be given from a file
 * @see http://www.cplusplus.com/doc/tutorial/program_structure/
 * @see http://cpp.sh/2dd
 * @compile  g++ -std=c++14 -g -Wall -o set_calculator set_calculator.cc main_set_calculator.cc
*/

#include "set_calculator.h"

//! Default constructor
Set::Set(){
  setv.resize(1);
  nlongs = 1;
}
Set::Set(int set_size){
  setv.resize(ceil(set_size/(sizeof(long int) * 8)));
  nlongs = ceil(set_size/(sizeof(long int)));
}
Set::~Set(){
  setv.clear();
  setl = 0;
}
int Set::Setnlong(int newsize){
  nlongs = newsize;
  return 0;
}

int Set::Getsz(void) const{
  return nlongs;
}

int Set::Store(int num){
  long int val_to_store = 1;
  int vec_indx;
  long aux;
  vec_indx = num / (sizeof(long) * 8);
  aux = num - sizeof(long) * 8 * vec_indx - 1;
  val_to_store = val_to_store << aux;

  if(vec_indx + 1 > nlongs){
    setv.push_back(vec_indx - nlongs);
    Setnlong(vec_indx + 1); 
  }
  setv[vec_indx] = val_to_store |setv.at(vec_indx);
  return 0;
}


/*istream &operator >>(istream & input, Set & fill_set){
  string line;
  vector<int> set1, set2;
  int set1sz, set2sz;
  
  std::getline(input, line);
  //std::stringstream linestream(line);
  // Search the first set
  std::size_t posini1 = line.find("{");      // position of the first"{" in str
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
  
  return input;
}
*/

istream &operator >>(istream & input, Set & fill_set){
  vector<int> set1, set2;
  int set1sz;
  
  //std::getline(input, line);
  string aux;
  input >> aux;
  std::size_t posini = aux.find("{");
  std::string setstr = aux.substr (posini+1);
  input >> aux;
  while (aux.find("}")==string::npos){
    setstr = setstr + aux;
    input >> aux;
  } 
  std::size_t endpos = aux.find("}");
  std::string tmpstr = aux.substr (0,endpos); 
  setstr = setstr + tmpstr;
  //std::stringstream linestream(line);
  // Search the first set
  
  set1sz=read_set_from_input(setstr, set1);
  for( int i = 0; i < set1sz; i++){
    fill_set.Store(set1[i]);
  }

/*
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
  */
  return input;
}

Set Set::operator +(const Set& other){
  int newsize;
  if(this->Getsz() > other.Getsz())
    newsize=Getsz();
    //Set result(Getsz());
  else
  //  Set result(other.Getsz());
    newsize=other.Getsz();

  Set result(newsize);
  
  for(int i = 0; i < newsize ; i++)
    result.setv[i] = setv[i] | other.setv[i];
  return result;
}

Set  Set::operator *(const Set& other){
  int newsize;
  if(this->Getsz() < other.Getsz())
    newsize = Getsz();
  else
    newsize=other.Getsz();
   
  Set result(newsize);

  for(int i = 0; i < newsize; i++)
    result.setv[i] = setv.at(i) & other.setv.at(i);
  return result;
}

bool Set::operator ==(const Set &other) const{
   if( this->setv == other.setv) 
    return true;
   else
    return false;
}

Set& Set::operator =(const Set &other){
   this->setv = other.setv;
   Setnlong(other.Getsz());
   return *this;
}


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


