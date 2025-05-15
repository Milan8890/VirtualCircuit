/**
 * @file board.h
 * @brief contains a dinamic list of gates, responsible for all the alculations and file management
 */

#ifndef BOARD
#define BOARD

#include <iostream>
#include <fstream>
#include <string>
#include "list.h"

using std::string;
using std::cout;
using std::endl;

class Board
{
    List* gates;
    size_t typeCount = 0;
public:
    Board(){}

    /**
    * @brief Searches the Lists for a type of gate, returns the List where it found it
    * 
    * @param type 
    * @return List* 
    */
    List* findType(string type);

    /**
    * @brief Sets up the circuit from a txt file
    * 1. creating the gates that are needed for the circuit
    * 2. making the connections between the gates
    * 
    * @param fileName 
    */
    void prepareCircuit(string fileName);

    /**
    * @brief   Calculates the output of the circuit with the given input values
    *          1. finds all of the INPUT-s and sets their signal to the given input
    *          2. finds all the OUTPUT-s and calls calculate() on every instance
    *          3. prints out the value of the OUTPUT-s 
    * 
    * @param inputVal 
    */
    void calculate(string inputVal, std::ostream& os = std::cout);

 
    /**
     * @brief Outputs all of the gates name, id, value to a given txt file
     * 
     * @param fileName 
     */
    void printAllResults(std::ostream& os = std::cout) const;

    /**
    * @brief number of different types of gates
    * 
    * @return int 
    */
    int types();

    /**
    * @brief number of input needed (numebr of INPUT-s)
    * 
    * @return int 
    */
    int inputNum();

    /**
     * @brief resets the board, deletes the lists
     * 
     */
    void clear();

    ~Board();
};


#endif