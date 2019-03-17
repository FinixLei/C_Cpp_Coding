/* list - 双向链表(序列容器)
   
   back()
   front()
   
   push_back()
   push_front()
   pop_back()
   pop_front()
   insert()
   
   remove(value) 参数是值，且是remove所有
   remove_if()
   erase(it) 或 erase(it, it+n) 参数是iterator
   
   emplace()
   emplace_back()
   emplace_front()

   clear()
   empty()
   size()
   max_size()
   resize()
   
   swap()
   sort()
*/

#include <iostream>
#include <list>

void test_remove()
{
  int myints[]= {17,89,7,14};
  std::list<int> mylist (myints,myints+4);

  mylist.remove(89);    // 17 7 14

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
    bool operator() (const int& value) { return (value%2)==1; }
};

void test_remove_if()
{
  int myints[]= {15,36,7,17,20,39,4,1};
  std::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

  mylist.remove_if (single_digit);           // 15 36 17 20 39

  mylist.remove_if (is_odd());               // 36 20

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void test_erase()
{
  std::list<int> mylist;
  std::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);

                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^
  advance (it2,6);            // ^                 ^
  ++it1;                      //    ^              ^

  it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist.erase (it1,it2);     // 10 30 60 80 90
                              //        ^

  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';
}

int main()
{
    test_remove();
    test_remove_if();
    test_erase();
    
    return 0;
}