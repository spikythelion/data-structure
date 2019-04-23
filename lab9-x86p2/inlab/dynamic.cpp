#include <iostream>

using namespace std;

class Animal{
public:
  virtual void jump(){
  }
};
  
class Dog: public Animal{
public:
  virtual void jump(){
  }
};

int main(){
  int i;
  cin >> i;
  Animal *a;
  if (i < 0)
    a= new Animal();
  if (i >= 0)
    a= new Dog();
  a->jump();
  return 0;
}
    
	

	
    
