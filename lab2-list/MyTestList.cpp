#include <iostream>
#include <string>

#include "List.h"

using namespace std;

int main(){
  List* l1= new List(); //Constructor
  /*
  cout<<"l1 isEmpty: "<< l1->isEmpty() <<endl;//isEmpty
  l1->makeEmpty();//makeEmpty

  cout<<"first is "<< l1->first().retrieve() <<endl;//first()
  
  l1->insertAfter(3,l1->first());//insertAfter
  l1->insertBefore(7, l1->last());//insertBefore

  cout<<"l1 isEmpty() after insert "<< l1->isEmpty() <<endl;//isEmpty
  
  l1->makeEmpty();//makeEmpty
 
  cout<<"l1 isEmpty() after makeEmpty  "<< l1->isEmpty()<<endl;
  */
  l1->insertAtTail(7);
  l1->insertAfter(3,l1->first());//insertAfter
  l1->insertAfter(7,l1->first());
  l1->remove(7);
  
  return 0;
}
