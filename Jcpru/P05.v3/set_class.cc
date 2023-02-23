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

#include "set_class.h"

//! Default constructor
Set::Set(){
  setv.resize(1);
  nlongs = 1;
}
Set::Set(int set_size){
  setv.resize(ceil(set_size/(sizeof(long int) * 8)));
  nlongs = ceil(set_size/(sizeof(long int)*8));
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
  aux = num - sizeof(long) * 8 * vec_indx ;
  val_to_store = val_to_store << aux;

  if(vec_indx + 1 > nlongs){
    setv.push_back(vec_indx - nlongs);
    Setnlong(vec_indx + 1); 
  }
  setv[vec_indx] = val_to_store |setv.at(vec_indx);
  return 0;
}



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
  if(this->Getsz() > other.Getsz())
    newsize = Getsz();
  else
    newsize=other.Getsz();
   
  Set result(newsize* (sizeof(long) * 8));

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
 // int aux, tmp=1;
  stringstream s_stream(inpset); //create string stream from the string

  while(s_stream.good()) {
    string substr;
    getline(s_stream, substr, ','); //get first string delimited by comma
    stringstream elem(substr);
    char a = elem.str()[0];
//    int num = int(a) - 97;
    int num = int(a);
    //int num = tmp << aux;
    //elem >> num;
    elements.push_back(num);
  }
  return elements.size();
}

bool Set::element_in_set(const char c){
  string tmps;
  stringstream tmp;
  int newsize;
  tmps.push_back(c);
  std::istringstream is(tmps);

  Set set2(this->Getsz()*(sizeof(long) * 8));
  Set set2;
  is >> set2;

  Set prod = *this * set2;
  newsize=prod.Getsz();
   
  for(int i = 0; i < newsize; i++)
    if(prod.setv[i] != 0)
      return true;
  return false;
}


