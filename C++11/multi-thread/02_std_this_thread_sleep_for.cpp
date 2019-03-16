#include <iostream>
#include <chrono>
#include <thread>

void test_sleep_for()
{
    std::cout << "Hello waiter" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;
    std::cout << "Waited " << elapsed.count() << " ms\n";
}

int main()
{
    test_sleep_for();
}

// Possible Output
// Hello waiter
// Waited 2000.41 ms
