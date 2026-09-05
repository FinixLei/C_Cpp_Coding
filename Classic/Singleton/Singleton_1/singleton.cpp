#include <thread>
#include <mutex>
#include "singleton.h"

static std::mutex mtx;

Singleton * Singleton::pointer = 0;

Singleton * Singleton::get_instance()
{
    if (Singleton::pointer == 0) {
        // mtx.lock(); // way-1
        
        std::lock_guard<std::mutex> lck(mtx); // way-2
        
        if (Singleton::pointer == 0) {
            Singleton::pointer = new Singleton();
        }
        
        // mtx.unlock();  // way-1
    }
    return Singleton::pointer;
}
