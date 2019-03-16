// at(size_type n)
// clear()
// push_back(), pop_back()
// reserve()

#include <iostream>
using namespace std;
#include <vector>

void print_vector_way_1(const vector<int>& v) {
    for(auto iter=v.begin(); iter!=v.end(); ++iter) {
        cout << *iter << ", ";
    }
    cout << endl;
}

void print_vector_way_2(const vector<int>& v) {
    for (auto i : v) {
        cout << i << ", ";
    }
    cout << endl;
}

void print_vector_way_3(const vector<int>& v) {
    for (int i=0; i<v.size(); ++i) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

void test_erase() {
  std::vector<int> myvector{1,2,3,4,5,6,7,8,9,10};

  // erase the 6th element, i.e. 6
  myvector.erase(myvector.begin()+5);

  // erase the first 3 elements
  myvector.erase(myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (auto i : myvector) {
    std::cout << ' ' << i;
  }
  std::cout << endl;
  std::cout << "size of myvector is: " << myvector.size() << endl;
}

void test_front()
{
  std::vector<int> myvector;
  myvector.push_back(78);
  myvector.push_back(16);

  // now front is 78, and back is 16
  myvector.front() -= myvector.back();  // front=78-16=62
  std::cout << "myvector.front() is now " << myvector.front() << std::endl;
}

int main()
{
    vector<int> v1{1,2,3,4,5,6,7,8,9,10};
    print_vector_way_1(v1);
    print_vector_way_2(v1);
    print_vector_way_3(v1);
    test_erase();
    test_front();
    
    return 0;
}
