#include "OUTPUT.h"

OUTPUT::OUTPUT()
{
    in = new gate*[1];
}

OUTPUT::OUTPUT(int iID) : OUTPUT()
{
    id = iID;
}

OUTPUT::OUTPUT(gate *ing, int iID)
{
    in = new gate*[1];
    in[0] = ing;
    id = iID;
}

bool OUTPUT::calculate()
{
    val = in[0]->calculate();
    return val;
}


void OUTPUT::setInputs(gate *ing, gate *n)
{
    in[0] = ing;
}

string OUTPUT::getName()
{
    return name;
}

int OUTPUT::getID()
{
    return id;
}


bool OUTPUT::getVal()
{
    return val;
}

void OUTPUT::write(std::ostream& os)
{
    os << getName() << " id: " << getID() << " val: " << getVal() << "\n";
}

OUTPUT::~OUTPUT()
{
    delete[] in;
}