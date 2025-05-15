#include "AND.h"

AND::AND()
{
    in = new gate*[2];
}

AND::AND(int iID) : AND()
{
    id = iID;
}

AND::AND(gate *i1, gate *i2, int iID)
{
    in = new gate*[2];
    in[0] = i1;
    in[1] = i2;
    id = iID;
}

bool AND::calculate()
{
    val = in[0]->calculate() && in[1]->calculate();
    return val;
}


void AND::setInputs(gate *i1, gate *i2)
{
    in[0] = i1;
    in[1] = i2;
}


string AND::getName()
{
    return name;
}


int AND::getID()
{
    return id;
}


bool AND::getVal()
{
    return val;
}


void AND::write(std::ostream& os)
{
        os << getName() << " id: " << getID() << " val: " << getVal() << "\n";
}

AND::~AND()
{
    delete[] in;
}
