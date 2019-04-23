#include "ListItr.h"
#include "ListNode.h"

using namespace std;

int main(){

  ListItr* li1= new ListItr();//constructor
  ListNode* ln1= new ListNode();
  ListItr* li2= new ListItr(ln1);
  cout<<"li2 value is  "<<li2->retrieve()<<endl;
  
  return 0;
}
  
