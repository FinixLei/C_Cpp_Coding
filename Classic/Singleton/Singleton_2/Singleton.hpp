#include <iostream>

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;  // C++11 保证线程安全
        return instance;
    }
    
    ~Singleton(){}

private:
    Singleton(){}
    Singleton(const Singleton& other) = delete;
    Singleton(Singleton&& other) = delete;
    Singleton& operator = (const Singleton& other) = delete;
    Singleton& operator = (Singleton&& other) = delete;
};
