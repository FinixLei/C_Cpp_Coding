#include <vector>
#include <iostream>
using namespace std;


/*
    从m个数字中选n个的所有排列
    递归：
    先确定最后1个数字是必选的，则接下来只要从 m-1 个数字中选 n-1 个；
    然后确定倒数第2个数字是必选的，则接下来只要从 m-2 个数字中选 n-2 个； 
    依此类推。
    
    若在第1轮中就确定倒数第2个数字是必选的，则意味着倒数第1个数字在将来也是必不会被选的，
    否则会引起重复；
    所以，若第1轮确定的是倒数第2个数字，那么意味着接下来要从m-2个数字中选n-1个数字；
    同理，若第1轮确定的是倒数第3个数字，那么意味着接下来要从m-3个数字中选n-1个数字；
    依此类推。
*/
list_all_n_of_m(int m, int n, const vector<int> array, vector<int>& result, vector<vector<int>>& all_lists)
{
    for (int i=m; i>=n; i--)
    {
        result.push_back(array[i-1]);
        if (n > 1)
        {
            list_all_n_of_m(i-1, n-1, array, result, all_lists);
        }
        else
        {
            all_lists.push_back(result);
        }
        result.pop_back();
    }
}

int main()
{
    vector<int> array({1, 2, 3, 4, 5});
    vector<int> tmp; 
    
    vector<vector<int>> all_lists;
    list_all_n_of_m(array.size(), 3, array, tmp, all_lists);
    
    for (auto vec : all_lists) {
        for (auto i : vec) { cout << i << " "; }
        cout << endl;
    }
    cout << "Total count: " << all_lists.size() << endl;
    
    return 0;
}