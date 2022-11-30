///Daniela Mordas and Gopal Krishna Shukla 
//Pair Programming Project 4

#include "Vertex.hpp"
#include <utility>

Vertex::Vertex()
{
    //Initalize the lable to nothing 
    label = "";
}

void Vertex::initalizeLabel(std::string s)
{
    label = s;
}
       
std::string Vertex::obtainLabel()
{
    //get the label 
    return label;
}

unsigned long Vertex::obtainWeight(std::string)
{
    for(auto i: adjacent){
        if(i.second == label)
        {
            return i.first;
        }
    }
    return 0;
}