#include "String.h"
#include <iostream>
using namespace std;

int main() {
    String a("Hello, my String!");
    String b = a;
    String c(a);
    
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    
    return 0;
}