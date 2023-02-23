/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 *
 * @author Daniel Perez Lozano
 * @email alu0101339542@ull.edu.es
 * @date 23 Oct 2020
 * @brief  
 * @see http://www.cplusplus.com/doc/tutorial/program_structure/
 * @see http://cpp.sh/2dd
 * @compile g++ -std=c++14 -g -Wall -o palindrome_prod palindrome_prod.cc 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class word{
  public:
    word();
    word(char w1, char w2);
    ~word();
    string Genfibword(int position);
    int Compare_strings(string givenstr);

  private:
    char word_1;
    char word_2;
};