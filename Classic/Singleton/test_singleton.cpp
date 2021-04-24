// g++ singleton.cpp test_singleton.cpp

#include "singleton.h"
#include <iostream>
#include <thread>
#include <sstream>
using namespace std;


bool bReady = false;

void thread_func()
{
    while (!bReady) { }

    Singleton *p = Singleton::get_instance();
    if (p == NULL) {
        cout << "p is NULL\n";
    }
    else {
        stringstream ss;
        ss << "p is not NULL. p = " << hex << p << "\n";
        cout << ss.str();
    }
}


int main()
{
    thread th1(thread_func);
    thread th2(thread_func);
    
    bReady = true;
    
    th1.join();
    th2.join();
    
    return 0;
}
