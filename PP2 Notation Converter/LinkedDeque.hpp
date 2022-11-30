//Daniela Mordas & Gopal Krishna Shukla
//Pair Project Code file
#ifndef LINKEDDEQUE_H
#define LINKEDDEQUE_H

#include <string>
#include <stdio.h>
#include <iostream>
#include "DLinkedList.hpp"

typedef std::string Elem; // deque element type

class LinkedDeque { // deque as doubly linked list

public:
 LinkedDeque(); // constructor
 int size() const; // number of items in the deque
 bool empty() const; // is the deque empty?
 const Elem& front() const; // first element
 const Elem& back() const; // last element

 void insertFront(const Elem& e); // insert new first element
 void insertBack(const Elem& e); // insert new last element
 void removeFront(); // remove first element
 void removeBack(); // remove last element

private:
 DLinkedList D; // doubly linked list of elements
 int n; // number of elements
};

#endif // LINKEDDEQUE_H