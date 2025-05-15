/**
 * @file INPUT.h
 * @brief Implementation of the INPUT, first line of "gates" no inputs just sends a given signal forward
 */

#ifndef INPUTG
#define INPUTG

#include <iostream>
#include <string>
#include "gate.h"

using std::string;
using std::cout;
using std::endl;

class INPUT : public gate
{
    string name = "INPUT";
public:
    string getName();
    int getID();
    bool getVal();

    INPUT(){}
    INPUT(int iID);

    /**
    * @brief no calculations done just sand signal forward
    * 
    * @return true 
    * @return false 
    */
    bool calculate();

    /**
    * @brief extra function in INPUT so the value can be changed without needing to rebuild the circuit
    * 
    * @param in 
    */
    void changeValue(bool);

    /**
     * @brief empty function since this doesnt have any inputs
     * 
     * @param i1 
     * @param i2 
     */
    void setInputs(gate *i1, gate *i2){}

    void write(std::ostream& os = std::cout);

    /**
    * @brief only empty destructor since no input gates
    * 
    */
    ~INPUT(){}

  
};


#endif