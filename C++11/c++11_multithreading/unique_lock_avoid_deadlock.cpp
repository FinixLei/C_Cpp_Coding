#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>
 
struct Box {
    explicit Box(int num) : num_things{num} {}
 
    int num_things;
    std::mutex m;
};
 
void transfer(Box &a, Box &b, int num)
{
    // don't actually take the locks yet
    std::unique_lock<std::mutex> lock1(a.m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(b.m, std::defer_lock);
 
    // lock both unique_locks without deadlock
    std::lock(lock1, lock2);
 
    a.num_things -= num;
    b.num_things += num;
 
    // 'a.m' and 'b.m' mutexes unlocked outside of 'unique_lock'
}
 
int main()
{
    Box acc1(100);
    Box acc2(50);
 
    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);
 
    t1.join();
    t2.join();
    
    std::cout << "acc1: " << acc1.num_things << std::endl;
    std::cout << "acc2: " << acc2.num_things << std::endl;
}

/** Output: 
acc1: 95
acc2: 55
**/

