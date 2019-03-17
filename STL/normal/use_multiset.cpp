/* 
    multiset - 按照某种特定顺序存储值，允许值有重复
    
    clear()
    count()
    find()
    size()
    max_size()
    
    emplace()
    insert()
    erase()
    
    equal_range()
    
    swap()
*/

// multiset::begin/end
#include <iostream>
#include <set>

void test_begin_end()
{
  int myints[] = {42,71,71,71,12};
  std::multiset<int> mymultiset (myints, myints+5);

  std::multiset<int>::iterator it;

  std::cout << "mymultiset contains:";
  for (std::multiset<int>::iterator it=mymultiset.begin(); it!=mymultiset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void test_count()
{
    int myints[]={10,73,12,22,73,73,12};
    std::multiset<int> mymultiset (myints,myints+7);

    std::cout << "73 appears " << mymultiset.count(73) << " times in mymultiset.\n";  // 3
}

void test_equal_range()
{
    typedef std::multiset<int>::iterator It;  // aliasing the iterator type used

    int myints[]= {77,30,16,2,30,30};
    std::multiset<int> mymultiset (myints, myints+6);  // 2 16 30 30 30 77
    
    std::pair<It,It> ret = mymultiset.equal_range(30); //      ^        ^
    
    mymultiset.erase(ret.first,ret.second);
    
    std::cout << "mymultiset contains:";
    for (It it=mymultiset.begin(); it!=mymultiset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void test_erase()
{
    std::multiset<int> mymultiset;
    std::multiset<int>::iterator it;
    
    // insert some values:
    mymultiset.insert (40);                            // 40
    for (int i=1; i<7; i++) mymultiset.insert(i*10);   // 10 20 30 40 40 50 60
    
    it=mymultiset.begin();
    it++;                                              //    ^
    
    mymultiset.erase (it);                             // 10 30 40 40 50 60
    
    mymultiset.erase (40);                             // 10 30 50 60
    
    it=mymultiset.find (50);
    mymultiset.erase ( it, mymultiset.end() );         // 10 30
    
    std::cout << "mymultiset contains:";
    for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void test_find()
{
    std::multiset<int> mymultiset;
    std::multiset<int>::iterator it;
    
    // set some initial values:
    for (int i=1; i<=5; i++) mymultiset.insert(i*10);   // 10 20 30 40 50
    
    it=mymultiset.find(20);
    mymultiset.erase (it);
    mymultiset.erase (mymultiset.find(40));
    
    std::cout << "mymultiset contains:";
    for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
    // 10 30 50
}

void test_insert()
{
    std::multiset<int> mymultiset;
    std::multiset<int>::iterator it;
    
    // set some initial values:
    for (int i=1; i<=5; i++) mymultiset.insert(i*10);  // 10 20 30 40 50
    
    it=mymultiset.insert(25);
    
    it=mymultiset.insert (it,27);    // max efficiency inserting
    it=mymultiset.insert (it,29);    // max efficiency inserting
    it=mymultiset.insert (it,24);    // no max efficiency inserting (24<29)
    
    int myints[]= {5,10,15};
    mymultiset.insert (myints,myints+3);
    
    std::cout << "mymultiset contains:";
    for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
}

int main ()
{
  test_begin_end();
  test_count();
  test_equal_range();
  test_erase();
  test_find();
  test_insert();

  return 0;
}