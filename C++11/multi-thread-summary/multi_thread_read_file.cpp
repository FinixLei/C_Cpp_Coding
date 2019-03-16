#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
using namespace std;


void thread_read_file(int tid, const string& file_path)
{
    ifstream file(file_path.c_str(), ios::in);
    if (!file.good()) {
        stringstream ss;
        ss << "Thread " << tid << " failed to open file: " << file_path << "\n";
        cout << ss.str();
        return;
    }
    
    int pos; 
    if (tid == 0) pos = 0;
    else pos = tid*10; 
    
    file.seekg(pos, ios::beg);
    string line;
    getline(file, line);
    stringstream ss;
    ss << "Thread " << tid << ", pos=" << pos << ": " << line << "\n";
    cout << ss.str();
}

void test_detach(const string& file_path)
{
    for (int i=0; i<10; ++i) {
        std::thread  th(thread_read_file, i, file_path);
        th.detach(); 
    }
}

void test_join(const string& file_path)
{
    vector<std::thread> vec_threads;
    for (int i=0; i<10; ++i) {
        std::thread  th(thread_read_file, i, file_path);
        vec_threads.emplace_back(std::move(th));  // push_back() is also good
    }
    
    auto it = vec_threads.begin();
    for (; it != vec_threads.end(); ++it) {
        (*it).join();
    }
}


int main()
{
    string file_path = "./1.txt";
    test_detach(file_path);
    std::this_thread::sleep_for(std::chrono::seconds(1)); // wait for detached threads done
    test_join(file_path);

    return 0;
}
