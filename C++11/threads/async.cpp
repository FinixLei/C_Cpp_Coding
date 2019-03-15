// http://blog.csdn.net/nirendao/article/details/50612713

#include <future>  
#include <iostream>  
#include <ctime>  
  
void test_time_1() {  
    std::future<int> future = std::async(std::launch::deferred, [](){  
        std::this_thread::sleep_for(std::chrono::seconds(5));  
        return 100;  
    });  
    std::cout << "waiting...\n";  
  
    clock_t start = clock();  
    std::future_status status = future.wait_for(std::chrono::seconds(10));  
    std::cout << "result is " << future.get() << std::endl;  
    clock_t end = clock();  
    std::cout << "Time Cost : " << (double)(end - start) / CLOCKS_PER_SEC << " seconds." << std::endl;  
}  
  
void test_time_2() {  
    std::future<int> future = std::async(std::launch::deferred, [](){  
        std::this_thread::sleep_for(std::chrono::seconds(5));  
        return 100;  
    });  
    std::cout << "waiting...\n";  
  
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();  
    std::future_status status = future.wait_for(std::chrono::seconds(10));  
    std::cout << "result is " << future.get() << std::endl;  
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();  
      
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);  
    std::cout << "Time Cost: " << time_span.count() << " seconds.";  
}  
  
int main()  
{  
    test_time_1();  
    test_time_2();  
}  