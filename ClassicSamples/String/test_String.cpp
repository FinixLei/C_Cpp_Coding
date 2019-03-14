#include <iostream>
#include "String.hpp"
using namespace std;


int main()
{
    String a("hello, world!");
    cout << a << endl; 
    
    String b = a; 
    cout << b << endl; 
    
    String c = "Boys and Girls";
    String d = a + b + c;
    cout << d << endl; 
    
    String e = std::move(d);
    cout << "e: " << e << endl;
    cout << "d: " << d;
    
    return 0;
}