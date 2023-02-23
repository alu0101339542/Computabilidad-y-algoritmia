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
 * @compile g++ -std=c++14 -g -Wall -o fibonacci_words fibonacci_words.cc 
 */
#include "fibonacci_words.h"

word::word(){
  word_1 = 'a';
  word_2 = 'b';
}
word::word(char w1, char w2){
  word_1 = w1;
  word_2 = w2;
}
word::~word(){
}

string word::Genfibword(int position) {
  string str;
  if (position == 1) { 
    str.push_back(word_1);
    return str;
  }
  if (position == 2) { 
    str.push_back(word_2);
    return str;
  }
  return Genfibword(position - 2) + Genfibword(position - 1);
}

int word::Compare_strings(string givenstr) {
  int position = 1;
  string str;
  do {
    if(Genfibword(position) == givenstr){
      str.clear();
      return position;
    }
    position ++;
  } while(Genfibword(position).length() <= givenstr.length());
  str.clear();
  return 0;
}

int main(int argc, char *argv[]) { 
  word fibo;
  string givenstr;
  ifstream input_file;
  ofstream output_file;
  int position;

  if(argc == 2 && string(argv[1]) == "--help") {
    cout << "The program expects two parameters $> ./fibonacci_words input.txt output.txt" << endl;
    cout << "input.txt indicates the filename where it will take the characters to check"
            "if they are a fibonacci word" << endl;
    cout << "output.txt is the filename where the words will get stored with its position" << endl;
    return -1;
  }
  if(argc != 3) {
    cout << "Syntax error: " << argv[0] << " was expecting the name of the input and the output file." << endl;
    cout<< "--help for more information " << endl;
    return -1;
  } 
  input_file.open(argv[1]);
  if(input_file.fail()){
    cout << "Error opening input file" << argv[1] << endl;
    cerr << "Error: " << strerror(errno);
    return -1;
  }
  output_file.open(argv[2]);
  if(output_file.fail()){
    cout << "Error opening output file" << endl;
    return -1;
  }
  while(getline(input_file, givenstr)){
    position = fibo.Compare_strings(givenstr);
    if(position == 0)
      output_file << givenstr << " is not a Fibonacci word" << endl;
    if(position != 0)
      output_file << givenstr << " is the word number" << position << endl;
  }
  
  input_file.close();
  output_file.close();
  return 0;
}

