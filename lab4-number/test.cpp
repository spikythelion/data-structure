#include <iostream>
#include <cfloat>
using namespace std;

union foo {
    float f;
    int *x;
} bar;

int main() {
    bar.f = 0;
    cout << bar.x << endl; // prints in big-endian
    return 0;
}
