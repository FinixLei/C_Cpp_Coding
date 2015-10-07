/*
    Given sevearl numbers and a figure n, list all the sequences which contains n elements and the numbers mentioned above. There can be duplicated. 
    给定几个数字与一个数n，写出含有这几个数字的n位的全排列，允许有重复。
*/

#include <iostream>
using namespace std;

static int count=0;

void fn(int a[], int asize, int b[], int bsize, int cur)
{
    if (cur == bsize)
    {
        for(int i=0; i<bsize; i++)
            cout<<b[i]<<" ";
        cout<<endl;
        count++;
        return;
    }
    
    for(int i=0; i<asize; i++)
    {
        b[cur]=a[i];
        fn(a, asize, b, bsize, cur+1);
    }
}

int main()
{
    int a[3]={1, 2, 3};
    int b[5];

    fn(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int), 0);
    cout<<count<<endl;  // 3^5 = 243
    
    return 0;
}
