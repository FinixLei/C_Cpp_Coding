/* deque - 双向队列

   front()
   back()
   at(size_type n)    // Returns a reference to the element at position n in the deque
   
   push_back()
   pop_back()
   push_front()
   pop_front()
   
   empty()
   size()
   max_size() - Returns the maximum number of elements that the deque container can hold
   
   emplace()       - insert a new element at position 
   emplace_back()  - insert a new element at the end of the deque
   emplace_front() - insert a new element at the beginning of the deque
   swap()
*/

#include <iostream>
#include <deque>
#include <vector>

void test_insert()
{
    std::deque<int> mydeque;

    // set some initial values:
    for (int i=1; i<6; i++) mydeque.push_back(i); // 1 2 3 4 5
    
    std::deque<int>::iterator it = mydeque.begin();
    ++it;
    
    it = mydeque.insert (it,10);                  // 1 10 2 3 4 5
    // "it" now points to the newly inserted 10
    
    mydeque.insert (it,2,20);                     // 1 20 20 10 2 3 4 5
    // "it" no longer valid!
    
    it = mydeque.begin()+2;
    
    std::vector<int> myvector (2,30);  // 30, 30
    mydeque.insert (it,myvector.begin(),myvector.end());
                                                    // 1 20 30 30 20 10 2 3 4 5
    
    std::cout << "mydeque contains:";
    for (it=mydeque.begin(); it!=mydeque.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

int main ()
{
  std::deque<int> mydeque;

  mydeque.push_front(77);
  mydeque.push_back(20);

  mydeque.front() -= mydeque.back();

  std::cout << "mydeque.front() is now " << mydeque.front() << '\n';  // 57
  
  test_insert();

  return 0;
}