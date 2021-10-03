// g++ -c MyClass.cpp 

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstddef>

#include "MemPool.h"
#include "MyClass.h"

namespace finix {
    
    void * MyClass::operator new (size_t size) {
        std::cout << "MyClass::operator new" << std::endl;
        
        MemPoolForMyClass * pool = MemPoolForMyClass::getMemoryPool();
        if (pool == nullptr) {
            std::cout << "Cannot get memory pool" << std::endl;
            throw "Cannot get memory pool";
        }
        
        void * p = pool->getMemory();
        
        if (p == nullptr) {
            std::cout << "No Memory got from the memory pool" << std::endl;
            throw "No Memory from pool";
        }
        else {
            std::cout << "MyClass::operator new() : got memory from memory pool" << std::endl;
        }
        
        return p;
    }
    
    void MyClass::operator delete(void * p) {
        MyClass * tmp = (MyClass *)p;
        
        MemPoolForMyClass * pool = MemPoolForMyClass::getMemoryPool();
        if (pool == nullptr) {
            std::cout << "Cannot get memory pool" << std::endl;
            throw "Cannot get memory pool";
        }
        
        std::cout << "MyClass::operator delete : return memory to memory pool" << std::endl;
        pool->returnMemory(tmp);
    }
    
    MyClass::MyClass(int data, std::string name) : _data(data), _name(name) { }
    
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

    void MyClass::set_data(int d) {
        _data = d;
    }
    
    int MyClass::get_data() {
        return _data;
    }
    
    void MyClass::set_name(std::string n) {
        _name = n;
    }
    
    std::string MyClass::get_name() {
        return _name;
    }
};
