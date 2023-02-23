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

class Miset {
  public:
    Miset();
    Miset(int set_size);
    ~Miset();
    int Setnlong(int newsize);
    int Getsz(void) const;
    int Store(int element);

    bool operator ==(const Miset &other) const;
    Miset operator +(const Miset& other);
    Miset operator -(const Miset& other);
    Miset operator *(const Miset& other);
    Miset & operator =(const Miset &other);
    Miset & operator !=(const Miset &other);
 
  private:
    unsigned long int setl;
    int nlongs; /*!< Number of longs that are being used in this object */
    vector<unsigned long int> setv;
    
    
};

ostream &operator <<(ostream &, const Miset &);
istream &operator >>(istream &, Miset &);

