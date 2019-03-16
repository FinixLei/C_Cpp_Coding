#include "auto_ptr.h"
#include <iostream>
using namespace std;


int main()
{
    int *a = new int (10);
    auto_ptr<int> pa(a);
    cout << *pa << endl;
    
    auto_ptr<int> pb = pa;
    cout << *pb << endl; 
    if (pa.get()==0) cout << "pa is NULL now\n";
    else cout << "Error: pa is not NULL. \n";
    
    auto_ptr<int> pc; 
    pc = pb; 
    *pc = 20;
    cout << *pc << endl;
    if (pb.get()==0) cout << "pb is NULL now\n";
    else cout << "Error: pb is not NULL. \n";
}
