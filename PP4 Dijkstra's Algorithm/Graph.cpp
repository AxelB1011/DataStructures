///Daniela Mordas and Gopal Krishna Shukla 
//Pair Programming Project 4

#include "Graph.hpp"
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

struct EdgeStruct { std::string a; std::string b; unsigned long w; };

//set the addVertex function
void Graph::addVertex(std::string label)
{
    //create a and use the private vertex pointer to add a new vertex to the graph 
    Vertex* vert = new Vertex();
    //set the new vert to the initalizeLabel
    vert ->initalizeLabel(label);
    //then add it to the list
    vertices.push_back(vert);

}
//set the removeVertex function
void Graph::removeVertex(std::string label)
{
    //start it by using a for loop to check if the vertecies is in the list
     for(auto vert:vertices) 
    {
        //make an if statement to check if the vertex is found
        if(vert -> obtainLabel() == label) 
        {
            //if so then have it deleted
            vertices.erase(std::remove(vertices.begin(), vertices.end(), vert), vertices.end());
        }
    }

    //then have another for loop search the edges
    for(auto edg : edges) 
    {
        //make if statement to check to see if the edge contains a vertex
        if(edg -> initalizeStart() == label || edg -> initalizeFinish() == label) 
        {
            //if so then the edge is tp be removed
            edges.erase(std::remove(edges.begin(), edges.end(), edg), edges.end()); 
        }
    }
    
}
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight)
{
    //check if vertex 1 exists
    if(!checkVertex(label1))
    {
        std::cout << "Vertex 1 does not exist.\n";
        return;
    }
    
    //check if vertex 2 exists
    if(!checkVertex(label2))
    {
        std::cout << "Vertex 2 does not exist.\n";
        return;
    }

    //check if it an edge to itsself
    if(label1 == label2)
    {
        std::cout << "Vertices cannot have an edge to themselves.\n";
        return;
    }

    //check if the edge already exists
    for(auto edg : edges)
    {
        //make if statement to see if the edge already exists
        if(edg -> initalizeStart() == label1 && edg -> initalizeFinish() == label2)
        {
            std::cout << "This edge already exists.\n";
            return;
        }
    }

    //create a new edge
    Edge* edg = new Edge(label1, label2, weight); 
    //then have the edge added to the new edge list
    edges.push_back(edg); 

}
void Graph::removeEdge(std::string label1, std::string label2)
{
     //use for loop to search to see if the edge is in the list
     for(auto edg : edges)
    {
        //use if statement to check 
        if(edg -> initalizeStart() == label1 && edg -> initalizeFinish() ==label2) 
        {
            //if it is found then it shoul be deleted
            delete edg; 
        }
    }
}

void Graph::makeList()
{

    for(auto v : vertices) 
    {
        for(auto e : edges) 
        {
            if(e ->initalizeStart() == v -> obtainLabel())
            {
                //add adjacent vertices to list
                adjacent[v ->obtainLabel()].push_back((std::make_pair(e ->initalizeWeight(), e -> initalizeFinish())));
                adjacent[e -> initalizeFinish()].push_back(std::make_pair(e ->initalizeWeight(), v -> obtainLabel()));

            }
        }
    }
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path)
{
    //initalize the adjacency list
    makeList(); 

    std::map<std::string, unsigned long> distance;
    std::priority_queue<std::pair<unsigned long, std::string>, std::vector<std::pair<unsigned long, std::string> >, std::greater<std::pair<unsigned long, std::string> > >pq;
    std::map<std::string, std::string> m;
    
    //use for loop to see if all of the verticies are in the vertex list
    for(auto vert : vertices) 
    {
        //use if statement to check for current vertex
        if(vert -> obtainLabel() == startLabel) 
        {
            //if it starts then skip
            continue; 
        }

        //then set all other values to infinite
        distance[vert -> obtainLabel()] = 9999999;
    }
    
    //set the distance of the starting vertex to 0 then have it added to the queue
    pq.push(std::make_pair(0, startLabel)); 
    

    //create a while loop to make sure the queue is not empty
    while(!pq.empty()) 
    {
    
        //use to save the vertex label 
        std::string s = pq.top().second; 
        //then pop it to remore it form the queue
        pq.pop();

        std::vector<std::pair<unsigned long, std::string>>::iterator i;
        //use a for loop to iterate through each element in the adjacency list
        for(i = adjacent[s].begin(); i != adjacent[s].end(); i++)
        {
            //assign and save the weight to its edge
            unsigned long weight = i -> first; 
            //save the vertex lable of i to the label
            std::string label = i -> second; 

            //make if statement to see if the endLable is shorter than its path through s
            if(distance[label] > distance[s] + weight)
            {
                //if it is then it will update the distance
                distance[label] = distance[s] + weight; 
                //then it will add the distance and vertex to the queue
                pq.push(std::make_pair(distance[label], label)); 
                m[label] = s;
            }
        }
        
    }
    createPath(startLabel, m, path, endLabel);

    path.push_back(startLabel);

    std::reverse(path.begin(), path.end());
    //then have it return the shortest distance
    return distance[endLabel]; 


}


void Graph::createPath(std::string startLabel, std::map<std::string, std::string> m, std::vector<std::string> &path, std::string current) {

  if (current == startLabel) {
    return;
  }

  path.push_back(current);

  createPath(startLabel, m, path, m[current]);
}

bool Graph::checkVertex(std::string label)
{
     //create for loop that will go through all the verticies in the vertex list
     for(auto v : vertices) //for all vertices in vertex list
    {
        //then use an if statement ro see if it is found
        if(v -> obtainLabel() == label) 
        {
            //if it is then it is to return true
            return true; 
        }
    }

    //if it is not in the list then it returns false
    return false;
}