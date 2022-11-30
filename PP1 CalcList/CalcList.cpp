//Daniela Mordas & Gopal Krishna Shukla
//Pair Project 

//include the .hpp file
#include "CalcList.hpp"

//define the CalcList Constructor 
CalcList:: CalcList ()
{
    //create a dnode to hold the inital 0 that is to be held in the calculator
    dnode* hold = new dnode;

    //create the head and tail nodes
    head = new dnode;
    tail = new dnode;

    //set all default values to 0
    //set default operation to addition
    hold -> firstValue = 0;
    hold -> secondValue = 0;
    hold -> oppUsed = 0;
    hold -> opp = ADDITION;

    //connect the hold node to the head and tail nodes
    //ensure that hold is inbetween the head and tail values
    hold -> prev = head;
    hold -> next = tail;
    head -> next = hold;
    tail -> prev =hold;

    //initalize the calcTotal defined in the .hpp file to 0
    calcTotal = 0;
}

//define the CalcList Destructor 
CalcList:: ~CalcList()
{
    //remove all but the head and tail node
    while (!empty()) remove(head -> next);

    //remove the head and tail nodes
    delete head; 
    delete tail;
}

//function to check if linkedlist is empty
bool CalcList:: empty() const{
    return (head->next->next == tail);
}

//function to remove a node from the linkedlist
void CalcList::remove(dnode* x)
{
    //initalize pointer variables
    dnode* u = x->prev; //predecessor
    dnode* w = x->next; //successor

    //unlink and then delete x from list
    u ->next = w; 
    w ->prev = u;

    delete x;
}

//return the current total of the calculation
double CalcList::total() const
{
    return calcTotal;
}

//adds opperation to the CalcList & updates the total value
void CalcList::newOperation(const FUNCTIONS func, const double operand)
{
    dnode* hold = new dnode; 
    dnode* endNode = nullptr; //the last node before the tail

    //stores value before preforming next opperation
    hold -> firstValue = calcTotal; 
    hold -> oppUsed = operand;

    //identify the opperation that is to be used, using an if else if statement
    if (func == ADDITION)
    {
        //incrementing using addition & then store the value in hold->opp
        calcTotal += operand;
        hold -> opp = ADDITION;
    }
    else if (func == SUBTRACTION)
    {
        //decrementing using subtraction & then store the value in hold->opp
        calcTotal -= operand;
        hold -> opp = SUBTRACTION;
    }
    else if (func == MULTIPLICATION)
    {
        //multiplying using multiplication & then store the value in hold->opp
        calcTotal *= operand;
        hold -> opp = MULTIPLICATION;
    }
    else if (func == DIVISION)
    {
        //creat a nested if statement because you can't divide by 0
        if(operand == 0)
        {
            delete (hold);
            throw std:: invalid_argument("Divide by zero error.");
            return;
        }
        else
        {
            //dividing using division & then store value in hold->opp
            calcTotal /= operand;
            hold -> opp = DIVISION;
        }
    }

    //use that value and store it in a new node after operation 
    hold -> secondValue = calcTotal;

    //find the previous node after the 1st opperation
    endNode = tail->prev;

    //placing hold inbetween the end node and the tail node
    endNode -> next = hold;
    hold -> prev = endNode;
    hold -> next = tail; 
    tail -> prev = hold;
}

//add the remove last opperation 
void CalcList:: removeLastOperation()
{
    dnode* previous = tail->prev->prev;
    dnode* current = previous->next;

    //no operations to remove if linkedlist only has the hold node
    if (head->next->next == tail)
    {
        throw std::invalid_argument("No operations to remove.");
        return;
    }
    //remove operation and delete the node
    else 
    {
        calcTotal = previous->secondValue;
        previous->next = tail;
        tail->prev = previous;
        delete current;
    }
}

std::string CalcList:: toString(unsigned short precision) const
{
    //initalize the number of nodes to 0
    int n = 0;

    //create a node to store the value of the node on which the last operation was performed
    dnode* last = tail->prev;
    
    //initalize node to traverse through the linked list
    dnode* nNode = head -> next;

    //create a while loop that will count the number of nodes
    while(nNode -> next != tail)
    {
        nNode = nNode -> next;
        n++;
    }
    std::stringstream str; //stringstream to display the output
    str.precision(precision); //use precision to set the number of decimal points

    //loop to store the output in string str
    while(last->prev != head)
    {
        if (last->opp == ADDITION)
        {
            str << n << ": " << std::fixed << last->firstValue << "+" << last->oppUsed << "=" << last->secondValue << std::endl;
        }
        else if (last->opp == SUBTRACTION)
        {
            str << n << ": " << std::fixed << last->firstValue << "-" << last->oppUsed << "=" << last->secondValue << std::endl;
        }
        else if (last->opp == MULTIPLICATION)
        {
            str << n << ": " << std::fixed << last->firstValue << "*" << last->oppUsed << "=" << last->secondValue << std::endl;
        }
        else if (last->opp == DIVISION)
        {
            str << n << ": " << std::fixed << last->firstValue << "/" << last->oppUsed << "=" << last->secondValue << std::endl;
        }
        n--;
        last = last->prev;
    }

    //return str to display the output
    return str.str();
}