#ifndef AUTO_PTR_H
#define AUTO_PTR_H

template<typename T>
class auto_ptr {
private:
    T *pointee; 

public: 
    explicit auto_ptr(T *p=0):pointee(p) {}
    ~auto_ptr() { delete pointee; }
    
    auto_ptr(auto_ptr& other) {
        T *tmp = other.pointee;
        other.pointee = 0;
        pointee = tmp; 
    }
    
    // operator= must return reference, as copy constructor is movable
    // also, this is more efficient than return value
    auto_ptr<T>& operator = (auto_ptr& other) {
        if (this == &other) return *this; 
        
        delete pointee; 
        T *tmp = other.pointee; 
        other.pointee = 0;
        pointee = tmp;
        return *this; 
    }
    
    // Must return reference, as "*pa = 10;" requires lvalue. 
    T& operator * () const { return *pointee; } 
    T* operator -> () const { return pointee; }
    T* get() const { return pointee; }
    
};

#endif
