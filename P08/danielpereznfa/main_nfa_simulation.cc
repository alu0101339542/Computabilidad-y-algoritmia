/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 *
 * @author Daniel Perez Lozano
 * @email alu0101339542@ull.edu.es
 * @date 21 Nov 2020
 * @brief Given a NFA from a file and a bounch of strings from another file the program should check if
 *  the given strings are accepted by the NFA and store the result in a 3rd file
 * @see http://www.cplusplus.com/doc/tutorial/program_structure/
 * @see http://cpp.sh/2dd
 * @compile  g++ -std=c++14 -g -Wall -o nfa_simulation nfa_simulation.cc main_nfa_simulation.cc
*/
#include "nfa_simulation.h"

int main(int argc, char *argv[]) {
  ifstream input_file;
  ifstream nfa_data;
  ofstream output_file;
  string line;
  bool result;

  int file_check;
  /*! Check if the files are good */
  file_check = CheckInput(argc, argv);
  if (file_check == -1) {
    return -1;
  }
  Nfa nfa1(argv[1]);
  //cout << nfa1;
  input_file.open(argv[2]);
  output_file.open(argv[3]);
  while(getline(input_file, line)){
    result = nfa1.NfaSimulate(line);
    Writeoutput(line, result, output_file);
  }
  /*if(result)
    cout << "String accepted" <<  endl;
  else {
    cout << "String not accepted" << endl;
  }
  */
  return 0;
}