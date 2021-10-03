// Does not consider multi-thread case 

#ifndef MEMPOOL_H
#define MEMPOOL_H

#include <string>
#include <cstddef>
#include "MyClass.h"

namespace finix {
    class MyClass;
    
    extern const int SizeOfMemPoolForMyClass;
    
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

            NodeForMyClass(NodeForMyClass *n=nullptr, MyClass * pm=nullptr) : next(n), pMyClass(pm) {
                if (pMyClass == nullptr) {
                    pMyClass = (MyClass *) malloc(SizeOfMyClass);
                }
            }
            
            inline ~NodeForMyClass() {
                free(pMyClass);
            }
            
            inline MyClass * getPointerToMyClass() {
                return pMyClass;
            }
        };
    
    public:
        static MemPoolForMyClass * getMemoryPool();
        
        static MyClass * getMemory();
        
        static void returnMemory(MyClass * p);
        
        static int getPoolAvailableSize(); 
        
    private:
        static void release();
        static void init();

        MemPoolForMyClass(); 
        MemPoolForMyClass(const MemPoolForMyClass &) = delete;
        MemPoolForMyClass & operator = (const MemPoolForMyClass &) = delete;
        
        ~MemPoolForMyClass();
        
    private:
        static MemPoolForMyClass * _original;
        static NodeForMyClass * _head ;
    };
}

#endif
