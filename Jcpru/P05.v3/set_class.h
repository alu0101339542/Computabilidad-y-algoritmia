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

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

class Set {
  public:
    Set();
    Set(int set_size);
    ~Set();
    int Setnlong(int newsize);
    int Getsz(void) const;
    int Store(int element);

    bool element_in_set(const char c);
    bool operator ==(const Set &other) const;
    Set operator +(const Set& other);
    Set operator -(const Set& other);
    Set operator *(const Set& other);
    Set & operator =(const Set &other);
    Set & operator !=(const Set &other);
 
  private:
    unsigned long int setl;
    int nlongs; /*!< Number of longs that are being used in this object */
    vector<unsigned long int> setv;
    
    
};

ostream &operator <<(ostream &, const Set &);
istream &operator >>(istream &, Set &);

int read_set_from_input(string inpset, vector<int> & elements);


