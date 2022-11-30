//Daniela Mordas & Gopal Krishna Shukla
//Pair Project 

//include the header guards to prevent multiple declarations
#ifndef CALCLIST_H
#define CALCLIST_H

//add the include functions
#include <iostream>
#include <sstream>
#include <iomanip>
#include "CalcListInterface.hpp"

class dnode 
{
public:
    //define the variables in the dnode 
    double firstValue; //value holder prior to operation
    double secondValue; //value holder after operation
    double oppUsed; //the value that was used in the operation
    //use the FUNCTION initalized in the enum in the CalcListInterface 
    FUNCTIONS opp; //operation used
    //initalize two pointers for storing the previous & next addresses
    dnode* prev = nullptr;
    dnode* next = nullptr;
    //Allow CalcList access
    friend class CalcList;
};

//added form CalcListInterface 
// Abstract class for inheritance
class CalcList: public CalcListInterface 
{
public:
    //Create a constructor and deconstructoer
    CalcList();
    ~CalcList();

    //define the abstract class & files 
    virtual double total() const;
    virtual void newOperation(const FUNCTIONS func, const double operand);
    virtual void removeLastOperation();
    virtual std::string toString(unsigned short precision) const;

    //empty function to check if the linkeslist is empty
    bool empty() const;
     
    //define the calc total 
    double calcTotal;

    //define the head and tail dnode pointers
    dnode* head;
    dnode* tail;

    //function to remove a node from the linkedlist
    void remove(dnode* x); 
};

#endif 