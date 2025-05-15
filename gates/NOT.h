/**
 * @file NOT.h
 * @brief Implementation of the NOT gate, 1 input, flips incoming signal
 */

#ifndef NOTG
#define NOTG

#include <iostream>
#include <string>
#include "gate.h"

using std::string;
using std::cout;
using std::endl;

class NOT : public gate
{
    string name = "NOT";
public:
    string getName();
    int getID();
    bool getVal();

    NOT();
    NOT(int iID);
    NOT(gate *ing, int iID);
    void setInputs(gate *ing, gate *n);

    /**
    * @brief flips incloming signal
    * 
    * @return true 
    * @return false 
    */
    bool calculate();
    ~NOT();

    void write(std::ostream& os = std::cout);
};


#endif