#include <vector>
#include <string>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename T>
print_container(T& ct) {
    for (auto i : ct) { cout << i << " "; } cout << endl;
}

template<typename T>
print_map(T& ct) {
    for (auto i : ct) {
        cout << i.first << " => " << i.second << endl;
    }
}


int main()
{
    // 序列容器-general: erase-remove 特定值 - c.erase(remove(c.beigin(), c.end(), value), c.end());
    vector<int> vec1{10, 20, 30, 30, 20, 10};
    auto it = remove(vec1.begin(), vec1.end(), 20);
    
    cout << "vec1 size = " << vec1.size() << endl;
    print_container(vec1);  // 10 20 30 30 20 10
    
    vec1.erase(it, vec1.end());
    cout << "vec1 size = " << vec1.size() << endl;
    print_container(vec1);  // 10 30 30 10
    
    // 序列容器-list: 直接用 remove 删除特定值 - list.remove(value)
    list<int> list1{1, 2, 3, 3, 2, 1};
    print_container(list1);
    list1.remove(2);
    print_container(list1);  // 1 3 3 1
    
    // 序列容器-general：erase-remove_if 特定条件 - c.erase(remove_if(c.begin(), c.end(), []()->bool{return true or false;}), c.end());
    vector<int> vec2{10, 20, 30, 30, 20, 10};
    auto it2 = remove_if(vec2.begin(), vec2.end(), [](int value)->bool {
        if (value == 20) return true;
        else return false; 
    });
    print_container(vec2);  // 10 20 30 30 20 10
    vec2.erase(it2, vec2.end());  
    print_container(vec2);  // 10 30 30 10
    
    // 序列容器-general: 用循环删除特定条件 - it=c.erase(it); 或 c.erase(it++);
    vector<int> vec3{40, 50, 60, 60, 50, 40};
    print_container(vec3);
    for(auto it=vec3.begin(); it!=vec3.end();) {
        if (*it == 50) {
            it = vec3.erase(it);  // 序列容器的erase返回被删除元素的下一个元素的iterator
            // vec3.erase(it++);  // 实际上这种后++的方法也可以，这也是用于关联容器的方法
        }
        else {
            it++;
        }
    }
    print_container(vec3);
    
    // 关联容器: 删除特定值 - 直接erase(key)
    map<string, int> m1{
        pair<string, int>("k1", 10), 
        pair<string, int>("k2", 20), 
        pair<string, int>("k3", 30)};
    print_map(m1);
    
    m1.erase("k2"); 
    print_map(m1);  // 缺了 k2 => 20 
    
    cout << "multimap:" << endl;
    multimap<string, int> m2;
    m2.insert(pair<string, int>("a", 10));
    m2.insert(pair<string, int>("b", 20)); 
    m2.insert(pair<string, int>("a", 30));
    print_map(m2);
    cout << "multimap:" << endl;
    m2.erase("a");  // 2 items about "a" are all deleted
    print_map(m2);  // b => 20
    cout << "End of multimap" << endl;
    
    // 关联容器：循环删除特定条件 - c.erase(it++)
    set<int> s1{1,2,3,4,5,6};
    print_container(s1);  // 1 2 3 4 5 6 
    
    for (auto it=s1.begin(); it!=s1.end();) {
        if (*it % 2 == 1) {
            // 关联容器的erase在删除元素后，被删元素的iterator作废，无法+1，因此要在删除前令其后++
            s1.erase(it++);
        }
        else {
            it++;
        }
    }
    print_container(s1);  // 2 4 6
    
    return 0;
}
