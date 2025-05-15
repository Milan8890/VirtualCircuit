#include "OR.h"

OR::OR()
{
    in = new gate*[2];
}

OR::OR(int iID) : OR()
{
    id = iID;
}

OR::OR(gate *i1, gate *i2, int iID)
{
    in = new gate*[2];
    in[0] = i1;
    in[1] = i2;
    id = iID;
}

bool OR::calculate()
{
    val = in[0]->calculate() + in[1]->calculate();
    return val;
}

void OR::setInputs(gate *i1, gate *i2)
{
    in[0] = i1;
    in[1] = i2;
}

string OR::getName()
{
    return name;
}


int OR::getID()
{
    return id;
}


bool OR::getVal()
{
    return val;
}

void OR::write(std::ostream& os)
{
    os << getName() << " id: " << getID() << " val: " << getVal() << "\n";
}

OR::~OR()
{
        delete[] in;
}