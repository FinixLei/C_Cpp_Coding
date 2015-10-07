# include <iostream>
using namespace std;

class A
{
public:
  static int count;
  A(){count++; }
  A(const A &){cout<<"Copy Constructor" <<endl;}

  static void print()
  {
   cout << "n=" << count << endl;
  }
   ~A(){count--; print();}
};

int A::count = 0;

A f(A x)
{
  x.print();
  return x;
}

int main(int argc, char * argv[])
{
  A h;
  A::print();
  f(h);
  A::print();
  return 0;
}

/* 
    执行结果是：
    1                 // 第一次A::print()
    Copy Constructor  // 调用f（h）时，将h拷贝构造给f函数的参数
    1                 // x.print()
    Copy Constructor  // f函数返回时，将x拷贝构造给一个临时对象
    0                 // x的析构函数
    -1                // 临时对象的析构函数
    -1                // 第二次A::print()
    -2                // h的析构函数
*/