#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

#include <iostream>
#include <atomic>
using namespace std;

class shared_count 
{
public:
    shared_count() noexcept : _count(1) {}
    
    void add_count() noexcept { 
        _count.fetch_add(1, std::memory_order_relaxed);  // ++ count;
    }
    
    long reduce_count() noexcept {
        return _count.fetch_sub(1, std::memory_order_acq_rel) - 1;  // return -- count;
    }
    
    long get_count() const noexcept {
        return _count.load(std::memory_order_acquire);   // return _count; 
    }
    
private:
    std::atomic<long> _count; 
};

template <typename T>
class smart_ptr 
{
private:
    T* _ptr = nullptr; 
    shared_count * _shared_count = nullptr; 
    
public:
    template <typename U>
    friend class smart_ptr; 
    
    explicit smart_ptr (T * ptr = nullptr) : _ptr(ptr) {
        if (ptr) {
            _shared_count = new shared_count();
        }
    }
    
    ~smart_ptr() {
        if (_ptr && _shared_count && _shared_count->reduce_count() == 0) {
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
            cout << "_shared_count = " << _shared_count->get_count() << endl;
        }
    }
    
    template <typename U> 
    smart_ptr(smart_ptr<U>&& other) noexcept : _ptr(other._ptr), _shared_count(other._shared_count) {
        other._ptr = nullptr;
        other._shared_count = nullptr;
        cout << "move constructor\n";
    }
    
    template <typename U>
    smart_ptr (const smart_ptr<U>& other, T* ptr) noexcept {
        _ptr = ptr; 
        if (_ptr && other._shared_count) {
            other._shared_count->add_count();
            _shared_count = other._shared_count; 
        }
    }
    
    void swap(smart_ptr& rhs) noexcept {
        using std::swap;
        swap(_ptr, rhs._ptr);
        swap(_shared_count, rhs._shared_count);
    }
    
    smart_ptr& operator = (smart_ptr rhs) noexcept {  // 必须是值传递
        cout << "operator = \n";
        if (rhs._shared_count) {
            cout << "rhs's count = " << rhs._shared_count->get_count() << endl;
        }
        rhs.swap(*this);
        return *this;
    }
    
    long use_count() const noexcept {
        if (_ptr && _shared_count) {
            return _shared_count->get_count();
        }
        return 0;
    }
    
    T* get() const noexcept { return _ptr; }
    T& operator * () const noexcept { return *_ptr; }
    T* operator -> () const noexcept { return _ptr; }
    operator bool() const noexcept { return _ptr; }
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

#endif