/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 *
 * @author Daniel Perez Lozano
 * @email alu0101339542@ull.edu.es
 * @date 9 Oct 2020
 * @brief Criba de Erasthostenes, the point of this program is to create an algorithm that finds all 
 * the prime numbers from 0 to the given number
 *
 * @see http://www.cplusplus.com/doc/tutorial/program_structure/
 * @see http://cpp.sh/2dd
 * @compile g++ -std=c++14 -g -Wall -o erathostenes erathostenes.cc 
 */

#include <iostream>
#include <vector>

using namespace std;

void Printvect(vector<int> numbers, vector<bool> prime);
void Delnotprime(vector<int> &numbers, vector<bool> &prime);
void Sieve(vector<int> &numbers, vector<bool> &prime);
void Removeprimes(int i, vector<bool> &prime, vector<int> numbers);
