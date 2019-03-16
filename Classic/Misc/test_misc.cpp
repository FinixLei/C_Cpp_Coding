#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;


/*
class AA
{
public:
    AA(int i = 10):aa(i), bb(i+1){}
    virtual void run(){printf("AA::run()\n");}
protected:
    int bb;
private:
    int aa;
};

class BB: private AA
{
public:
    void run()
    {
        printf("BB::run()\n");
        cout<< AA::bb <<endl;
        // cout<< AA::aa <<endl;  Cannot access aa;
    }
};


BB b;
int main()
{
  AA * pA = (AA*)(&b);
  pA->run();
  return 0;
}
*/

/*
class Base
{
public:
    void print(){cout<<"Base print"<<endl;}
    virtual void printv(){cout<<"Base print virtual"<<endl;}
};

class Derived : public Base
{
public:
    void print(){cout<<"Derived print"<<endl;}
    virtual void printv(){cout<<"Derived printv"<<endl;}
};

void fn(Base * b, int i){cout<<"Base int"<<endl;}
void fn(Derived * b, int i){cout<<"Drived int"<<endl;}
void fn(Base * b, unsigned int i){cout<<"Base unsigned int"<<endl;}
void fn(Derived * b, unsigned int i){cout<<"Drived unsigned int "<<endl;}

int main()
{
    Derived * dp = new Derived();
    Base * bp = (Base *)dp;
    fn(dp, 10);  // Derived int 
    fn(bp, 10);  // Base int 
    bp->print(); // Base print
    bp->printv();  // Derived printv
    
    return 0;
}
*/

/*
class AA
{
    int a;
    static int aa;
    virtual void fn1()=0;
};

class BB
{
    int x;
    virtual void fn2()=0;
};

class CC :public AA, public BB
{
    virtual void fn1(){}
    virtual void fn2(){}
    virtual void fn3(){}
};

int main()
{
    cout << sizeof(int) << endl; // 4
    cout << sizeof(AA) << endl; //4+4=8 , sizeof(BB)也是8, static变量不影响类的大小 (现在是16？)
    cout << sizeof(BB) << endl; 
    cout << sizeof(CC) << endl; //所以C的size是16  （现在是32？）
    CC * cp = new CC;
    AA * ap = (AA*)cp;
    BB * bp = (BB*)cp;
    printf("%p, %p, %p", ap, bp, cp); //ap和cp一样，比bp小2
    
    return 0;
}
*/

/*
#include <cassert>
#include <cstring>

char * strcpy2(char * dest, const char * src)
{
     assert((dest != NULL) && (src != NULL));
     int i = 0;
     while((dest[i] = src[i++]) != '\0')
         NULL;
     return dest;
}

int main()
{
    char charray[10];
    memset(charray, 0x00, 10);
    char * src = "aaabbb";
    strcpy2(charray, src);
    cout<<charray <<endl;
    cout<<"length of charray is: " <<strlen(strcpy2(charray, src)) <<endl;  // 6
    return 0;
}
*/

/*
#include <ctime>

int main()
{
    int a = 0;
    int max = 0;
    srand(time(NULL));
    clock_t t_begin, t_end;
    t_begin = clock();
    while(a < 100000000)
    {
        int tmp = rand();
        max = (tmp > max) ? tmp : max;
    //  cout <<tmp <<"\t";
        a++;
    }
    t_end = clock();
    
    cout<<"Takes " <<(t_end - t_begin)/CLOCKS_PER_SEC << " seconds" <<endl;
    cout<<max <<endl;
    
    return 0;
}
*/

/*
#include <string>
int main()
{
    string str = "China";
    const char * strch = str.c_str();
    cout << strch <<endl;
    cout <<strlen(strch) <<endl; // 5
    
    string str1 = "aaa.bbb.ccc.ddd";
    string::size_type pos = str1.rfind("."); // reverse find
    if(pos != string::npos)
    {
        str1.insert(pos, "HH"); // insert(pos, insertedstring)
        cout<<str1 <<endl; // aaa.bbb.cccHH.ddd
        cout<<"pos = " <<pos <<endl; // 11, after insert, pos is the 1st H
    }
  
    string substr = str1.substr(0, pos); // substr(begin, size)
    cout<<substr <<endl; // aaa.bbb.ccc
    
    pos = substr.find("b"); //find("dest string")
    cout << "pos = " << pos << endl;
    
    substr.erase(3, 4); // erase(begin, size)
    cout<<substr << endl; // aaa.ccc
    
    cin.get();
    return 1;
}
*/

/*
int main()
{
    const int a = 1;
    int & b = const_cast<int &>(a);
    b = 10;
    cout<<"b=" <<b<<endl;  // 10
    cout<<"a=" <<a <<endl; // 1
    
    int c = 2;
    int & d = c;
    d = -20;
    cout << "c=" <<c <<endl;  // -20
    cout << "d=" <<d <<endl;  // -20
    
    const int * i = new int (100);
    int * p = const_cast<int *>(i);
    *p = 99;
    cout << "i points to " << *i <<endl;  // 99
    cout << "p points to " << *p <<endl;  // 99
    
    return 0;
}
*/

/* 
// Empty class will take 1 byte, AAA will take 8 bytes 
class AAA 
{
public: 
    void print() {}  // does not take any space 
    virtual printv() {}  // take 8 bytes for virtual function 
};

class A
{
public:
    ~A(){}
    void print(){cout<<"This is A. " <<endl;}
    virtual void print_name(){cout<<"Name is A. " <<endl;}
    
protected:
    A(){}

private:
    static int a[100];  // does not take any space for static member variables
};

class B:public A
{
public:
    B(int i=0):data(i){}
    B(const B& b){data = b.data;}
    
    ~B(){}
    void print_name(){cout<< "Name is B. " <<endl;}
    virtual void print_data()const {cout<<data << endl;}
    
    B operator ++ () {data ++; return *this;}  // pre ++
    B operator ++ (int d) {B tmp(*this); data ++; return tmp;}  // post ++
    
    friend B operator + (const B& b1, const B& b2) {
        B result(b1.data + b2.data);
        return result;
    }
    friend ostream & operator << (ostream & oo, const B& b) {  // must be const引用类型，因为其实万能传递型
        oo<<b.data <<" ";
        return oo;
    }
    
private:
    int data;
};

int main()
{
    cout << "sizeof(AAA): " << sizeof(AAA) << endl;  // 8
    cout << "sizeof(A): " << sizeof(A) <<endl;       // 8
    cout << "sizeof(B): " << sizeof(B) <<endl;       // 16
    
    B b1(10);
    B b2(20);
    B b3 = b1 + b2;
    b3.print_data();  // 30
    b3++;
    cout << b3 << endl; // 31
    ++b3;
    cout << b3 << endl;    // 32
    cout << b3++ << endl;  // 32
    cout << ++b3 << endl;  // 34
    
    return 0;
}
*/

/*
#include <cstring>

int main()
{
    char * str = "123456789";
    char charray[] = "123456789";
    
    cout<<"sizeof(char *str): " <<sizeof(str) <<endl; // 8
    cout<<"strlen(char *str): " <<strlen(str) <<endl; // 9
    cout<<"sizeof(char array []): " <<sizeof(charray) <<endl; // 10
    cout<<"strlen(char array []): " <<strlen(charray) <<endl; // 9
    
    return 0;
}
*/

/*
#include <vector>

// the below program show how to change capacity to size
int main()
{
    vector<int> vi;
    vi.push_back(99); 
    vi.push_back(98);
    vi.push_back(97);
    cout<<"vi size: " <<vi.size()<<endl;
    cout<<"vi capacity: " <<vi.capacity() <<endl;
    
    vector<int> (vi).swap(vi); // change capacity to size
    
    cout<<"vi size: " <<vi.size()<<endl;
    cout<<"vi capacity: " <<vi.capacity() <<endl;
    
    return 0;
}
*/

/*
class Base
{
public:
     void vmf() {cout<<"In Base" <<endl;}
     void vmf(int data) {cout<<"In Base:" <<data <<endl; }
};

class Derived:public Base
{
public:
    using Base::vmf;  // Now vmf() and vmf(int) of B have been used in Derived. 
    void vmf(); // overwrite vmf(). 
};

void Derived::vmf()
{
    cout<<"In Derived" <<endl;
    Base::vmf();
}

int main()
{
    Derived d;
    d.vmf();
    d.vmf(10);
    
    return 0;
}
*/

namespace std {
    template<> 
    void swap<int>(int& a, int& b) {
        a = a ^ b; 
        b = b ^ a; 
        a = a ^ b;
        a++;
        b++;
    }
}

int main()
{
    const int& a =100;
    int& b = const_cast<int&>(a);
    b=150;
    cout<<"a = " <<a <<", b = " <<b <<endl;
    
    int c = 10;
    int d = 20;
    swap<int>(c, d);
    cout<<"c = " <<c <<", d = " <<d <<endl;
    
    return 0;
}
