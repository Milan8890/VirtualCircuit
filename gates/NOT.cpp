#include "NOT.h"

NOT::NOT()
{
    in = new gate*[1];
}

NOT::NOT(int iID) : NOT()
{
    id = iID;
}

NOT::NOT(gate *ing, int iID)
{
    in = new gate*[1];
    in[0] = ing;
    id = iID;
}


bool NOT::calculate()
{
    val = !in[0]->calculate();
    return val;
}

void NOT::setInputs(gate *ing, gate *n)
{
    in[0] = ing;
}


string NOT::getName()
{
    return name;
}


int NOT::getID()
{
    return id;
}


bool NOT::getVal()
{
    return val;
}


void NOT::write(std::ostream& os)
{
        os << getName() << " id: " << getID() << " val: " << getVal() << "\n";
}

NOT::~NOT()
{
    delete[] in;
}
