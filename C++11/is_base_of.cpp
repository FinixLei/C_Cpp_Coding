#include <type_traits>
#include <iostream>
#include <string>
using namespace std;

class A {};

class B : public A 
{};

class C: public B
{};

class D {};

int main()
{
    if (std::is_base_of<A, typename std::remove_pointer<C>::type>::value) 
        cout << "True" << endl;  // True
    else 
        cout << "False" << endl;
    
    if (std::is_base_of<A, typename std::remove_pointer<D>::type>::value) 
        cout << "True" << endl;
    else 
        cout << "False" << endl;  // False

    return 0;
}
