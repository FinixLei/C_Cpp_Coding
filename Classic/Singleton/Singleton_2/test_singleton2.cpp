#include "Singleton.hpp"
#include <iostream>
#include <thread>
#include <sstream>
using namespace std;


bool bReady = false;

void thread_func()
{
    while (!bReady) { }

    Singleton& s = Singleton::getInstance();

    stringstream ss;
    ss << "Address of s is " << hex << &s << "\n";
    cout << ss.str();
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
