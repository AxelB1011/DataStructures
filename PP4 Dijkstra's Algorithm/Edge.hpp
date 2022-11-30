///Daniela Mordas and Gopal Krishna Shukla 
//Pair Programming Project 4
//reccomended to create own separate class
#ifndef EDGE_H
#define EDGE_H

#include <string>
//include the vector header to be referenced 
#include "Vertex.hpp"

class Edge
{
    public:
        //initalize edge to consist of 2 strings start and finish and unsigned long for weight
        Edge(std::string, std::string, unsigned long);
        std::string initalizeStart();
        std::string initalizeFinish();
        unsigned long initalizeWeight();

    private:
        //initalize strings and the unsigned long so it's private 
        std::string start;
        std::string finish;
        unsigned long weight;

};


#endif