#include <iostream>
#include <thread>
#include <chrono>
 
void foo()
{
    std::cout << "start...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "end...\n";
}
 
int main()
{
    std::thread t1(foo);
    std::thread::id t1_id = t1.get_id();
 
    std::thread t2(foo);
    std::thread::id t2_id = t2.get_id();
 
    std::cout << "t1's id: " << t1_id << '\n';
    std::cout << "t2's id: " << t2_id << '\n';
 
    t1.join();
    t2.join();
}

// Output: 
// start...
// start...
// t1's id: 0x600010520
// t2's id: 0x600010660
// end...
// end...
