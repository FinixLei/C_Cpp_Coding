#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
 
std::mutex g_display_mutex;
 
void foo()
{
    // The class thread::id is a lightweight, trivially copyable class 
    // that serves as a unique identifier of std::thread objects.
    std::thread::id this_id = std::this_thread::get_id();
 
    g_display_mutex.lock();  // The usage of g_display_mutex is to keep the printed statement not broken down
    std::cout << "thread " << this_id << " sleeping...\n";
    g_display_mutex.unlock();
 
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
 
int main()
{
    std::thread t1(foo);
    std::thread t2(foo);
 
    t1.join();
    t2.join();
}

// Output:
// thread 0x600010520 sleeping...
// thread 0x6000107b0 sleeping...
