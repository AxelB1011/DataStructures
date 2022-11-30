///Daniela Mordas and Gopal Krishna Shukla 
//Pair Programming Project 4
//reccomended to create own separate class
#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <utility>
#include <vector>

class Vertex
{
    public:
        //set and initalize the public variables 
        Vertex(); 
        void initalizeLabel(std::string);
        std::string obtainLabel();
        void addAdjacent(std::string, unsigned long);
        unsigned long obtainWeight(std::string);

    private:
        std::string label;
        std::vector<std::pair<unsigned long, std::string> >adjacent;
        unsigned long distance;

    friend class Edge;
};


#endif