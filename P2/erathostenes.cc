
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 *
 * @author Daniel Perez Lozano
 * @email alu0101339542@ull.edu.es
 * @date 9 Oct 2020
 * @brief Criba de Erasthostenes
 *
 * @see http://www.cplusplus.com/doc/tutorial/program_structure/
 * @see http://cpp.sh/2dd
 */

#include <iostream>
#include <vector>

using namespace std;

// It prints the vector numbers elements along  with a Y for prime or a N for 
// not prime
void Printvect(vector<int> numbers, vector<bool> prime){
  for(unsigned int i = 0; i < numbers.size(); i++){
    cout << numbers.at(i) << "(";
    if(prime.at(i) == false)
      cout << "N), ";
    if(prime.at(i) == true)
      cout << "Y), ";
  }
}
// Will delete every element that is not prime from both vectors
void Delnotprime(vector<int> &numbers, vector<bool> &prime){
  vector<bool>::iterator it;
  vector<int>::iterator itn;

  itn = numbers.begin();
  for (it = prime.begin(); it != prime.end(); ++it){  
    if(*it == false){
      prime.erase(it);
      numbers.erase(itn);
      it--;
      continue;
    }
    itn ++;
  }  
} 

// Will mark from that point in the list onwards all the values ​​that are multiples of the chosen one,
// as not prime.
void Removeprimes(int i, vector<bool> &prime, vector<int> numbers){
  for(unsigned int j = i + 1; j < numbers.size(); j++){
    if(numbers[j] % numbers[i] == 0)
      prime[j] = 0;
  }
}

// It will operate on the list of values ​​and it will mark multiples of 2, 3, 5, etc. as non-prime. 
// To do this, it will locate a value that is prime and invoke the Remove function
void Sieve(vector<int> &numbers, vector<bool> &prime){
  for(unsigned int i = 0; i < numbers.size(); i++){
    if(prime[i] == true)
      Removeprimes(i, prime, numbers);
  }
}

int main(int argc, char *argv[]){
  vector<int> numbers;
  vector<bool> prime;

  if(argc != 2){
    cout << "Syntax error: " << argv[0] << " " << " Natural number " << endl;
    //return -1;
  }
  // Argv[0] is the command name, argv[1] is the first argument and so on
  int N = stoi(argv[1]);
  // Fills the vector with values from 2 to N 
  numbers.resize(N - 1);
  prime.resize(numbers.size(), true);

  for(int i = 0; i < N - 1; i++)
    numbers[i] = i + 2;

  Sieve(numbers, prime);
  Printvect(numbers, prime);
  cout << endl;
  Delnotprime(numbers, prime);
  Printvect(numbers, prime);  
}
