/**
 * @file list.h
 * @brief contains a dynamic array of gate pointers
 */

#ifndef LIST
#define LIST

#include <string>
#include <cstring>
#include "gateInclude.h"

class List
{
protected:
    size_t n = 0;
    gate **data = nullptr;
    
public:

    List(){}

    List(gate *in);

    /**
    * @brief returns the current number of gates in the list
    * 
    * @return size_t
    */
    size_t count() const;

    /**
    * @brief adds a gate to the end ofthe list like push_back
    * 
    * @param in 
    */
    void add(gate *in);

    /**
    * @brief removes the element at the given index
    * 
    * @param t 
    */
    void remove(size_t t);

    /**
     * @brief index operator, returns data-s element at the given index
     * 
     * @param i 
     * @return gate* 
     */
    gate* operator[](size_t i) const;
    
    /**
     * @brief get the type of gate that is stored in the list \n 
     *        can decide if the stored gates are heterogenic or homogenic
     * 
     * @return string 
     */
    string getType() const;
    virtual ~List();
};

#endif