/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 *
 * @author Daniel Perez Lozano
 * @email alu0101339542@ull.edu.es
 * @date 17 Jan 2021
 * @brief The Merge sort program
 * @see http://www.cplusplus.com/doc/tutorial/program_structure/
 * @see http://cpp.sh/2dd
 * @compile  g++ -std=c++14 -g -Wall -o Sortedvectort Sortedvectort.cc Sortedvectort.cc
*/

#pragma once 

#include <vector>
#include <iostream>

using namespace std;


namespace CyA {

  class Sortedvectort: public vector<int> {
  public:
      //Default costructor
      Sortedvectort(void):
      vector<int>() {}

      //constructor
      Sortedvectort(const vector<int>& v):
      vector<int>(v)  {}
      
      //destructor
      ~Sortedvectort(){}
      
      void Mergesort(void);
      
      void Write(ostream& os) const;

      void MergeSortIte(void);    
      
  private:
          
      void Createvectsentinel(int l, int r, vector<int>& v);
      void Merge(const vector<int>& v1, const vector<int>& v2, int l);
      
      void Mergesort(int l, int r);
      void Merge(int l, int c, int d);
      void MergeSubArray(int l1, int l2, int r1, int r2, vector<int> &temp);
  };

}

ostream& operator<<(ostream& os, const CyA::Sortedvectort& v);