#include <cstring>
#include "String.h" 

String::String(const char * str) {
    m_data = new char[strlen(str) + 1];
    strcpy(m_data, str); 
}

String::String(const String & other) {
    m_data = new char[strlen(other.m_data) + 1];
    strcpy(m_data, other.m_data); 
}

String::~String() {
    delete [] m_data;
}

String& String::operator = (const String & other) {
    if (this == &other) {
        return *this;
    }
    
    delete [] m_data; 
    
    m_data = new char[strlen(other.m_data) + 1];
    strcpy(m_data, other.m_data);
    
    return *this;
}

std::ostream & operator << (std::ostream & oo, const String & s) {
    oo << s.m_data;
    return oo;
}
