/**
 * @file gate.h
 * @brief abstract parent class of every gate
 */
#ifndef GATE
#define GATE

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "../memtrace.h"

using std::string;
using std::cout;
using std::endl;

class gate
{
protected:

    bool val = NULL;
    int id = 0;
    gate **in;
    string name = "gate";
    
public:

    /**
     * @brief retruns name of gate, used for printing
     * 
     * @return string 
     */
    virtual string getName() = 0;

    /**
     * @brief returns id of gate, used for printing
     * 
     * @return int 
     */
    virtual int getID() = 0;

    /**
     * @brief returns the value of the gate, used for printing
     * 
     * @return true 
     * @return false 
     */
    virtual bool getVal() = 0;
    
    /**
     * @brief writes to a given strem: name, id, value
     * 
     * @param os
     */
    virtual void write(std::ostream& os = std::cout) = 0;

    /**
     * @brief calculates based on gate type
     * 
     * @return true 
     * @return false 
     */
    virtual bool calculate() = 0;

    /**
     * @brief if the default constructor is used, can be called to set the input gates
     * 
     * @param i1 
     * @param i2 
     */
    virtual void setInputs(gate *i1, gate *i2) = 0;
    virtual ~gate(){};
};


#endif