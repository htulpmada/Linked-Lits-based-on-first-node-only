//LinkedList.cpp : main project file.
//written by Nathan Brinda, CWID:11552778
//and
//Adam Pluth, CWID: 
//#include "stdafx.h"      //REMOVE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "LinkedList.h"
	
LinkedList::LinkedList(){
	data=0;
	next=NULL;
}

LinkedList::~LinkedList(){
   if (next)
      delete next;
}

char LinkedList::removeFront(){
      char tempc;
      LinkedList* templ = next->next;
      tempc = next->data;
      next = templ;
      return tempc;
}

void LinkedList::insertFront(char c){

   LinkedList* templ;
   templ = new LinkedList;
   templ->data = c;
   templ->next = next;
   next = templ;
}

char LinkedList::front()const {
	return this->next->data;
}

int LinkedList::count()const{
   LinkedList *temp = next;
   int counter = 0;
   while (temp)
   {
      temp = temp->next;
      counter++;
   }
   return counter;

	}
   
std::string LinkedList::toString()
{
   LinkedList *temp = next;
   std::string str;
   while (temp)
   {
      str += temp->data;
      temp = temp->next;
   }
   return str;
}
