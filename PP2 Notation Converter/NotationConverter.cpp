//Daniela Mordas & Gopal Krishna Shukla
//Pair Project Code file
#include "NotationConverter.hpp"
#include <iostream>

NotationConverter::NotationConverter() : convert(), ch() {}

//check if an element is an Alphabet or not
bool NotationConverter::isOperand(char x) {
   return (x >= 'a' && x <= 'z') ||
          (x >= 'A' && x <= 'Z');
} 

//check if an element is an Operator or not
bool NotationConverter::isOperator(char x) {
   return (x == '+'|| x == '-'|| x == '*'|| x == '/');
} 

//function to convert from postfix to infix
std::string NotationConverter::postfixToInfix(std::string inStr) {
	int i;
	std::string ans; //store the converted infix expression
	std:: string str; //store each characted of the input string (postfix expression)
	for (i = 0; i < inStr.length(); i++) {
		str="";
		if(isOperand(inStr[i])) {
			str.push_back(inStr[i]);
			convert.insertBack(str);

		}
		else if(inStr[i]==' ') {
			continue;
		}
		else if (isOperator(inStr[i])) {
			std::string s1=convert.back();
			convert.removeBack();
			std::string s2=convert.back();
			convert.removeBack();
			ans="(" + s2 + " " + inStr[i] + " " + s1 + ")";
			convert.insertBack(ans);
		}
		else {
            throw std::invalid_argument("Input is Invalid");
        }
	}
	ans=convert.back();
	convert.removeBack();
	return ans;
}

//function to convert from postfix to prefix
std::string NotationConverter::postfixToPrefix(std::string inStr) {
	std::string str;
    std::string ans;

    str = postfixToInfix(inStr);

    ans = infixToPrefix(str);

    return ans;
}

//function to convert from infix to postfix
std::string NotationConverter::infixToPostfix(std::string inStr) {
	std::string str;
	std::string str1;
	std::string ans;
	int i;
	for (i=0; i<inStr.length(); i++){
		str="";
		str1="";
		if (inStr[i] == ' ') {
            continue;
        }

		if(inStr[i]=='(') {
			str1.push_back('(');
			ch.insertBack(str1);
		}
		else if(inStr[i]==')') {
			while(ch.back()[0]!='(') {
				str.push_back(ch.back()[0]);
				convert.insertBack(str);
				ch.removeBack();
			}
			ch.removeBack();
		}
		else if(isOperand(inStr[i])) {
			str.push_back(inStr[i]);
			convert.insertBack(str);
		}
		else if (isOperator(inStr[i])){
			str1.push_back(inStr[i]);
            ch.insertBack(str1);  
        }
        else {
            throw std::invalid_argument("Input is Invalid");
        }
    }
    while (convert.size() > 0) {
        ans = convert.back() + " " + ans;
        convert.removeBack();
    }
    return ans;
}

//function to convert from infix to prefix
std::string NotationConverter::infixToPrefix(std::string inStr) {
	std::string str;
	std::string ans;
	std::string ans2;
	int i;
	for (i=0; i<inStr.length(); i++) {
		if (inStr[i] == ' ') {
			continue;
		}
		else if (inStr[i] == '(') {
			inStr[i]=')';
		}
		else if(inStr[i] == ')') {
			inStr[i]='(';
		}
		str= inStr[i] + str;
	}
	ans=infixToPostfix(str);
	for (int i=0; i< ans.length(); i++) {
		ans2= ans[i] + ans2;
	}
	return ans2;
}

//function to convert from prefix to infix
std::string NotationConverter::prefixToInfix(std::string inStr) {
	std::string str;
	std::string ans;
	int i;
	for(i=(inStr.length()-1); i>=0; i--) {
		str = "";

		if(isOperand(inStr[i])) {
			str.push_back(inStr[i]);
			convert.insertBack(str);

		}
		else if(inStr[i]==' ') {
			continue;
		}
		else if (isOperator(inStr[i])){
			std::string s1=convert.back();
			convert.removeBack();
			std::string s2=convert.back();
			convert.removeBack();
			ans="(" + s1 + " " + inStr[i] + " " + s2 + ")";
			convert.insertBack(ans);
		}
		else {
            throw std::invalid_argument("Input is not valid");
        }
	}
	ans=convert.back();
	convert.removeBack();
	return ans;
}

//function to convert from prefix to postfix
std::string NotationConverter::prefixToPostfix(std::string inStr) {
	std::string str;
	std::string ans;
	str=prefixToInfix(inStr);
	ans=infixToPostfix(str);
	return ans;
}







