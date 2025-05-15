#include "list.h"


List::List(gate *in)
{
    n++;
    data = new gate*[1];
    data[0] = in;
}

size_t List::count() const
{
    return n;
}

void List::add(gate *in)
{
    if(data != nullptr)
    {
        gate **r = new gate*[n+1];
        for(size_t i = 0; i < n; i++)
            r[i] = data[i];

        r[n] = in;
        delete[] data;
        data = r;
        n++;
    }
    else
    {
        data = new gate*[1];
        data[0] = in;
        n = 1;
    }
}


void List::remove(size_t t)
{
    if(t >= n)
        throw std::out_of_range("ajaj");
    
    gate **r = new gate*[n-1];
    size_t te = 0;
    for(size_t i = 0; i < n; i++)
    {
        if(i != t)
        {
            r[te] = data[i];
            te++;
        }
        else
            delete data[i];
    }

    delete[] data;
    data = r;
    n--;
}

gate* List::operator[](size_t i) const
{
    if(i >= count())
        throw std::out_of_range("ajaj");
        
    return data[i];
}


string List::getType() const
{
    if(n > 1)
    {
        for(size_t i = 1; i < n; i++)
        {
            if(data[i]->getName() != data[i-1]->getName())
                return("multiple types");
        }
    }

    if(n > 0)
        return data[0]->getName();
    
    return "";
}

List::~List()
{
    for(size_t i = 0; i < n; i++)
    {
        delete data[i];
    }
    
    delete[] data;
}