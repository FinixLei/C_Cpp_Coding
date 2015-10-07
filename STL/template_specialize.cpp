#include <algorithm>
#include <iostream>

namespace std {
    template<>
    void swap<int>(int & a, int & b)
    {
        a = 1000;
        b = 2000;
    }
}

int main(int argc, char *argv[])
{
    int a = 99;
    int b = 100;
    std::swap(a, b);
    std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
    
    return 0;
}
