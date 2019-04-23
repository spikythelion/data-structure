/**
Name: Tho Nguyen
Email ID: tnn7yc
File name:List.cpp
Date:9/13/18
*/


#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

using namespace std;

//Constructor
List:: List(){
  head= new ListNode();
  tail= new ListNode();
  head->previous= NULL;
  head->next= tail;
  tail->previous= head;
  tail->next= NULL;
  count= 0;
}

//Copy Constructor
List::List(const List& source){
    head= new ListNode;
    tail= new ListNode;
    head->next= tail;
    tail->previous= head;
    count= 0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()){
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }

  //Destructor
  List:: ~List(){
    this->makeEmpty();
    delete head;
    delete tail;
  }

  //Equals operator
  List& List::operator=(const List& source){
    if (this==&source)
      return *this;
    else{
      makeEmpty();
      ListItr iter(source.head->next);
      while (!iter.isPastEnd()){
	insertAtTail(iter.retrieve());
	iter.moveForward();
      }
    }
    return *this;
  }

  // Retun true if empty, else false
bool List::isEmpty() const{
  if(count==0){
      return true;
  }
    return false;
}

  //removes all item except balnk head and tail
void List::makeEmpty(){
  ListItr* li= new ListItr(head->next);
  if(this->isEmpty())
     cout<<"This list is already empty"<<endl;
  else{
    while(!li->isPastEnd()){
      ListNode* del= NULL;
      del= li->current;
      li->moveForward();
      delete del;
      --count;
     }
    head->next= tail;
    tail->previous= head;
  }
}

  //Returns an iterator that points to the ListNode in the first position
ListItr List::first(){
  return *(new ListItr(head->next));
}

  //Returns an iterator that points to the ListNode in the last position
ListItr  List::last(){
  return *(new ListItr(tail->previous));
  }

  //Inserts x after current iterator position p
 void List::insertAfter(int x, ListItr position){
    ListNode* ln= new ListNode();
    ln->value= x;
    ln->next= position.current->next;
    position.current->next->previous= ln;
    position.current->next= ln;
    ln->previous= position.current;
    ++count;
  }

 //Inserts x before current iterator position p
  void List::insertBefore(int x, ListItr position){
    ListNode* ln= new ListNode();
    ln->value= x;
    ln->previous= position.current->previous;
    position.current->previous->next= ln;
    position.current->previous= ln;
    ln->next= position.current;
    ++count;
  }
    
						 
//Insert x at tail of list
 void List::insertAtTail(int x){
   ListNode* prev= tail->previous;
   ListNode* ln= new ListNode();
   ln->value= x;
   prev->next= ln;
   tail->previous= ln;
   ln->previous= prev;
   ln->next= tail;
   ++count;
  }

 //Removes the first occurrence of x
 void List::remove(int x){
   ListItr* temp= new ListItr(head->next);
   bool done= false;
   while (!(temp->isPastEnd()) && !done){
      if (temp->current->value==x){
	ListNode* nxt= temp->current->next;
	temp->current->previous->next= nxt;
	nxt->previous= temp->current->previous;
	delete temp->current;
	done= true;
	--count;
      }
      temp->moveForward();
    }
   if (!done)
     cout<<"There is no " <<x<<" in this list"<<endl;
  }
       

   //Returns an iterator that points to the first occurrence of x,
  //else return a iterator to the dummy tail node
 ListItr List::find(int x){
    ListItr* li= new ListItr(head->next);
    while (!(li->isPastEnd())){
      if (li->current->value==x){
	return *li;
      }
      li->moveForward();
    }
    return *(new ListItr(tail));
  }
   //Returns the number of elements in the list
  int List::size() const{
     return count;
   }
    

  

    

