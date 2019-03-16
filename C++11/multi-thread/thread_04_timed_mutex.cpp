#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::timed_mutex mtx;

void fireworks() {
    // wait for a lock: each thread prints '-' every 200 ms;
    while (!mtx.try_lock_for(std::chrono::milliseconds(200))) {
        std::cout << "-" ;
    }
    // get a lock! wait for 1s, then prints '*'
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "*\n";
    mtx.unlock();
}

int main() {
    const int size = 10;
    std::thread threads[size];
    for (int i=0; i<size; ++i) {
        threads[i] = std::thread(fireworks);
    }
    for (auto& th : threads) th.join();
    
    return 0;
}
