#ifndef Huffman_hpp
#define Huffman_hpp

#include "HuffmanBase.hpp"
#include <string>
#include <vector>
#include <map>

class HuffmanTree : public HuffmanTreeBase
{
      public:
        std::string compress(const std::string inputStr);
        std::string serializeTree() const;
        std::string decompress(const std::string inputCode, const std::string serializedTree);
        void prefixCode(HuffmanNode*, std::string, std::map<char, std::string>&);
        void deleteNode(HuffmanNode*) const;
        void serializeString(HuffmanNode*, std::string&) const;

        private:
          HuffmanNode *tree; //private member to access the tree
};

#endif