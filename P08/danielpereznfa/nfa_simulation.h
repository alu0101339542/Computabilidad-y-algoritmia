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
 * @compile  g++ -std=c++14 -g -Wall -o nfa_simulation nfa_simulation.cc nfa_simulation.cc
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
//#include <cmath>
#include <map>
#include <set>
#include <stack> 


using namespace std;

//! The Not Determisitic finite automata class
class Nfa {
  public:
    Nfa(string filename); /**< Default constructor */
    ~Nfa(); /**< Destructor */
    //void SetNstates(int number_of_states);
    ifstream& ReadNumberStates(ifstream &input);
    ifstream& ReadInitState(ifstream &input);
    ifstream& ReadTransition(ifstream &input);
    bool InsertInAlphabet(unsigned char symbol);
    void EpsClausure(set<int> current, set<int> & clone);
    void SymbolTransition(unsigned char symbol, set<int> current, set<int>& next);
    bool NfaSimulate(string input_string);
    bool CheckSymbolInAlphabet(unsigned char symbol);

    friend std::ostream& operator<<(std::ostream&, const Nfa&);
    private:
    map<unsigned char, unsigned int> alphabet;
    vector<vector<set<int>>> delta;
    set<unsigned int> accepted_states; 
    //vector<int> states;   
    unsigned int nstates;
    unsigned int initial_state;
    unsigned int n_accepted_states;
    unsigned int symbolcount;
};
int CheckInput(int argc, char **argv);
void Writeoutput(string line, bool result, ofstream &output_file);