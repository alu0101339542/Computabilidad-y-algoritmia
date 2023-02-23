/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 *
 * @author Daniel Perez Lozano
 * @email alu0101339542@ull.edu.es
 * @date 17 Jan 2021
 * @brief The merge sort program
 * @see http://www.cplusplus.com/doc/tutorial/program_structure/
 * @see http://cpp.sh/2dd
 * @compile  g++ -std=c++14 -g -Wall -o sorted_vector_t sorted_vector_t.cc sorted_vector_t.cc
*/
#include <cstdio>
#include <vector>
#include <random>
#include <iostream>

#include "sorted_vector_t.h"

#define LIMIT 999
#define SIZE   30


using namespace std;

int main(void) {	
    default_random_engine generator;
    uniform_int_distribution<int> distribution(-LIMIT, LIMIT); //This distribution produces random integers in a range [a,b] 
                                                               //where each possible value has an equal likelihood of being produced 
    //Generate a vector with random numbers
    CyA::Sortedvectort v;
    
    for(int i = 0; i < SIZE; i++)
        v.push_back(distribution(generator));
   /* static const int arr[] = {3,1,4,1,5};
    for(int i = 0; i < 5; i++)
        v.push_back(arr[i]);*/
    //print the original vector  
    cout << v << endl;
    
    //call the method that sorts the vector
    //v.MergeSortIte();
    v.Mergesort();
    
    //print the result
    cout << v << endl;
    
	return 0;
}