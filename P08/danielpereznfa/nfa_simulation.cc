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

/** This method checks if the given files are good */
int CheckInput(int argc, char *argv[]){
  ifstream input_file;
  ifstream nfa_data;
  ofstream output_file;
  nfa_data.open(argv[1]);
  input_file.open(argv[2]);

  if(argc != 4) {
    cout << "Syntax error: " << argv[0] << " was expecting the name of the nfa the strings file and the output file." << endl;
    cout << "--help for more information " << endl;
    return -1;
  } 
  if(nfa_data.fail()) {
    cout << "Error opening nfa file" << argv[1] << endl;
    //cerr << "Error: " << strerror(errno);
    return -1;
  }
  if(nfa_data.peek() == std::ifstream::traits_type::eof()) {
    cout<< "The nfa file is empty" << endl;
    return -1;
  }
  if(input_file.fail()) {
    cout << "Error opening input file" << argv[2] << endl;
    //cerr << "Error: " << strerror(errno);
    return -1;
  }
  if(input_file.peek() == std::ifstream::traits_type::eof()) {
    cout<< "The input file is empty" << endl;
    return -1;
  }
  output_file.open(argv[3]);
  if(output_file.fail()){
    cout << "Error opening output file" << endl;
    return -1;
  }
  if(argc == 2 && string(argv[1]) == "--help") {
    cout << "The program expects three parameters $> ./nfa_simulation input.nfa input.txt output.txt " << endl;
    cout << "nfa_simulation.data indicates the filename where it will take the nfa form" << endl;
    cout << "input.txt indicates the filename where it will take the strings form" << endl;
    cout << "output.txt is the filename where the result will get stored " << endl;
    return -1;
  }
  nfa_data.close();
  input_file.close();
  output_file.close();
  return 0;
}

//! Constructor creates the NFA with the data from the file
Nfa::Nfa(string filename){
  ifstream nfa_data;
  symbolcount = 1;
  alphabet.insert(pair<char,int>('~',0));
  nfa_data.open(filename);
  ReadNumberStates(nfa_data);
  for(unsigned int i = 0; i < nstates; i++)
    delta[i].resize(symbolcount);
  ReadInitState(nfa_data);
  for(unsigned int i = 0; i < nstates; i++){
    ReadTransition(nfa_data);
  }
  nfa_data.close();
}

//! Destructor
Nfa::~Nfa() {
  delta.clear();
  accepted_states.clear();
  alphabet.clear();
}

/** This mehod reads the file of the NFA and gets from it the number of states, we use that value
 * to resize the delta function set matrix, it returns the input but without the first value
 */
ifstream& Nfa::ReadNumberStates(ifstream &input) {
  string n_state;
  //string foo;
  input >> n_state;
  /*input >> foo;
  if(foo.erase().length() != 0){ //<< removes new line from string*/
    /*cout << "An error has been found while reading the NFA file: number of states"<< endl;
    exit(EXIT_FAILURE); 
  }*/
  nstates = stoi(n_state);
  delta.resize(nstates);
  return input;
}

/** This mehod reads the file of the NFA and gets from it the intial state, we use that value */
ifstream& Nfa::ReadInitState(ifstream &input) {
  string init_state;
  //string foo;
  input >> init_state;
  /*input >> foo;
  if(foo.erase().length() != 0){ //<< removes new line from string*/
    /*cout << "An error has been found while reading the NFA file: number of initial state"<< endl;
    exit(EXIT_FAILURE);
  }*/
  initial_state = stoi(init_state);
  return input;
}

/** This method reads the transition lines of the NFA file and stores each value where it belongs in the NFA class
 * it also calls the method of insert in Alphabet to store the new symbols in a map
 */
ifstream& Nfa::ReadTransition(ifstream &input) {
  string state, accept, ntrans, symbol, destin_state;
  input >> state >> accept >> ntrans;
  if(stoi(accept) == 1) {
    accepted_states.insert(stoi(state));
  }
  for(int i = 0; i < stoi(ntrans); i++) {
    input >> symbol >> destin_state;
    InsertInAlphabet(symbol[0]);
    delta[stoi(state)][alphabet[symbol[0]]].insert(stoi(destin_state));
  }

  return input;
}

/** To insert a symbol in an alphabet we use the class map that asociates a character with an index. To do this 
 * we define an iterator that will tell us if the symbol is already in the alphabet. If it is not it should be inserted
 */
bool Nfa::InsertInAlphabet(unsigned char symbol){
  map<unsigned char, unsigned int>::iterator it;
  if(symbol != '~') {
    it = alphabet.find(symbol);
    if(it == alphabet.end()) {
      alphabet.insert(pair<unsigned char, unsigned int>(symbol, symbolcount));
      symbolcount++;
      for(unsigned int i = 0; i < nstates; i++)
        delta[i].resize(symbolcount);

      return false; /*<< It was not in the alphabet already */
    }
  }
  return true;
}

/** With this method we obtain the epsilon transitions for a set of states*/
void Nfa::EpsClausure(set<int> current, set<int>& epsilonstates){
  int pstate;
  set<int> aux;
  stack<int> stk;
  for(auto it = current.begin(); it != current.end(); it ++) {
    stk.push(*it);
  }
  epsilonstates = current;
  while(!stk.empty()){
    pstate = stk.top();
    stk.pop();
    aux = delta[pstate][0];
    for(auto it = aux.begin(); it != aux.end(); it ++){
      if(epsilonstates.find(*it) == epsilonstates.end()){
        epsilonstates.insert(*it);
        stk.push(*it);
      } 
    }
  }
}

/** This method receives a set of states and obtains its transitions for a given symbol*/
void Nfa::SymbolTransition(unsigned char symbol, set<int> current, set<int>& next){
  set<int> tmp;
  for(auto it = current.begin(); it != current.end(); it ++) {
    if(!delta[*it][alphabet[symbol]].empty()){
      set_union(delta[*it][alphabet[symbol]].begin(), delta[*it][alphabet[symbol]].end(), next.begin(), next.end(), inserter(tmp, tmp.begin()));
      next = tmp;
    }
  }
}

/** This is the method that will be called in the main function. It recieves the input string. First it finds all the epsilon 
 * clausure transition states for the NFA's initial state. Once it has that it goes through all the transitions for each given symbol
 * in the string that we are supposed to check. Finaly using a set class method it makes the intersection of the result
 * that we obtained with the set of accepted states. If the result is different than empty, it means that it ends in a final state returning true
 */
bool Nfa::NfaSimulate(string input_string){
  set<int> current, epsilon_curr, next, endset;
  current.insert(initial_state);
  EpsClausure(current, epsilon_curr);
  for(long unsigned int i=0; i < input_string.size(); i++){
    if(!CheckSymbolInAlphabet(input_string[i])){
      cout << "A symbol that does not belong to the alphabet was found" << endl;
      return false;
    }
    SymbolTransition(input_string[i], epsilon_curr, next);
    epsilon_curr.clear();
    EpsClausure(next, epsilon_curr);
    next.clear();
  }
  set_intersection(epsilon_curr.begin(), epsilon_curr.end(), accepted_states.begin(), accepted_states.end(), inserter(endset, endset.begin()));
  if(!endset.empty())
    return true;
  else
    return false;
}

bool Nfa::CheckSymbolInAlphabet(unsigned char symbol){
  map<unsigned char, unsigned int>::iterator it;
  it = alphabet.find(symbol);
  if(it == alphabet.end()) {
    return false;
  }
  else{
    return true;
  }
}

/**Writes the output*/
void Writeoutput(string line, bool result, ofstream &output_file){
  if(result == false){
    output_file << line << " --> No " << endl;
  }
  else{
    output_file << line << " --> Si " << endl;
  }
}

/**Operator to write delta*/
ostream &operator <<(ostream & output, const Nfa & nfa_print){
  for(unsigned int j=0; j< nfa_print.nstates; j++){
    cout << "state n " << j;
    for(unsigned int k=0; k< nfa_print.symbolcount;k++){
      cout << " symbol " << k << " -->";
      for (auto it = nfa_print.delta[j][k].begin(); it != nfa_print.delta[j][k].end(); it++) 
        cout << *it << " "; 
      cout << endl;
    }
  }
  cout << "Accepted states ";
  for (auto it = nfa_print.accepted_states.begin(); it != nfa_print.accepted_states.end(); it++) 
        cout << *it << " "; 
      cout << endl;
  return output;
} 
