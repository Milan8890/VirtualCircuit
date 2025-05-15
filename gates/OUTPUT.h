/**
 * @file OUTPUT.h
 * @brief Implementation of the OUTPUT, 1 input, only saves and passes along the signal
 */

#ifndef OUTPUTG
#define OUTPUTG

#include <iostream>
#include <string>
#include "gate.h"

using std::string;
using std::cout;
using std::endl;

class OUTPUT : public gate
{
    string name = "OUTPUT";
public:
    string getName();
    int getID();
    bool getVal();

    OUTPUT();
    OUTPUT(int iID);
    OUTPUT(gate *ing, int iID);
    void setInputs(gate *ing, gate *n);

    /**
    * @brief Calculates value of gate
    * @details doesn't change the incoming signal just stores it
    * @return true 
    * @return false 
    */
    bool calculate();
    ~OUTPUT();

    void write(std::ostream& os = std::cout);
};


#endif