#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
    stringstream ss;
    int tid = 10;
    ss << "this is thread " << tid << "\n";
    cout << ss.str();  // this is thread 10
    
    stringstream ss2; 
    ss2 << "thread_id: " << 20;
    
    int thread_id;
    string sentence;
    ss2 >> sentence >> thread_id; 
    cout << sentence << thread_id << endl;  // thread_id:20  Note, no space prior to 20
    
    return 0;
}
