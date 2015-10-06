#include <vector>
#include <iostream>
using namespace std;

void test_vector_01() {
    int a[] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(int);
    
    vector<int> vi; 
    
    for (int i=0; i<size; i++) {
        vi.push_back(a[i]);
    }
    
    for (vector<int>::iterator vit=vi.begin(); vit!=vi.end(); vit++) {
        cout << *vit << " ";
    }
    cout << endl;
    
    // const_iterator 迭代器所指内容不变，而迭代器本身可以改变（如++）
    for (vector<int>::const_iterator cvit=vi.begin(); cvit!=vi.end(); cvit++) {
        cout << *cvit << " ";
    }
    cout << endl;
}

int main(int argc, char ** argv) {
    test_vector_01();
    
    return 0;
}
