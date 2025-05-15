/**
 * @file AND.h
 * @brief Implementation of the AND gate, 2 inputs, mutiplies incoming signals
 */

#ifndef ANDG
#define ANDG

#include <iostream>
#include <string>
#include "gate.h"

using std::string;
using std::cout;
using std::endl;

class AND : public gate
{
    string name = "AND";
public:
    AND();
    AND(int iID);
    AND(gate *i1, gate *i2, int iID);
    void setInputs(gate *i1, gate *i2);

    /**
    * @brief Calculates value of gate
    * @details Calls the calculate() of the 2 input gates and multiplies them together
    * @return true 
    * @return false 
    */
    bool calculate();

    string getName();
    int getID();
    bool getVal();

    ~AND();
    void write(std::ostream& os = std::cout);
};


#endif