#include <iostream>
#include <thread>
#include <chrono> 

void pause_thread(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "pause of " << n << " seconds ended\n"; 
}

int main()
{
    std::cout << "Spawning 3 threads...\n"; 
    std::thread t1(pause_thread, 5);
    std::thread t2(pause_thread, 10);
    std::thread t3(pause_thread, 15);
    
    std::cout << "Done spwaning. Now wait for them to join\n"; 
    t1.join();
    t2.join();
    t3.join();
    std::cout << "All threads joined!\n";
    
    return 0;
}