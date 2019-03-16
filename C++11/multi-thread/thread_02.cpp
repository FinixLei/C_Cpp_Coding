#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>

void f1(int n) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    for(int i=0; i<5; ++i) {
        std::cout << "Thread " << n << "." << i << " executing\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void f2(int &n) {
    n = 0;
    while(n < 5) {
        std::cout << "Thread 2." << n << " executing\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(7));
    }
}

int main(){
    int n = 3;
    std::thread t1;  // not a thread
    std::thread t2(f1, 1);  // pass by value
    std::thread t3(f2, std::ref(n));  // pass by reference
    std::thread t4(std::move(t3));  // t4 is now running f2(), t3 is no longer a thread
    
    t2.join();
    t4.join();
    std::cout << "Final value of n is " << n << "\n";
}

/**! Output as below
Thread 2.Thread 0 executing
1.0 executing
Thread 1.1 executing
Thread 2.1 executing
Thread 1.2 executing
Thread 2.2 executing
Thread 1.3 executing
Thread 2.3 executing
Thread 1.4 executing
Thread 2.4 executing
Final value of n is 5
**/
