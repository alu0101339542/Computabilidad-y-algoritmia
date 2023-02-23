/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 *
 * @author Daniel Perez Lozano
 * @email alu0101339542@ull.edu.es
 * @date 17 Jan 2021
 * @brief The merge sort program
 * @see http://www.cplusplus.com/doc/tutorial/program_structure/
 * @see http://cpp.sh/2dd
 * @compile  g++ -std=c++14 -g -Wall -o Sortedvectort Sortedvectort.cc Sortedvectort.cc
*/

#include "sorted_vector_t.h"

#include <climits>
#include <iomanip>

namespace CyA {

//when Mergesort its called for the first time it generates the search range
void Sortedvectort::Mergesort(void) {
    Mergesort(0, size() - 1);
}

void Sortedvectort::Write(ostream& os) const {
    const int sz = size();

    os << "< ";
    for(int i = 0; i < sz; i++)
        os << setw(5) << at(i);
    os << "> ";
}


void Sortedvectort::Mergesort(int l, int r) {
    if (l < r) {
        
        int c = (l + r) / 2; //midpoint

        Mergesort(l, c); //Mergesort of the left

        Mergesort(c + 1, r); //Mergesort of the right

        Merge(l, c, r);
    }
}


////////////////////////////////////////////////////////////////////////////
// FUSIÓN CON CENTINELA
////////////////////////////////////////////////////////////////////////////

//Creates a vector v that has in its r+1 position a sentinel(a value that is too bif)
void Sortedvectort::Createvectsentinel(int l, int r, vector<int>& v) {
  #define sent 10000
  for(int i = l; i <= r; i++) {
    v.push_back(at(i));
  }
  //cout << "sale del for" << endl;
 //Once the vector is filled we add the sentinel in its last position
 v.push_back(sent);
}

void Sortedvectort::Merge(int l, int c, int d) {
  vector<int> leftsentinel; //Va &?? como arriba?
  vector<int> rightsentinel;
  unsigned i = 0, j = 0;
  Createvectsentinel(l, c, leftsentinel);
  Createvectsentinel(c + 1, d, rightsentinel);
  //Comprobamos que este bien el orden, o lo cambiamos si no
  for(int k = 0; k < leftsentinel.size() + rightsentinel.size() -2; k++) {
    if(leftsentinel.at(i) < rightsentinel.at(j)) {
      at(k + l) = leftsentinel[i]; //Esto no puede ser se esta sobrecargando en la posicion 0 todo el rato
      i++;
    }
    else {
      at(k + l) = rightsentinel[j];
      j++;
    }
   // cout<<"at "<< at(k) << endl;
  }
 // cout <<"sale "<<endl;
  //cout << *this << endl;
}


//Iterative

void Sortedvectort::MergeSubArray(int l1, int l2, int r1, int r2, vector<int> &temp){
  //int index = 0;
  while(l1 <= r1 && l2 <= r2)   {
    if(at(l1) <= at(l2)) {
      temp.push_back(at(l1)); //revisar
      //index ++;
      l1 ++;
    }
    else {
      temp.push_back(at(l2));
      l2 ++;
    }
  }
   while(l1 <= r1) {
      temp.push_back(at(l1)); //revisar
      l1 ++;
    }
    while(l2 <= r2) {
      temp.push_back(at(l2));
      l2 ++;
    }
}

void Sortedvectort::MergeSortIte(void) {
  int len = 1;
  int l1, l2, r1, r2;
  vector<int> temp;
  while(len < size()) {
    int i = 0;
    while( i < size()) {
      l1 = i;
      r1 = i + len -1;
      l2 = i + len;
      r2 = i + 2 * len -1;
      if (l2 >= size()) {
        break;
      }
      if(r2 >= size()) {
        r2 = size() -1;
      }
      MergeSubArray(l1, l2, r1, r2, temp);
      for(int j = 0; j <= r2 - l1; j++) {
        at(i + j) = temp[j];
      }
      temp.clear();
      i = i + 2 * len;
    }
    len = 2 * len;
  }
} 

}
ostream& operator<<(ostream& os, const CyA::Sortedvectort& v) {
    v.Write(os);
    return os;
}

