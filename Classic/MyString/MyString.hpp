#include <cstring>
#include <iostream>

class MyString {
private:
    char * str_ = nullptr;
    
public:
    MyString(const char * src = nullptr) {
        if (src == nullptr) {  // avoid strlen(nullptr)
            str_ = new char [1] {'\0'};
            return;
        }
        
        size_t len = strlen(src);
        str_ = new char [len+1];
        for (size_t i=0; i<=len; i++) {
            str_[i] = src[i];
        }
    }
    
    ~MyString() {
        delete [] str_;
    }
    
    MyString(const MyString& other) {
        if (other.str_ == nullptr) {
            str_ = new char [1] {'\0'};
            return;
        }
        
        size_t len = strlen(other.str_);
        char * tmp = new char [len+1];
        for (size_t i=0; i<=len; i++) {
            tmp[i] = other.str_[i];
        }
        str_ = tmp;
    }
    
    MyString& operator = (const MyString& other) {
        if (this == &other) return *this;
        
        if (other.str_ == nullptr) {
            char * tmp = new char[1] {'\0'};
            delete [] str_;
            str_ = tmp;
            return *this;
        }
        
        size_t len = strlen(other.str_);
        char * tmp = new char [len+1];
        for (size_t i=0; i<=len; i++) {
            tmp[i] = other.str_[i];
        }
        delete [] str_;
        str_ = tmp;
        
        return *this;
    }
    
    MyString(MyString&& other) noexcept : str_(other.str_) {
        other.str_ = nullptr;
    }
    
    MyString& operator = (MyString&& other) noexcept {
        if (this == &other) return *this;
        
        delete [] str_;
        str_ = other.str_; 
        other.str_ = nullptr;
        return *this;
    }
    
    const char * c_str() const {
        return str_ ? str_ : "";
    }
    
    bool empty() const {
        return str_ == nullptr || str_[0] == '\0';
    }
    
    
    size_t length() const {
        if (str_ == nullptr) return 0;
        return strlen(str_);
    }
    
    friend std::ostream& operator << (std::ostream& oo, const MyString& ms);
    
    friend MyString operator + (const MyString& a, const MyString& b);
};

inline std::ostream& operator << (std::ostream& oo, const MyString& ms) {
    if (ms.str_ != nullptr) oo << ms.str_;
    return oo;
}

inline MyString operator + (const MyString& a, const MyString& b) {
    size_t a_len = a.length();
    size_t b_len = b.length();
    size_t len = a_len + b_len;
    
    MyString result;
    char * tmp = new char [len+1];
    for (size_t i=0; i<a_len; i++) {
        tmp[i] = a.str_[i];
    }
    for (size_t i=a_len; i<len; i++) {
        tmp[i] = b.str_[i-a_len];
    }
    tmp[len] = '\0';
    
    delete result.str_;
    result.str_ = tmp;
    return result;
}
