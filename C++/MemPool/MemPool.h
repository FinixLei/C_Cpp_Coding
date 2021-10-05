// Does not consider multi-thread case 

#ifndef MEMPOOL_H
#define MEMPOOL_H

#include <string>
#include <cstddef>
#include "MyClass.h"

namespace finix {
    class MyClass;
    
    // The max number of MyClass instances can be stored in this memory pool 
    extern const int SizeOfMemPoolForMyClass;
    
    // sizeof(MyClass) - cannot get by "sizeof(MyClass)" in this file directly
    extern const int SizeOfMyClass;
    
    class MemPoolForMyClass
    {
    private:
        class NodeForMyClass {  // Internal Class 
        private:
            NodeForMyClass * next;
            MyClass * pMyClass; 
            
        public:
            friend class MemPoolForMyClass;

            inline NodeForMyClass(NodeForMyClass *n=nullptr, MyClass * pm=nullptr) : next(n), pMyClass(pm) {
                if (pMyClass == nullptr) { pMyClass = (MyClass *) malloc(SizeOfMyClass); }
            }
            
            inline ~NodeForMyClass() { free(pMyClass); }
        };
    
    public:
        // Singleton Pattern. Return this memory pool. 
        static MemPoolForMyClass * getMemoryPool();
        
        // Return the pointer pointing to the memory of one MyClass instance
        static MyClass * getMemory();
        
        // Return the memory, which is pointed by the pointer p, to this memory pool
        static void returnMemory(MyClass * p);
        
        // Return how many MyClass instances can be alloacted with this memory pool
        static int getPoolAvailableSize(); 
        
    private:
        // Release all the memory of this memory pool
        static void release();
        
        // Init this memory pool by allocating all the memory 
        static void init();

        MemPoolForMyClass(); 
        MemPoolForMyClass(const MemPoolForMyClass &) = delete;
        MemPoolForMyClass & operator = (const MemPoolForMyClass &) = delete;
        ~MemPoolForMyClass();
        
    private:
        // Pointer to this memory pool
        static MemPoolForMyClass * _original;
        
        // Use one linked list for all the memory blocks of MyClass instances; 
        // _head is the head of this linked list. 
        static NodeForMyClass * _head ;
    };
}

#endif
