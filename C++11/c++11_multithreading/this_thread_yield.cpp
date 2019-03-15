/*
对具体实现（译注：具体实现指的是操作系统的调度器）提出一个提醒以重新规划线程的执行，即让其他线程先运行。
注意：
该方法的具体行为取决于实现，尤其是正在使用的操作系统调度器的机制以及系统的状态。
比如，一个先进先出的实时调度器（Linux中的SCHED_FIFO）将会使当前线程暂停，
并将其置于同优先级线程队列的末尾（如果同优先级线程队列里没有其他线程，yield就没有效果了。）
*/

#include <iostream>
#include <chrono>
#include <thread>
 
// "busy sleep" while suggesting that other threads run 
// for a small amount of time
void little_sleep(std::chrono::microseconds us)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start + us;
    do {
        std::this_thread::yield();
    } while (std::chrono::high_resolution_clock::now() < end);
}
 
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
 
    little_sleep(std::chrono::microseconds(100));
 
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "waited for "
              << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
              << " microseconds\n";
}
