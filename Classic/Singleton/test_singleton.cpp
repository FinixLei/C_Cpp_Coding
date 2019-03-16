#include "singleton.hpp"
#include <iostream>
using namespace std;


int main()
{
    Singleton *p = Singleton::get_instance();
    if (p == NULL) cout << "p is NULL\n";
    else cout << "p is not NULL\n";
    
    Singleton *q = Singleton::get_instance();
    cout << hex << p << endl;
    cout << hex << q << endl;
    
    return 0;
}