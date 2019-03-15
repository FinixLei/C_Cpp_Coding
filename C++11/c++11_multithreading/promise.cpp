#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
 
void accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last,
                std::promise<int> accumulate_promise)
{
    int sum = std::accumulate(first, last, 0);
    accumulate_promise.set_value(sum);  // Set future as ready
}
 
int main()
{
    std::vector<int> numbers{ 1, 2, 3, 4, 5, 6 };
    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    
    std::thread work_thread(accumulate, numbers.begin(), numbers.end(),
                            std::move(accumulate_promise));
    // work_thread.detach();

    // accumulate_future.wait();  // future::wait(), it can run without this line 
    std::cout << "result=" << accumulate_future.get() << '\n';  // future::get()
    work_thread.join();  // wait for thread completion
}

/** Output: 
result=21
**/  
