// g++ -c MyClass.cpp 

#include "MyClass.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstddef>

namespace finix {
    static void * MyClass::operator new (size_t size) {
        std::cout << "MyClass::operator new" << std::endl;
        void * p = malloc(sizeof(MyClass));
        if (p == nullptr) {
            std::cout << "No Memory" << std::endl;
            throw "No Memory";
        }
        return p;
    }
    
    static void MyClass::operator delete(void * p) {
        std::cout << "MyClass::operator delete" << std::endl;
        MyClass * tmp = (MyClass *)p;
        free(tmp);
    }
    
    MyClass::MyClass(int data, std::string name) : _data(data), _name(name) {}
    
    MyClass::MyClass(const MyClass & other) {
        _data = other._data;
        _name = other._name;
    }
    
    MyClass& MyClass::operator = (const MyClass & other) {
        if (this == &other) return *this;
        _data = other._data;
        _name = other._name;
        return *this;
    }
    
    MyClass::~MyClass() {}

    int MyClass::get_data() {
        return _data;
    }
    
    std::string MyClass::get_name() {
        return _name;
    }
};
