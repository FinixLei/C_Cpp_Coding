#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>

template <typename RAIter>
int parallel_sum(RAIter beg, RAIter end)
{
    auto len = end - beg;
    if (len > 1000) return std::accumulate(beg, end, 0);

    RAIter mid = beg + len / 2;
    auto handle = std::async(std::launch::async, parallel_sum<RAIter>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}

int main()
{
    std::vector<int> v(10000);
    int init = 1;
    for (int i = 0; i < v.size(); ++i) {
        v[i] = init;
        init++;
    }

    std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << std::endl;
}
