///Daniela Mordas and Gopal Krishna Shukla 
//Pair Programming Project 4
#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.hpp"
#include "Vertex.hpp"
#include <vector>
#include <utility>
#include <map>

class Graph
{
    public:
        void addVertex(std::string label);
        void removeVertex(std::string label);
        void addEdge(std::string label1, std::string label2, unsigned long weight);
        void removeEdge(std::string label1, std::string label2);
        unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);
        bool checkVertex(std::string);
        void makeList();
        void removeVertices();
        void createPath(std::string startLabel, std::map<std::string, std::string> m, std::vector<std::string> &path, std::string current);
    
    private:
        std::vector<Vertex*> vertices;
        std::vector<Edge*> edges;
        std::map<std::string, std::vector<std::pair<unsigned long, std::string> > >adjacent;


};


#endif