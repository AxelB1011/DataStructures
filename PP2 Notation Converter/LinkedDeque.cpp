//Daniela Mordas & Gopal Krishna Shukla
//Pair Project Code file
#include "LinkedDeque.hpp"

LinkedDeque::LinkedDeque()  : D(), n(0) {}

// function to return size of deque
int LinkedDeque::size() const {
    return n;
}

//function to check if deque is empty
bool LinkedDeque::empty() const {
    return n == 0;
}

//function that will return the front element
const Elem& LinkedDeque::front() const {
    if(empty()) {
        throw std::invalid_argument("No front value, Deque is empty");
    }
    return D.front();
}

//function that will return the last element
const Elem& LinkedDeque::back() const {
    if(empty()) {
        throw std::invalid_argument("No back value, Deque is empty");
    }
    return D.back();
}

//function that will insert new first element
void LinkedDeque::insertFront(const Elem& e) {
 D.addFront(e); n++;
}

// function that will insert new last element
void LinkedDeque::insertBack(const Elem& e) {
 D.addBack(e); n++;
}

//function that will remove first element
void LinkedDeque::removeFront() {
 if (empty()) { throw std::invalid_argument("empty deque"); }
 D.removeFront(); n--;
}

//function that will remove last element
void LinkedDeque::removeBack() {
 if (empty()) { throw std::invalid_argument("empty deque"); }
 D.removeBack(); n--;
}