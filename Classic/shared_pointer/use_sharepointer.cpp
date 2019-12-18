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
    cout << "p1 count: " << p1.use_count() << endl; 
    
    smart_ptr<shape> p2;
    cout << "p2 count: " << p2.use_count() << endl; 
    
    p2 = p1;
    cout << "p2 count: " << p2.use_count() << endl;
    
    // smart_ptr<triangle> p3;
    // p3 = p1;    // error: cannot convert ‘circle* const’ to ‘triangle*’ in assignment
    // cout << "p3 count: " << p3.use_count() << endl;
    
    return 0;
}