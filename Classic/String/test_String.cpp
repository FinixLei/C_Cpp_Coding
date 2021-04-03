#include <iostream>
#include "String.hpp"
using namespace std;


int main()
{
    String a("a ");
    cout << "a = " << a << endl << endl;
    
    String b = std::move(a); 
    cout << "b = std::move(a); so, b = " << b << endl;
    cout << "a = " << a << endl << endl;
    
    String c = b;
    cout << "c = b; so, c = " << c << endl << endl;
    
    String d = std::move(b + c);
    cout << "d = std::move(b + c); so, d = " << d << endl << endl;
    
    String e = b + c;
    cout << "e = b + c; so, e = " << e << endl << endl;
    
    a = std::move(e);
    cout << "a = std::move(e), so, a = " << a << endl;
    cout << "Now e = " << e << endl << endl; 
    
    return 0;
}
