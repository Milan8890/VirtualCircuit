/**
 * @file OR.h
 * @brief Implementation of the OR gate, 2 inputs, adds incoming singals
 */

#ifndef ORG
#define ORG

#include <iostream>
#include <string>
#include "gate.h"

using std::string;
using std::cout;
using std::endl;

class OR : public gate
{
    string name = "OR";
public:
    string getName();
    int getID();
    bool getVal();

    OR();
    OR(int iID);
    OR(gate *i1, gate *i2, int iID);
    void setInputs(gate *i1, gate *i2);

    /**
    * @brief Calculates value of gate
    * @details adds the incoming 2 signals together
    * @return true 
    * @return false 
    */
    bool calculate();
    ~OR();

    void write(std::ostream& os = std::cout);
};


#endif