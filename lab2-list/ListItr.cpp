/**
Name: Tho Nguyen
Email ID: tnn7yc
File name:ListItr.cpp
Date:9/13/18
*/


#include "ListItr.h"
#include "ListNode.h"

using namespace std;

//Constructor
ListItr::ListItr(){
  current= new ListNode();
  //  cout<<"Constructor"<<endl;
}

//One parameter constructor
ListItr::ListItr(ListNode* theNode){
  current= theNode;
  // cout<<"One par constructor"<<endl;
}

//Returns true if pas end position in list, else false
bool ListItr::isPastEnd() const{
  if(current->next==NULL)
    return true;
  return false;
}

//Returns true if past first position  in list, else false
bool ListItr::isPastBeginning() const{
  if (current->previous==NULL)
    return true;
  return false;

}

//Adnvaces current to next position in list (unless already past end of list)
void ListItr::moveForward(){
  if(this->isPastEnd())
    cout<<"Already past end of list"<<endl;
  else{
    current= current->next;
  }
}

//Moves current back to previous position in list
//(unless already past beginning of list)
void ListItr::moveBackward(){
  if(this->isPastBeginning())
    cout<<"Already past beginning of list"<<endl;
  else{
    current= current->previous;
  }
}

//Returns item in current position
int ListItr::retrieve() const{
  if (current==NULL)
    return 0;
  return current->value;
}

//print a list either forward when forward is true or back ward
void printList(List& theList, bool forward){
  ListItr* temp= new ListItr();
   if (forward){
     *temp= (theList.first());//first returns a ListItr
     while(!(temp->isPastEnd())){
       cout<<temp->retrieve()<< ",  ";
       temp->moveForward();
     }
   }

   if (!forward){
     *temp= (theList.last());//last returns a ListItr
     while(!(temp->isPastBeginning())){
       cout<<temp->retrieve()<< ",  ";
       temp->moveBackward();
     }
   }
 }

