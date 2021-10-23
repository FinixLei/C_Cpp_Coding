#include <iostream>
#include "shared_ptr_list.hpp"

using namespace std;
using namespace finix;

int main()
{
    List<int> mylist;
    
    for (int i=0; i<10; i++) {      // try 1e5
        mylist.push_back(i+1);
    }
    for (int i=100; i>=91; i--) {
        mylist.push_front(i);
    }
    
    cout << "front: " <<  mylist.front() << endl;
    mylist.pop_front();
    cout << "front: " << mylist.front() << endl;
    mylist.pop_front();
    
    cout << "back:  " << mylist.back() << endl;
    mylist.pop_back();
    cout << "back:  " << mylist.back() << endl;
    mylist.pop_back();
    
    mylist.traverse_list();
    
    cout << "Done..." << endl;
    
    return 0;
}

