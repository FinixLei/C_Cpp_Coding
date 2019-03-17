/* 
    queue - 单向队列（先进先出）
    
    back()   // returns a reference to the last element
    front()
    
    emplace()
    push()
    pop()    // remove the first element, returns nothing
    
    empty()
    size()
    
    swap()
*/


#include <iostream>       // std::cout
#include <queue>          // std::queue

int main ()
{
  std::queue<int> myqueue;

  myqueue.push(12);
  myqueue.push(75);   // this is now the back

  myqueue.back() -= myqueue.front();  // 63
  std::cout << "myqueue.back() is now " << myqueue.back() << '\n';

  return 0;
}