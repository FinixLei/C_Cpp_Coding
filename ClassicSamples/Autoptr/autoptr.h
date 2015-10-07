#ifndef AUTOPTR_H
#define AUTOPTR_H

template<typename T>
class autoptr {
private:
    T* pointee;
    
    T* release() {
        T* temp = pointee;
        pointee = 0;
        return temp;
    }
    
public: 
    explicit autoptr(T* p=0):pointee(p) {}
    
    ~autoptr() {delete pointee;}
    
    autoptr(const autoptr<T> & other) {
        pointee = other.release();
    }
    
    T& operator = (const autoptr<T> & other) {
        if (this == &other) {
            return *this;
        }
        
        delete pointee;
        pointee = other.release();
    }
    
    T* operator -> () const {
        return pointee;
    }
    
    T* get() const {
        return pointee;
    }
    
    T& operator * () const {
        return *pointee;
    }
};

#endif
