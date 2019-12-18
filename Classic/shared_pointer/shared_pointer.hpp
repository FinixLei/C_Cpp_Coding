#include <iostream>

class shared_count 
{
public:
    shared_count() noexcept : _count(1) {}
    
    void add_count() noexcept { 
        ++ _count;
    }
    
    long reduce_count() noexcept {
        return -- _count;
    }
    
    long get_count() const noexcept {
        return _count; 
    }
    
private:
    long _count; 
};

template <typename T>
class smart_ptr 
{
public:
    template <typename U>
    friend class smart_ptr; 
    
    explicit smart_ptr (T * ptr = nullptr) : _ptr(ptr) {
        if (ptr) {
            _shared_count = new shared_count();
        }
    }
    
    ~smart_ptr() {
        if (_ptr && _shared_count->reduce_count() == 0) {
            delete _ptr; 
            delete _shared_count;
        }
    }
    
    smart_ptr (const smart_ptr& other) {
        _ptr = other._ptr; 
        if (_ptr) {
            other._shared_count->add_count();
            _shared_count = other._shared_count; 
        }
    }
    
    template <typename U> 
    smart_ptr (const smart_ptr<U> & other) noexcept {
        _ptr = other._ptr;
        if (_ptr) {
            other._shared_count->add_count();
            _shared_count = other._shared_count;
        }
    }
    
    template <typename U> 
    smart_ptr(smart_ptr<U>&& other) noexcept {
        _ptr = other._ptr; 
        if (_ptr) {
            _shared_count = other._shared_count; 
            other._ptr = nullptr;
        }
    }
    
    template <typename U>
    smart_ptr (const smart_ptr<U>& other, T* ptr) noexcept {
        _ptr = ptr; 
        if (_ptr) {
            other._shared_count->add_count();
            _shared_count = other._shared_count; 
        }
    }
    
    void swap(smart_ptr& rhs) noexcept {
        using std::swap;
        swap(_ptr, rhs._ptr);
        swap(_shared_count, rhs._shared_count);
    }
    
    smart_ptr& operator = (smart_ptr rhs) noexcept {
        rhs.swap(*this);
        return *this;
    }
    
    long use_count() const noexcept {
        if (_ptr) {
            return _shared_count->get_count();
        }
        else {
            return 0;
        }
    }
    
    T* get() const noexcept { return _ptr; }
    T& operator * () const noexcept { return *_ptr; }
    T* operator -> () const noexcept { return _ptr; }
    operator bool() const noexcept { return _ptr; }
    
private:
    T* _ptr; 
    shared_count * _shared_count; 
};

template <typename T> 
void swap(smart_ptr<T>& lhs, smart_ptr<T>& rhs) noexcept {
    lhs.swap(rhs);
}

template <typename T, typename U> 
smart_ptr<T> static_pointer_cast (const smart_ptr<U>& other) noexcept {
    T* ptr = static_cast<T*> (other.get());
    return smart_ptr<T>(other, ptr);
}

template <typename T, typename U>
smart_ptr<T> const_pointer_cast(const smart_ptr<U>& other) noexcept {
    T* ptr = const_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}

template <typename T, typename U>
smart_ptr<T> dynamic_pointer_cast(const smart_ptr<U>& other) noexcept {
    T* ptr = dynamic_cast<T*>(other.get());
    return smart_ptr<T>(other, ptr);
}
