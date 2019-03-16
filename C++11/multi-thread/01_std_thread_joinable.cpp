#include <iostream>
#include <thread>
#include <chrono>
 
void foo()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
 
int main()
{
    // std::thread::joinable()
    // true if the thread object identifies an active thread of execution, false otherwise
    
    std::thread t;
    std::cout << "before starting, joinable: " << t.joinable() << '\n';     // 0
 
    t = std::thread(foo);
    std::cout << "after starting, joinable: " << t.joinable() << '\n';      // 1
    
    t.join();
    std::cout << "after joining, joinable: " << t.joinable() << '\n';       // 0
}
