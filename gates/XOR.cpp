#include "XOR.h"

XOR::XOR()
{
    in = new gate*[2];
}

XOR::XOR(int iID) : XOR()
{
    id = iID;
}

XOR::XOR(gate *i1, gate *i2, int iID)
{
    in = new gate*[2];
    in[0] = i1;
    in[1] = i2;
    id = iID;
}

bool XOR::calculate()
{
    val = (in[0]->calculate() + in[1]->calculate()) && (!in[0]->calculate() + !in[1]->calculate());
    return val;
}

void XOR::setInputs(gate *i1, gate *i2)
{
    in[0] = i1;
    in[1] = i2;
}

string XOR::getName()
{
    return name;
}

int XOR::getID()
{
    return id;
}

bool XOR::getVal()
{
    return val;
}

void XOR::write(std::ostream& os)
{
    os << getName() << " id: " << getID() << " val: " << getVal() << "\n";
}

XOR::~XOR()
{
    delete[] in;
}