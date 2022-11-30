//Daniela Mordas & Gopal Krishna Shukla
//Pair Project Code file
#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H

#include <string>
#include <iostream>
#include <stdexcept>
#include "NotationConverterInterface.hpp"
#include "LinkedDeque.hpp"

class NotationConverter: public NotationConverterInterface
{
public:

  NotationConverter(); //constructor

  //functions to perform all the given conversions
  virtual std::string postfixToInfix(std::string inStr);
  virtual std::string postfixToPrefix(std::string inStr);

  virtual std::string infixToPostfix(std::string inStr);
  virtual std::string infixToPrefix(std::string inStr);

  virtual std::string prefixToInfix(std::string inStr);
  virtual std::string prefixToPostfix(std::string inStr);

  //helper functions to check if a given element is Operand or Operator
  bool isOperand(char x);
  bool isOperator(char x);

private:
  LinkedDeque convert;
  LinkedDeque ch;


};



#endif /* NOTATIONCONVERTERINTERFACE_H */