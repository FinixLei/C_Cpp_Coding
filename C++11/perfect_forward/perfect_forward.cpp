#include <iostream>
 using namespace std;
 
void fun(int &x) { cout << "lvalue ref" << endl; }
void fun(int &&x) { cout << "rvalue ref" << endl; }
void fun(const int &x) { cout << "const lvalue ref" << endl; }
void fun(const int &&x) { cout << "const rvalue ref" << endl; }
 
template<typename T>
void perfect_forward(T &&t) { fun(std::forward<T>(t)); }
 
int main()
{
    perfect_forward(10);           // rvalue ref
 
    int a;
    perfect_forward(a);            // lvalue ref
    perfect_forward(std::move(a)); // rvalue ref
 
    const int b = 8;
    perfect_forward(b);            // const lvalue ref
    perfect_forward(std::move(b)); // const rvalue ref
 
    return 0;
}