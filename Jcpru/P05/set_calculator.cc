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
Miset::Miset(){
  setv.resize(1);
  nlongs = 1;
}
Miset::Miset(int set_size){
  setv.resize(ceil(set_size/(sizeof(long int) * 8)));
  nlongs = ceil(set_size/(sizeof(long int)));
}
Miset::~Miset(){
  setv.clear();
  setl = 0;
}
int Miset::Setnlong(int newsize){
  nlongs = newsize;
  return 0;
}

int Miset::Getsz(void) const{
  return nlongs;
}

int Miset::Store(int num){
  long int val_to_store = 1;
  int vec_indx;
//  long aux;
  vec_indx = num / (sizeof(long) * 8);
//  aux = num - sizeof(long) * 8 * vec_indx;
  val_to_store = val_to_store << num;

  if(vec_indx > nlongs){
    setv.push_back(vec_indx - nlongs);
    Setnlong(vec_indx); 
  }
  setv[vec_indx] = val_to_store |setv.at(vec_indx);
  return 0;
}


istream &operator >>(istream & input, Miset & fill_set){
  string line;
  int num;

  std::getline(input, line);
  //std::stringstream linestream(line);
  
  std::size_t posini = line.find("{");      // position of "{" in str
  std::size_t posfin = line.find("}");

  std::string tmpstr = line.substr (posini+1,posfin-1);  
  stringstream s_stream(tmpstr); //create string stream from the string

  while(s_stream.good()) {
    string substr;
    getline(s_stream, substr, ','); //get first string delimited by comma
    stringstream elem(substr);
    elem >> num;
  }
  
}

Miset Miset::operator +(const Miset& other){
  int newsize;
  if(this->Getsz() > other.Getsz())
    newsize=Getsz();
    //Miset result(Getsz());
  else
  //  Miset result(other.Getsz());
    newsize=other.Getsz();

  Miset result(newsize);
  
  for(int i = 0; i < newsize ; i++)
    result.setv[i] = setv.at(i) | other.setv.at(i);
  return result;
}

Miset  Miset::operator *(const Miset& other){
  int newsize;
  if(this->Getsz() < other.Getsz())
    newsize = Getsz();
  else
    newsize=other.Getsz();
   
  Miset result(newsize);

  for(int i = 0; i < newsize; i++)
    result.setv[i] = setv.at(i) & other.setv.at(i);
  return result;
}

bool Miset::operator ==(const Miset &other) const{
   if( this->setv == other.setv) 
    return true;
   else
    return false;
}

Miset& Miset::operator =(const Miset &other){
   this->setv = other.setv;
   Setnlong(other.Getsz());
   return *this;
}
