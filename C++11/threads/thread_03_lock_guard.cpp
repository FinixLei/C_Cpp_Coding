#include <iostream>
#include <thread>       // std::thread
#include <mutex>        // std::mutex, std::lock_guard
#include <stdexcept>    // std::logic_guard

std::mutex mtx;

void print_even(int x) {
    if (x % 2 ==0) {
        std::cout << x << " is even\n";
    } 
    else {
        throw(std::logic_error("not even"));
    }
}

void print_thread_id(int id) {
    try {
        // use a local lock_guard to lock mtx for guaranteeing unlocking on destruction or exception
        std::lock_guard<std::mutex> lck(mtx);
        print_even(id);
    }
    catch (std::logic_error&){
        std::cout << "[Exception Caught]\n";
    }
}

int main() {
    const int size = 10;
    std::thread threads[size];
    
    for (int i=0; i<size; ++i) {
        threads[i] = std::thread(print_thread_id, i+1);
    }
    
    for (auto& th : threads) th.join();
    
    return 0;
}

/**! Output as below
[Exception Caught]
2 is even
[Exception Caught]
4 is even
[Exception Caught]
6 is even
[Exception Caught]
8 is even
[Exception Caught]
10 is even
**/