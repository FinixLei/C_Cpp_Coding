#include <iostream>
#include "MyString.hpp"
using namespace std;


int main()
{
    MyString a("a ");
    cout << "a = " << a << endl << endl;
    
    MyString b = std::move(a); 
    cout << "b = std::move(a); so, b = " << b << endl;
    cout << "a = " << a << endl << endl;
    
    MyString c = b;
    cout << "c = b; so, c = " << c << endl << endl;
    
    MyString d = std::move(b + c);
    cout << "d = std::move(b + c); so, d = " << d << endl << endl;
    
    MyString e = b + c;
    cout << "e = b + c; so, e = " << e << endl << endl;
    
    a = std::move(e);
    cout << "a = std::move(e), so, a = " << a << endl;
    cout << "Now e = " << e << endl << endl; 
    
    MyString f;
    f = a;
    cout << "f = a, so f = " << f << endl;
    
    return 0;
}
