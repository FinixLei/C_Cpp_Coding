/*
  Given sevearl numbers and a figure n, 
  list all the sequences which contains n elements and the numbers mentioned above.
  There can be duplicated. 
  给定几个数字与一个数n，写出含有这几个数字的n位的全排列，允许有重复。
*/

#include <vector>
#include <iostream>
using namespace std;

static int total = 0;

const vector<int> vec{1, 2, 3}; 
const int n = 5;

void list_all(int n, int pos, vector<int> & target_vec) {
    if (pos >= n) {
        for (auto i : target_vec) {
            cout << i << " ";
        }
        cout << endl;
        total++;
        return; 
    }
    
    for (int i=0; i<vec.size(); ++i) {
        target_vec.push_back(vec[i]);
        pos++;
        list_all(n, pos, target_vec);
        pos--;
        target_vec.pop_back();
    }
}


int main()
{
    vector<int> vec;
    list_all(n, 0, vec);
    cout << "total number is " << total << endl;
    return 0;
}
