///Daniela Mordas and Gopal Krishna Shukla 
//Pair Programming Project 4

#include "Edge.hpp"

//initalize edge to consist of 2 strings start and finish and unsigned long for weight
Edge::Edge(std::string firstLable, std::string secondLable, unsigned long wei)
{
    //set the private strings to point to the std strings
    start = firstLable;
    finish = secondLable;
    weight = wei;
}

//set the initalizeStart string and have it return start
std::string Edge::initalizeStart()
{
    return start;
}

//set the initalizeFinish string and have it return finish
std::string Edge::initalizeFinish()
{
    return finish;
}

//set the unsigned long initalizeWeight and return weight
unsigned long Edge::initalizeWeight()
{
    return weight;
}