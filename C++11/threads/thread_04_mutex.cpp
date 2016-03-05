#include <iostream>
#include <thread>
#include <mutex>

volatile int counter(0);  // non-atomic counter
std::mutex mtx;  // lock access to counter

void attempt_10k_inc() {
    for (int i=0; i<10000; ++i) {
        if (mtx.try_lock()) {
            // only increase if lock can be got successfully
            ++counter;
            mtx.unlock();
        }
    }
}

int main() {
    const int size = 10;
    std::thread threads[size];
    for (int i=0; i<size; ++i) {
        threads[i] = std::thread(attempt_10k_inc);
    }
    
    for (auto & th : threads) th.join();
    std::cout << counter << " successful increases of the counter. \n";
    
    return 0;
}

/**! Output as below 
29357 successful increases of the counter.
**/
