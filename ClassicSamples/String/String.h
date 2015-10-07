#include <cstdio>
#include <iostream>
using namespace std;

class String
{
public:
    String(const char *str = NULL);  // 普通构造函数
    String(const String &other);     // 拷贝构造函数
    ~ String(void);                  // 析构函数
    String & operator =(const String & other);  // 赋值函数
    
    friend std::ostream & operator << (std::ostream & oo, const String & s); 
  
private:
    char * m_data;  // 用于保存字符串
};
