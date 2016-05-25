//#include "stdafx.h"  //REMOVE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//written by Nathan Brinda, CWID:11552778
//and
//Adam Pluth, CWID: 11455946
//cs101 project3
#include <iostream>
#include <fstream>
#include "LinkedList.h"

void Exit(char c, char b, std::string str);
char opposite(char item);

int main(int argc, char* argv[]) {

   if (argc != 2) {
      std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
      return 1;
   }

   std::ifstream input(argv[1]);
   char c;

   /* Put any variables you need here */
   LinkedList closers = LinkedList();
   LinkedList openers = LinkedList();

   /* Implement logic here */
   while (input >> c)
   {
      if (c == '{' || c == '(' || c == '<' || c == '['){
         openers.insertFront(c);
         }
      
      if (c == '}' || c == ')' || c == '>' || c == ']'){
         if (openers.count() <= 0)
         {
            std::cout << "Reached closing brace with no matching open brace: " << c << std::endl;
	 //    std::getchar();
         return 0;
         }
         if (c == opposite(openers.front())){ openers.removeFront(); }
         else{ Exit(c, openers.front(), openers.toString()); }
      }
   }

   if (openers.count() >= 1)
   {
      std::cout << "did not close all braces \nRemaining braces: " << openers.toString() << std::endl;
	  return 0;
   }   
   input.close();
   std::cout << "Valid program" << std::endl;
   //std::getchar();
   return 0;
}

void Exit(char c, char b, std::string str){
   if (!c){ std::cout << "did not close all braces \nRemaining braces to close: " << str << std::endl; }
   else if (!b)std::cout << "Reached closing brace with no matching open brace: " << c << std::endl;
   else { std::cout << "Found '" << c << "' expected closing brace for '" << b << "'\nRemaining braces: " << str << std::endl; }
   //std::getchar();
   exit(0);
}

char opposite(char item)
{
   switch (item)
   {
   case ')':
      return '(';
   case '(':
      return ')';
   case'[':
      return ']';
   case ']':
      return '[';
   case '}':
      return'{';
   case '{':
      return '}';
   case '>':
      return '<';
   case '<':
      return '>';
   default:
      return item;
   }
}

