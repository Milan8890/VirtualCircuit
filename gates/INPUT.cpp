#include "INPUT.h"

INPUT::INPUT(int iID)
{
    id = iID;
}

bool INPUT::calculate()
{
    return val;
}


void INPUT::changeValue(bool in)
{
    val = in;
}

string INPUT::getName()
{
    return name;
}

int INPUT::getID()
{
    return id;
}

bool INPUT::getVal()
{
    return val;
}

void INPUT::write(std::ostream& os)
{
    os << getName() << " id: " << getID() << " val: " << getVal() << "\n";
}
