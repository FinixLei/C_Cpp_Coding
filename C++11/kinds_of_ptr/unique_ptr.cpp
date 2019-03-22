#include <memory>
#include <iostream>
using namespace std;


int main()
{
    unique_ptr<int> a(new int(10));
    cout << "a = " << *a << endl;
    
    // copy constructor is deleted 
    // unique_ptr<int> b(a);
    // unique_ptr<int> c = b; 
    // operator= is also deleted 
    // unique_ptr<int> b;
    // b = a;
    
    unique_ptr<int> b;
    b = std::move(a);
    cout << "b = " << *b << endl;
    
    unique_ptr<int> c = std::move(b);
    cout << "c = " << *c << endl;
    
    c.release();
    int * pc = c.get();
    if (pc == NULL) {
        cout << "pointer of c is NULL\n";  // print this 
    }
    else {
        cout << "ponter of c is not NULL\n";
    }
    if(!a) { // operator bool 
        cout << "pointer of a is NULL \n";  // print this 
    }
    
    unique_ptr<int []> foo(new int [3]);  
    for (int i=0; i<3; i++) foo[i]=i;  // operator []
    for (int i=0; i<3; i++) cout << foo[i] << " ";
    cout << endl;
    
    return 0;
}