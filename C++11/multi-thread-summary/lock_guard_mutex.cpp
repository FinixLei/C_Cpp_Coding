#include <map>
#include <string>
#include <chrono>
#include <mutex>
#include <thread>
#include <sstream>
#include <iostream>
using namespace std;


map<string, string> web_pages;
std::mutex global_mutex;

void save_page(const string& page_name, const string &page_content)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::lock_guard<std::mutex> guard(global_mutex);
    web_pages[page_name] = page_content;
    stringstream ss;
    ss << "thread id is " << std::this_thread::get_id() << ". page_name is " << page_name << "\n";
    cout << ss.str();
}


int main()
{
    thread t1(save_page, "https://lenovo.com", "Hello, Lenovo!");
    thread t2(save_page, "https://google.com", "Hello, Google!");
    
    t1.join();
    t2.join();
    
    for (const auto &page : web_pages) {
        cout << page.first << " -> " << page.second << endl;
    }
    
    return 0;
}
