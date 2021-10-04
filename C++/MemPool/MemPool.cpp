// g++ -c MemPool.cpp

#include "MemPool.h"
#include <string>
#include <cstddef>
#include <iostream>

// Mandotory for satisfying link requirement. 
finix::MemPoolForMyClass * finix::MemPoolForMyClass::_original = nullptr;
finix::MemPoolForMyClass::NodeForMyClass * finix::MemPoolForMyClass::_head = nullptr;

namespace finix {
    const int SizeOfMemPoolForMyClass = 10;
    
    MemPoolForMyClass * MemPoolForMyClass::getMemoryPool() {
        if (_original == nullptr) {
            _original = new MemPoolForMyClass;
            _original -> init();
        }
        return _original; 
    }
        
    MyClass * MemPoolForMyClass::getMemory() {
        if (_head == nullptr) {
            std::cout << "No Memory in Pool" << std::endl;
            return nullptr;
        }
        
        NodeForMyClass * tmp = _head; 
        _head = _head->next; 
        
        MyClass * p = tmp->pMyClass;
        
        tmp->pMyClass = nullptr; 
        delete tmp; 
        
        std::cout << "Provide Memory of one MyClass instance. Now Pool size is " << getPoolAvailableSize() << std::endl;
        return p;
    }
    
    void MemPoolForMyClass::returnMemory(MyClass * p) {
        if (p == nullptr) {
            std::cout << "Error Input for getBackMyClassMemory" << std::endl;
            return;
        }
        
        int count = getPoolAvailableSize();
        if (count >= SizeOfMemPoolForMyClass) {
            std::cout << "Pool is full. No return back, just release." << std::endl;
            delete p;
            return;
        }
        
        NodeForMyClass * pNode = new NodeForMyClass(_head, p);
        pNode -> next = _head;
        _head = pNode; 
        std::cout << "Memory Pool got the returned memory. Now count is " << count + 1 << std::endl;
    }
    
    int MemPoolForMyClass::getPoolAvailableSize() {
        int count = 0;
        NodeForMyClass * tmp = _head;
        while (tmp)  {
            count ++;
            tmp = tmp->next;
        }
        return count;
    }
    
    void MemPoolForMyClass::release() {
        while (_head != nullptr) {
            NodeForMyClass * tmp = _head;
            _head = _head -> next;

            free(tmp->pMyClass);
            tmp->pMyClass = nullptr;
            delete tmp;
        }
    }
    
    void MemPoolForMyClass::init() {
        release();
        _head = nullptr;
        
        MyClass * pTmpHead = (MyClass *)calloc(SizeOfMemPoolForMyClass, sizeof(MyClass));
        if (pTmpHead == nullptr) {
            std::cout << "No Memory can be got from System" << std::endl;
            throw "No Memory can be got from System";
        }
        
        int count = 0;
        while (count < SizeOfMemPoolForMyClass) {
            NodeForMyClass * tmp = new NodeForMyClass(nullptr, pTmpHead);
            if (_head) { 
                tmp->next = _head;
                _head = tmp;
            }
            else { 
                _head = tmp;
            }
            count += 1;
            pTmpHead = pTmpHead + sizeof(MyClass);
        }
        
        count = getPoolAvailableSize();
        std::cout << "Init Memory Pool Done. Pool size is " << count << std::endl;
    }

    MemPoolForMyClass::MemPoolForMyClass() {}
    
    MemPoolForMyClass::~MemPoolForMyClass() {
        release();
    }
}
