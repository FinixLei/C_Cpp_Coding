#include <mutex>
#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
 
int main()
{
    int counter = 0;
    std::mutex counter_mutex;
    std::vector<std::thread> threads;
 
    auto worker_task = [&](int id) {
        // Note, this is just lock, as it is RAAI (Resource Acquisition is Initialization)
        std::unique_lock<std::mutex> lock(counter_mutex);  
        
        ++counter;
        std::cout << id << ", initial counter: " << counter << '\n';
        lock.unlock();
        
        // don't hold the lock while we simulate an expensive operation
        std::this_thread::sleep_for(std::chrono::seconds(1));
 
        lock.lock();
        ++counter;
        std::cout << id << ", final counter: " << counter << '\n';
    };
 
    for (int i = 0; i < 10; ++i) {
        // vector::push_back() cannot work due to std::thread is not copyable.
        threads.emplace_back(worker_task, i);
    }
 
    for (auto &thread : threads) thread.join();
}


/**
Possible Output:
0, initial counter: 1
1, initial counter: 2
2, initial counter: 3
3, initial counter: 4
4, initial counter: 5
5, initial counter: 6
6, initial counter: 7
7, initial counter: 8
8, initial counter: 9
9, initial counter: 10
1, final counter: 11
0, final counter: 12
3, final counter: 13
5, final counter: 14
2, final counter: 15
4, final counter: 16
7, final counter: 17
9, final counter: 18
6, final counter: 19
8, final counter: 20
**/

