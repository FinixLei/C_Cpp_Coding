#include <vector>
#include <iostream>
using namespace std;


void print_vector(vector<int>& vec) 
{
    for(auto i:vec) cout << i << " ";
    cout << endl;
}

// 堆以层次序排列在vector中， 
// 以i位置为顶点的子堆中，唯有该顶点位置不对，其他位置都遵从大顶堆的定义
// 本函数用以下沉调整该顶点
// 注意：
//   size并不一定是vector.size()
//   在建堆的时候，size是vector.size(); 
//   但是在堆排序的过程中，size是不断缩小的。
void siftdown(vector<int>& vec, int i, int size) 
{
    int j = 2 * i + 1;
    while (j<size) {
        if (j+1<size && vec[j]<vec[j+1]) j++;
        if (vec[i] < vec[j]) {
            std::swap(vec[i], vec[j]);
            i = j;
            j = 2*i+1;
        }
        else {
            break;
        }
    }
}

void create_heap(vector<int>& vec)
{
    int size = vec.size();
    int i = (size-2)/2;  // 最后一个节点的父节点
    for (; i>=0; --i) {
        siftdown(vec, i, size);
        // print_vector(vec);
    }
}

void heap_sort(vector<int>& vec)
{
    int i = vec.size()-1;
    while (i>0) {
        std::swap(vec[0], vec[i]);
        // cout << "<<<< "; print_vector(vec);
        siftdown(vec, 0, i);
        // cout << "#### "; print_vector(vec);
        --i;
    }
}

int main()
{
    vector<int> vec{10, 43, 55, 33, 39, 8, 99, 100};
    print_vector(vec);
    create_heap(vec);
    cout << "--------------------\n";
    heap_sort(vec);
    print_vector(vec);
    
    return 0;
}
