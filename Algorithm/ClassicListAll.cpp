#include <iostream>
using namespace std;

/* 
令E= {e1 , ..., en }表示n 个元素的集合，我们的目标是生成该集合的所有排列方式。令Ei 为E中移去元素i 以后所获得的集合，
perm (X) 表示集合X 中元素的排列方式，ei . perm(X)表示在perm (X) 中的每个排列方式的前面均加上ei 以后所得到的排列方式。
例如，如果E= {a, b, c}，那么E1= {b, c}，perm (E1 ) = ( b c, c b)，e1 .perm (E1) = (a b c, a c b)。
对于递归的基本部分，采用n = 1。当只有一个元素时，只可能产生一种排列方式。
当n > 1时，perm (E) = e1 .perm (E1) +e2 .perm(E2 ) +e3.perm (E3) + ... +en .perm (En )。
这种递归定义形式是采用n 个perm (X) 来定义perm (E), 其中每个X 包含n- 1个元素。
至此，一个完整的递归定义所需要的基本部分和递归部分都已完成。

源代码：
//辅助函数，用于交换 */
template <class T>
inline void Swap(T& a, T& b)
{
	T temp;
	temp=a; a=b; b=temp;
}

// 也可以不用上述自己定义的Swap而直接用std::swap()


static int count = 0;

//打印出k到m的全排列，包括k和m，调用时:ClassicListAll(array, 0, n-1)
void ClassicListAll(int array[], int start, int end) 
{
    if (start == end) {
        for (int i=0; i<=end; i++) {
            cout<<array[i] <<", ";
        }
        cout<<endl;
        count ++;
        return;
    }
    
    for (int i=start; i<=end; i++) {
        Swap(array[i], array[start]);
        ClassicListAll(array, start+1, end);
        Swap(array[i], array[start]);
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    
    ClassicListAll(array, 0, (sizeof(array)/sizeof(int) - 1)); 
    cout << "There are " << count << " kinds of list for above array. " << endl;
    
    return 0;
}
