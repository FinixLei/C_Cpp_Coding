#ifndef MYCLASS_H
#define MYCLASS_H

#include <cstddef>
#include <string>

namespace finix {

    class MyClass
    {
    public:
        static void * operator new (size_t size);
        static void operator delete(void * p);
    
        MyClass(int data = 0, std::string name="");
        MyClass(const MyClass& other);
        MyClass& operator = (const MyClass & other);
        ~MyClass();

        int get_data();
        std::string get_name();
        
    private:
        int _data;
        std::string _name; 
    };

}

#endif
