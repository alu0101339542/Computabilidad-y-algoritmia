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

/** Here it will be checked whether the given values from the command line are the ones expected 
  * and it will take action depending on what they are
  */
int main(int argc, char *argv[]){
  if(argc == 2 && string(argv[1]) == "--help") {
    cout << "The program expects two parameters $> ./set_calculator input.txt output.txt" << endl;
    cout << "input.txt indicates the filename where it will take the sets form" << endl;
    cout << "output.txt is the filename where the words will get stored with its position" << endl;
    return -1;
  }
   if(argc != 3) {
    cout << "Syntax error: " << argv[0] << " was expecting the name of the input and the output file." << endl;
    cout << "--help for more information " << endl;
    return -1;
  } 

  return 0;
}
