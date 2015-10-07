#include <iostream>
using namespace std;

#include "autoptr.h"

int main() {
    int * a = new int(100);
    autoptr<int> pa(a);
    cout << "*pa = " << *pa << endl;
    
    (* pa.get()) = 200;
    cout << "*pa = " << *pa << endl;
    
    *pa = 300;
    cout << "*pa = " << *pa << endl;
}
