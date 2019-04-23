#include <iostream>

using namespace std; 

class Dog{
    public:
    string breed = "";
    void setAge(Dog d);
    int age = 0;
};

void Dog::setAge(Dog d){
    d.age = 2;
}

int main(){
    Dog d;
    d.setAge(d);
    cout << d.age;
    return 0;
}
