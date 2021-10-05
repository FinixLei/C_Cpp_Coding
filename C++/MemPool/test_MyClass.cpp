// g++ -c MyClass.cpp test_MyClass.cpp MemPool.cpp
// g++ -o a.out *.o

#include "MyClass.h"
#include <iostream>
#include <string>

extern const int finix::SizeOfMemPoolForMyClass;

int main()
{
    finix::MyClass * p1 = new finix::MyClass(20, "Tom");
    finix::MyClass * p2 = new finix::MyClass(30, "Finix");
    std::cout << "Processing...\n";
    std::cout << "p1->_data = " << p1->get_data() << std::endl;
    std::cout << "p1->_name = " << p1->get_name() << std::endl;
    std::cout << "p2->_data = " << p2->get_data() << std::endl;
    std::cout << "p2->_name = " << p2->get_name() << std::endl;
    delete p1;
    delete p2;
    std::cout << "Done...\n";
  
    finix::MyClass *pArray[finix::SizeOfMemPoolForMyClass+1];
    for (int i=0; i<finix::SizeOfMemPoolForMyClass+1; i++) {
        try {
            pArray[i] = new finix::MyClass(i, "");
        }
        catch(char const * msg) {
            std::cerr << msg << std::endl;
            pArray[i] = nullptr;
        }
        catch(std::bad_alloc& e) {
            std::cerr << "Cannot get memory from pool" << std::endl;
            pArray[i] = nullptr;
        }
    }
    for (int i=0; i<finix::SizeOfMemPoolForMyClass+1; i++) {
        if (pArray[i]) {
            delete pArray[i];
            pArray[i] = nullptr;
        }
    }
  
    return 0;
}
