#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
void print_vector(const vector<T>& v)
{
    for (auto item: v) {
        cout << item << " ";
    }
    cout << endl;
}


int main()
{
    int  array[] = {0, 1, 2, 3};
    int size = sizeof(array)/sizeof(array[0]);

    // way-1: push_back 
    vector<int> v1;
    v1.reserve(size);
    for(int i=0; i<size; i++) {
        v1.push_back(array[i]);
    }
    
    // way-2: vec(array, arrya+size)
    // way-2: vec(other.begin(), other.end())
    vector<int> v2_1(array, array+size);
    vector<int> v2_2(v2_1.begin(), v2_1.end()); 
    
    // way-3: copy(array, arrya+size, dst.begin())
    // way-3: copy(src.begin(), src.end(), dst.begin())
    vector<int> v3(size); 
    cout << "After initiation, v3'size is " << v3.size() << endl;
    cout << "capacity: " << v3.capacity() << endl;
    copy(array, array+size, v3.begin());  // if size > v3.size(), then only copy v3.size() numbers 
    
    // way-4: reseve() + self.insert(self.begin(), array, array+size)
    vector<int> v4;
    v4.reserve(size);  // if not reserve, the size is still 0 after initialization
    cout << "After reserve, v4's size is " << v4.size() << endl;
    cout << "capacity: " << v4.capacity() << endl;
    v4.insert(v4.begin(), array, array+size); 
    
    // Not a new way 
    vector<int> v5(size);  // v5.size() is 4 now 
    v5.insert(v5.begin(), array, array+size);   // If use insert, size will increase to 8. 
    // copy(v4.begin(), v4.end(), v5.begin());  // If use copy, the size is still 4. 

    // way-5: vector::vector(number, value)
    vector<int> v6(3, 10);  // 10 10 10
    
    // print vectors
    print_vector(v1);
    print_vector(v2_1);
    print_vector(v2_2);
    print_vector(v3);
    print_vector(v4);
    print_vector(v5);
    print_vector(v6);
    
    // const_iterator 迭代器所指内容不变，而迭代器本身可以改变（如++）
    for (vector<int>::const_iterator cvit=v5.begin(); cvit!=v5.end(); cvit++) {
        cout << *cvit << " ";
    }
    
    return 0;
}
