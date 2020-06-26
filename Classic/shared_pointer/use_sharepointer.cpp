#include <iostream>
#include "shared_pointer.hpp"

using namespace std; 


class shape 
{
public: 
    virtual ~shape(){}
};

class circle : public shape
{
public: 
    virtual ~circle() { puts("~circle()\n"); }
};

class triangle : public shape 
{
public:
    virtual ~triangle() { cout << "~triangle()" << endl; }
};


int main()
{
    smart_ptr<circle> p1(new circle());
    smart_ptr<shape> p2;
    cout << "p1 count: " << p1.use_count() << endl;  // 1
    cout << "p2 count: " << p2.use_count() << endl;  // 0
    cout << "-------------------\n";
    
    p2 = p1;  // 先copy构造 for base class, 再右值copy构造
    cout << "-------------------\n";
    cout << "p2 count: " << p2.use_count() << endl;  // 2
    cout << "p1 count: " << p1.use_count() << endl;  // 2
    
    cout << "-------------------\n";
    smart_ptr<shape> p3 = p2;   // 普通copy构造
    cout << "p1 count: " << p1.use_count() << endl;  // 3 
    cout << "p2 count: " << p2.use_count() << endl;  // 3
    cout << "p3 count: " << p3.use_count() << endl;  // 3
    
    
    // smart_ptr<triangle> p3;
    // p3 = p1;    // error: cannot convert ‘circle* const’ to ‘triangle*’ in assignment
    // cout << "p3 count: " << p3.use_count() << endl;
    
    return 0;
}