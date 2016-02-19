#include <iostream>
#include <functional>
using namespace std;

class A {
public:
    virtual void open_internal() {
        cout << "A::open_internal()" << endl;
    }
    
    void open() {  // not virutal function
        cout << "A::open()" << endl;
        open_internal();
    }
};

class B: public A {
public:
    void open_internal() {
        cout << "B::open_internal()" << endl;
    }
    
    virtual void open() {
        cout << "B::open()" << endl;
    }
};

void print() {
    cout << "In print()" << endl;
}

int main() {
    A * p = new B;
    std::function<void(void)> f1 = std::bind(&A::open, p);
    f1(); // A::open(), B::open_internal()
    
    void (*f2)(void);
    f2 = print;  // Cannot define a function pointer for p->open() or A::open()
    f2();  // In print()

    return 0;
}
