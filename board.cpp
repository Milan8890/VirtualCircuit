#include "board.h"
#include "memtrace.h"

List* Board::findType(string type)
{
    for(size_t i = 0; i < typeCount; i++)
    {
        if(gates[i].getType() == type)
            return &gates[i];
    }

    return nullptr;
}

void Board::prepareCircuit(string fileName)
{
    gates = new List[6];
    std::ifstream is(fileName);

    if(!is.good())
    {
        clear();
        throw "File doesn't exist\n";
    }

    int nonInGate = 0;

    string cName;
    int amount;
    do
    {
        is >> cName;
        is >> amount;

        typeCount++;

        List* temp;
        temp = findType(cName);
        if(temp == nullptr)
        {
            int x = 0;
            while (gates[x].getType() != "")
                x++;
            
            temp = &gates[x];
        }

        if(cName == "INPUT") 
        {   
            for(int i = 0; i < amount; i++)
                temp->add(new INPUT(i));
        }
        else if(cName == "AND")
        {
            for(int i = 0; i < amount; i++)
                temp->add(new AND(i));
        }
        else if(cName == "OR")
        {
            for(int i = 0; i < amount; i++)
                temp->add(new OR(i));
        }
        else if(cName == "XOR")
        {
            for(int i = 0; i < amount; i++)
                temp->add(new XOR(i));
        }
        else if(cName == "NOT")
        {
            for(int i = 0; i < amount; i++)
                temp->add(new NOT(i));
        }
        else if(cName == "OUTPUT")
        {
            for(int i = 0; i < amount; i++)
                temp->add(new OUTPUT(i));
        }
        else
        {
            clear();
            throw "Problem in file, non existent gate name\n";
        }
            

        if(cName != "INPUT")
            nonInGate += amount;
    }
    while (cName != "OUTPUT");
    string g0, g1, g2;
    size_t i0,i1,i2;

    int setNumber = 0;
    while(true)
    {
        is >> g0;
        if(g0 == "END")
            break;

        is >> i0;
        List* temp0 = findType(g0);
        if(g0 != "NOT" && g0 != "OUTPUT")
        {
            is >> g1;
            is >> i1;
            List* temp1 = findType(g1);

            is >> g2;
            is >> i2;
            List* temp2 = findType(g2);

            
            if((*temp0).count() <= i0 || (*temp1).count() <= i1 || (*temp2).count() <= i2)
            {
                clear();
                throw "Problem in file, bad index\n";
            }
                

            (*temp0)[i0]->setInputs((*temp1)[i1], (*temp2)[i2]);
            setNumber++;
        }
        else if(g0 == "NOT" || g0 == "OUTPUT")
        {
            is >> g1;
            is >> i1;
            List* temp1 = findType(g1);

            if((*temp0).count() <= i0 || (*temp1).count() <= i1)
            {
                clear();
                throw "Problem in file, bad index\n";
            }
                

            (*temp0)[i0]->setInputs((*temp1)[i1], nullptr);
            setNumber++;
        }
        else
        {
            clear();
            throw "Problem in file, non existent gate name\n";
        }
    }

    if(setNumber < nonInGate)
    {
        clear();
        throw "Problem in file, some gate inputs are missing\n";
    }
        
}

void Board::calculate(string inputVal, std::ostream& os)
{   

    List *inGates = findType("INPUT");

    if(inGates->count() != strlen(inputVal.c_str()))
        throw "Too many or too few input values";
    
    for(size_t i = 0; i < inGates->count(); i++)
    {
        INPUT *temp = dynamic_cast<INPUT*>((*inGates)[i]);
        temp->changeValue(inputVal[i] == '1');
    }
        
    List *outGates = findType("OUTPUT");

    os << "___________________\n\n";
    for(size_t j = 0; j < outGates->count(); j++)
    {
        (*outGates)[j]->calculate();
        (*outGates)[j]->write(os);
    }
    os << "___________________\n";

}

void Board::printAllResults(std::ostream& out) const
{
    for(size_t i = 0; i < typeCount; i++)
    {
        for(size_t j = 0; j < gates[i].count(); j++)
            gates[i][j]->write(out);

        out << "\n";
    }
}

int Board::types()
{
    return typeCount;
}

int Board::inputNum()
{
    return findType("INPUT")->count();
}

void Board::clear()
{
    delete[] gates;
    typeCount = 0;
}

Board::~Board()
{
    if(typeCount > 0)
        clear();
}