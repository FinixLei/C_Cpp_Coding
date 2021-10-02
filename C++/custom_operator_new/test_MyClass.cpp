// g++ test_MyClass.cpp MyClass.o 
// or 
// g++ test_MyClass.cpp MyClass.cpp 

#include "MyClass.h"
#include <iostream>
#include <string>


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
  
    return 0;
}
