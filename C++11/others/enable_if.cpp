#include <type_traits>
#include <iostream>
using namespace std;

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
  is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template < class T,
           class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}

int main() {

  short i = 1;    // code does not compile if type of i is not integral; short is also integral

  // When the boolalpha format flag is set, bool values are inserted/extracted by 
  // their textual representation: either true or false, instead of integral values.
  std::cout << std::boolalpha; 
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;

  return 0;
}
