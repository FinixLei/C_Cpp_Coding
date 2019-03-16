#include <thread>
#include <future>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
 
int main()
{
    std::istringstream iss_numbers{"3 4 1 42 23 -23 93 2 -289 93"};
    std::istringstream iss_letters{" a 23 b,e a2 k k?a;si,ksa c"};
 
    std::vector<int> numbers;
    std::vector<char> letters;
    std::promise<void> numbers_promise, letters_promise;
 
    auto numbers_ready = numbers_promise.get_future();
    auto letter_ready = letters_promise.get_future();
 
    std::thread value_reader([&]
    {
        // I/O operations.
        std::copy(std::istream_iterator<int>{iss_numbers},
                  std::istream_iterator<int>{},
                  std::back_inserter(numbers));
 
        // Notify for numbers.
        // future will become ready, i.e. 
        // numbers_promise.get_future() will become ready
        numbers_promise.set_value();
 
        std::copy_if(std::istreambuf_iterator<char>{iss_letters},
                     std::istreambuf_iterator<char>{},
                     std::back_inserter(letters),
                     ::isalpha);
 
        // Notify for letters.
        // future will become ready, i.e. 
        // letters_promise.get_future() will become ready
        letters_promise.set_value();
    });
    
    numbers_ready.wait();  // future::wait()
 
    std::sort(numbers.begin(), numbers.end());
 
    /* Actually, we don't need this paragraph of code. 
    if (letter_ready.wait_for(std::chrono::seconds(1)) ==
            std::future_status::timeout)
    {
        std::cout<<"print numbers now: \n";
        //output the numbers while letters are being obtained.
        for (int num : numbers) std::cout << num << ' ';
        numbers.clear(); //Numbers were already printed.
    }
    */
 
    letter_ready.wait();  // future.wait()
    std::sort(letters.begin(), letters.end());
 
    //If numbers were already printed, it does nothing.
    for (int num : numbers) std::cout << num << ' ';
    std::cout << '\n';
 
    for (char let : letters) std::cout << let << ' ';
    std::cout << '\n';
 
    value_reader.join();
    // value_reader.detach();
}

/** Output:  
-289 -23 1 2 3 4 23 42 93 93
a a a a b c e i k k k s s
**/  

