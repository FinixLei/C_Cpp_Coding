/*
    所谓placement new就是在用户指定的内存位置上构建新的对象，这个构建过程不需要额外分配内存，只需要调用对象的构造函数即可。
    placement new是怎么做的呢?
    说白了就是把原本new做的两步工作分开来。第一步分配内存，第二步调用类的构造函数在自己分配的内存上构建新的对象。
     
    placement new的好处：
    1）在已分配好的内存上进行对象的构建，构建速度快。
    2）已分配好的内存可以反复利用，有效的避免内存碎片问题。
*/

#include <cstring>
#include <iostream>
using namespace std;

class  Foo // sizeof(Foo) == 8
{
    char  cc;
    float  f;
 
public :
    void print() { 
        cout << " ADDR: " << this << endl; 
    }
    void set_f(float _f) { 
        cout << " set f val : " << _f << endl; 
        f = _f; 
    }
    void  get_f() {
        cout <<" get f val : "<< f << endl; 
    }
}; 

 
int main() {
    
    const int N = 1;

    // 1. 分配内存 
    char *  buff  =   new   char [sizeof (Foo)  *  N ];
    memset( buff, 0 , sizeof (Foo) * N ); 

    // 2. 构建对象 
    Foo *  p1  =   new (buff)Foo; 
    Foo *  p2  =   new (buff + sizeof(Foo))Foo; 

    // 3. 使用对象 
    p1 -> print(); 
    p1 -> set_f( 5.5f );
    p1 -> get_f(); 
    
    p2->print();
    p2->set_f(10.2f);
    p2->get_f();

    // 4. 析构对象，显式的调用类的析构函数。 
    p1->~Foo(); 
    p2->~Foo();

    // 5. 销毁内存 
    delete [] buff; 

    /* 
        上面5个步骤是标准的placement new的使用方法。 
        对于buff这块内存可以反复使用，只要重复2、3、4步骤即可。
    */
}
