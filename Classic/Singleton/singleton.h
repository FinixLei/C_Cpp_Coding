#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
public:
    static Singleton * get_instance();
    
private:
    Singleton() {}
    ~Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton operator= (const Singleton &) = delete;
    
private:
    static Singleton * pointer; 
};

#endif