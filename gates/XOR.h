/**
 * @file XOR.h
 * @brief Implementation of the XOR gate, 2 inputs
 */

#ifndef XORG
#define XORG

#include <iostream>
#include <string>
#include "gate.h"

using std::string;
using std::cout;
using std::endl;

class XOR : public gate
{
    string name = "XOR";
public:
    string getName();
    int getID();
    bool getVal();

    XOR();
    XOR(int iID);
    XOR(gate *i1, gate *i2, int iID);
    void setInputs(gate *i1, gate *i2);

    /**
    * @brief Calculates value of gate
    * @details calculates the exclusive-or of the two incoming signals
    * @return true 
    * @return false 
    */
    bool calculate();
    ~XOR();

    void write(std::ostream& os = std::cout);
};


#endif