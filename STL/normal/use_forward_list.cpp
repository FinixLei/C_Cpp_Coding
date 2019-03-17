/* forward_list - 单向链表 （序列容器）
   
   before_begin()
   begin()
   end()
   
   push_front()
   pop_front()
      
   front()
   emplace_after()
   emplace_front()
   insert_after()
   
   clear()
   empty()
   max_size()
   resize()
   
   erase_after()
   remove()
   remove_if()
       
   swap()
   sort()
   reverse()
*/

#include <iostream>
#include <forward_list>


void test_remove()
{
  std::forward_list<int> mylist = {10, 20, 30, 40, 30, 20, 10};

  mylist.remove(20);  // 10 30 40 10  // all the "20" are removed 

  std::cout << "mylist contains:";
  for (int& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';
}

void test_erase_after()
{
  std::forward_list<int> mylist = {10, 20, 30, 40, 50};

                                            // 10 20 30 40 50
  auto it = mylist.begin();                 // ^

  it = mylist.erase_after(it);              // 10 30 40 50
                                            //    ^
  it = mylist.erase_after(it,mylist.end()); // 10 30
                                            //       ^

  std::cout << "mylist contains:";
  for (int& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';
}

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
class is_odd_class
{
public:
  bool operator() (const int& value) {return (value%2)==1; }
} is_odd_object;

void test_remove_if()
{
  std::forward_list<int> mylist = {7, 80, 7, 15, 85, 52, 6};

  mylist.remove_if (single_digit);      // 80 15 85 52
  mylist.remove_if (is_odd_object);     // 80 52

  std::cout << "mylist contains:";
  for (int& x: mylist) std::cout << ' ' << x;
  std::cout << '\n';
}


int main()
{
    test_remove();
    test_erase_after();
    test_remove_if();
    
    return 0;
}