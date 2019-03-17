/*
    set - 集合 （关联容器）
    
    insert() - return pair<iterator, bool>, 若已存在，则insert失败，bool为false
    emplace()  - 返回值与insert相同, i.e. pair<iterator, bool>
    equal_range()
    
    find()
    count()
    empty()
    size()
    max_size()
    
    swap()
*/

// set::begin/end
#include <iostream>
#include <set>
using namespace std;


void test_find()
{
    std::set<int> myset;
    std::set<int>::iterator it;
    
    // set some initial values:
    for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50
    
    it=myset.find(20);
    myset.erase (it);
    myset.erase (myset.find(40));  // 10 30 50
    
    std::cout << "myset contains:";
    for (it=myset.begin(); it!=myset.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
}

int main ()
{
  int myints[] = {75,23,65,482,13};
  std::set<int> myset (myints,myints+5);

  std::cout << "myset contains:";
  for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << endl;
  // 13 23 65 75 482
  
  test_find();  // 10 30 50
  
  return 0;
}
