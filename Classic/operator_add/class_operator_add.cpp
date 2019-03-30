#include <iostream>
using namespace std;

class A 
{
private:
    int value;
    
public:
    A(int v=0) {
        value = v;
        cout << "In A's constructor: value=" << value << endl; 
    }
    
    A(const A& other) {
        value = other.value;
        cout << "In A's const left copy constructor: value=" << value << endl;
    }
    
    A(A& other) {
        value = other.value;
        cout << "In A's left copy constructor: value=" << value << endl;
    }
    
    A& operator = (const A& other) {
        if (this == &other) {
            return *this;
        }
        value = other.value;
        cout << "In A's operator=, value=" << value << endl; 
        return *this;
    }
    
    
    void print_value() {
        cout << value << endl << endl;
    }
    
    A operator + (const A& other) {
        A tmp;
        tmp.value = this->value + other.value;
        cout << "In A's operator+, value=" << tmp.value << endl;
        return tmp;
    }
    
    friend A operator+ (int v, A& a);
    
};

A operator+ (int v, A& a) 
{
    A tmp;
    tmp.value = v + a.value; 
    cout << "In friend operator+, value=" << tmp.value << endl;
    return tmp;
}

int main()
{
    A a = 10;  // 只是构造函数，没有先构造再copy构造
    a.print_value();
    
    A b = 20;
    A c = a + b; 
    c.print_value();
    
    c = a + 30;
    c.print_value();
    
    c = 30 + b; 
    c.print_value();
    
    c = c + c; 
    c.print_value();
    
    A d = a;  // "left copy constructor "
    // Why statement in copy constructor is not printed when return from/pass parameter to a function? 
    
    return 0;
}