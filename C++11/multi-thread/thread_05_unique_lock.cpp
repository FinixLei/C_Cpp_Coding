#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_block(int n, char c) {
    // critical session (exclusive access to std::cout signaled by life time of lck)
    std::unique_lock<std::mutex> lck(mtx);
    for (int i=0; i<n; ++i) {
        std::cout << c;
    }
    std::cout << std::endl;
}

int main() {
    std::thread th1(print_block, 20, '*');
    std::thread th2(print_block, 20, '#');
    std::thread th3(print_block, 20, 'a');
    std::thread th4(print_block, 20, '&');
    
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    
    return 0;
}
