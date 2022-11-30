//Daniela Mordas and Gopal Krishna Shukla 
//Pair Programming Project 3

#include "HuffmanTree.hpp"
#include "HuffmanBase.hpp"
#include "HeapQueue.hpp"
#include "TestStrings.hpp"
#include <string>
#include <map>
#include <iostream>
#include <vector>

//function to compress the string
std::string HuffmanTree::compress(std::string inputStr)
{  
    
    HuffmanNode *last = new HuffmanNode('\0', 0, nullptr, nullptr, nullptr);
    HeapQueue<HuffmanNode* , HuffmanNode::Compare> heap;
    std::map<char, std::string> m; //map that will return compressed string
    std::map<char, int> frequency;
    std::string s="";
    //generate a list of the frequency in which characters appear in the string using a map
    for (std::string::iterator i= inputStr.begin(); i!=inputStr.end(); i++){
        frequency[*i]++;
    }
    //iterate through the map to insert the characters and their frequencies in our priority queue
    std::map<char, int>::iterator it = frequency.begin();
    while (it!=frequency.end()){
        HuffmanNode *n= new HuffmanNode(it->first, it->second);
        heap.insert(n);
        it++;
    }
    //insert intermediate nodes(parent nodes) in our priority
    while(heap.size() != 1){
        //create two nodes to store the value of children nodes and remove children nodes from our priority queue
        HuffmanNode *val1= heap.min();
        heap.removeMin(); 
        HuffmanNode *val2= heap.min();
        heap.removeMin();
        //create and insert new parent in our prioirty queue node using the sum of frequencies of child nodes
        HuffmanNode *parTree = new HuffmanNode('\0', (val1->getFrequency() + val2->getFrequency()), nullptr, val1, val2);
        heap.insert(parTree);
    }

    last = heap.min(); //get the last pair of the priority queue (root node)
    tree = last; //put it equal to our private member tree
    heap.removeMin(); //remove last pair from the priority queue
    prefixCode(last, s, m); //encode characters in the string with their prefix codes

    std::string result=""; //variable to store and return the compressed string
    std::string::iterator itr = inputStr.begin();
    
    //replace the characters in the string with their new variable-length prefix codes and return the compressed string
    while (itr!=inputStr.end()){
        result += m[*itr];
        itr++;
    }
    return result;
}

//function to serialize the tree
std::string HuffmanTree::serializeTree() const {
    std::string str= "";
    serializeString(tree, str); //call serializeString for postorder traversal and serialization
    deleteNode(tree); //remove nodes
    return str; //return serialized string
}

//function to decompress the string
std::string HuffmanTree::decompress(const std::string inputCode, const std::string serializedTree)
{
    std::vector<HuffmanNode*> v;
    std::string str="";

    //deserialize the tree string using leaf and branch indicators
    for (unsigned int i=0; i<serializedTree.length(); i++) {
        //if leaf indicator, go to the next character and push it to our vector
        if(serializedTree[i] == 'L') { 
            i++;
            HuffmanNode *node = new HuffmanNode(serializedTree[i], 0);
            v.push_back(node);
        }
        //if branch indicator, create a parent node and push it to our vector
        else if(serializedTree[i] == 'B'){
            HuffmanNode *right = v.back(); //get left child from the last element of vector and delete it from vector
            v.pop_back();

            HuffmanNode *left = v.back(); //get right child from last element of vector and delete it from vector
            v.pop_back();
            //create parent node using left and right child
            HuffmanNode *par = new HuffmanNode('\0', 0, nullptr, left, right); 
            v.push_back(par); //add parent node to vector
        }
    }
    //get the last element of our vector and assign it to our private member tree
    HuffmanNode *n1 = v.back();
    tree = n1;

    //decompress the Huffman Code by tracing the tree
    for (unsigned int i=0; i<inputCode.size(); i++){
        if(inputCode[i] == '0') {
            n1 = n1 -> left; 
        }
        if(inputCode[i] == '1') {
            n1 = n1 -> right;
        }
        //add the character to our decompressed string if it is present at a leaf node
        if(n1->isLeaf()) {
            str += n1 ->getCharacter(); 
            n1 = tree; 
        }
    }
    deleteNode(tree); //remove nodes
    return str; 
}

//function to traverse the tree in preorder and encode prefix codes to the string
void HuffmanTree::prefixCode(HuffmanNode* root, std::string str, std::map<char, std::string> &m1)
{
    if (root == nullptr) {
        return;
    }
    //encode characters in string str using map with the prefix codes
    if(root->isLeaf()){
        m1[root->getCharacter()] = str;
    }
    prefixCode(root -> left, str + "0", m1); //add 0 when traversal goes left
    prefixCode(root -> right, str + "1", m1); //add 1 when traversal goes right
}

//recursive function for post order traversal and seriliazation
void HuffmanTree::serializeString(HuffmanNode* traverse, std::string &str) const
{
    if (traverse == nullptr) { return;}
    serializeString(traverse->left, str);
    serializeString(traverse->right, str);
    //add L plus the character to the serialize tree string if leaf node
    if (traverse->isLeaf()) {
        str += "L";
        str += traverse->getCharacter();
    }
    //add B to the serialize tree string if branch node
    if (traverse->isBranch()) {
        str +="B";
    }
}

//function to delete nodes
void HuffmanTree::deleteNode(HuffmanNode* node) const
{
    if(node == nullptr) {return;}
    deleteNode(node -> left); 
    deleteNode(node -> right);
    delete node;
}