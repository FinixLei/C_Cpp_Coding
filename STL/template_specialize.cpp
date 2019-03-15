#include <algorithm>
#include <iostream>
using namespace std;

namespace std {
    template<>
    void swap<int>(int & a, int & b)
    {
        a = a ^ b; 
        b = a ^ b; 
        a = a ^ b; 
        a++;
        b++;
    }
}

int main(int argc, char *argv[])
{
    int a = 99;
    int b = 100;
    swap(a, b);
    cout << "a = " << a <<endl;
    cout << "b = " << b <<endl;
    
    return 0;
}
