/*
    关键点是：
    1. wait()函数的内部实现是：先释放了互斥量的锁，然后等待条件为真；
    2. notify系列函数需在unlock之后再被调用。
    3. 套路是：
        a. A线程拿住锁，然后wait,此时已经释放锁，只是阻塞了在等待条件为真；
        b. B线程拿住锁，做一些业务处理，然后领等待条件为真，释放锁，再调用notify函数；
        c. A线程被唤醒，接着运行。
    4. 只能用unique_lock, 这种lock是movable的。
*/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
 
std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;
 
void worker_thread()
{
    {
        // Wait until main() sends data
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{return ready;});
    }
 
    {
        std::unique_lock<std::mutex> lk(m);
        // after the wait, we own the lock.
        std::cout << "Worker thread is processing data\n";
        data += " after processing";
     
        // Send data back to main()
        processed = true;
        std::cout << "Worker thread signals data processing completed\n";
    }
    
    cv.notify_one();
}
 
int main()
{
    std::thread worker(worker_thread);
 
    data = "Example data";
    // send data to the worker thread
    {
        std::unique_lock<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();
 
    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{return processed;});
    }
    
    std::cout << "Back in main(), data = " << data << '\n'; 
    worker.join();
}
