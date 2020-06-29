#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v1(10);
    vector<int> v2; 
    v2.reserve(20);
    
    cout << v1.size() << endl;  // 10
    cout << v2.size() << endl;  // 0
    
    cout << v1.capacity() << endl;  // 10
    cout << v2.capacity() << endl;  // 20
    
    for (int i=0; i<11; i++) {
        v1.push_back(i);
    }
    cout << v1.size() << endl;      // 21=10+11
    cout << v1.capacity() << endl;  // 40
    
    return 0;
}