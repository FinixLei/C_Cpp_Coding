#include <string>
#include <iostream>
using namespace std;


void test_const_int_star();
void test_const_cast();
void test_enum();
void test_typedef(); 
void test_string();

int main(int argc, char * argv[]) {
    // test_string();
    // test_typedef();
    // test_enum();
    test_const_cast();
    // test_const_int_star(); 
    
    return 0;
}

void test_string() {
    string str = "abc";
    string::size_type pos = str.find("bc"); 
    cout << "pos = " << pos << endl;  // pos = 1
    
    str.insert(pos, "_A_"); 
    cout << "str = " << str << endl;  // str = a_A_bc
    
    pos = str.rfind("_b");
    cout << "pos = " << pos << endl;  // pos = 3
    
    string tmp = str.substr(pos, 1); 
    cout << "tmp = " << tmp << endl;  // tmp = _
    
    str.erase(0, 3);  // erase from positon 0, size is 3
    cout << "str = " << str << endl;  // str = _bc
}

void test_typedef() {
    typedef char * cstring;
    
    const char * p1 = "Hello, typedef!";   // 指向常量的指针，const只作用于char
    cout << "p1 -> " << p1 << endl;  // p1 -> Hello, typedef!
    
    p1 = "Hello, World";  // Fine. Just the pointing address is changed. 
    cout << "p1 -> " << p1 << endl;  // p1 -> Hello, World!
    
    const cstring p2 = (const cstring)"ABCD";  // 本身是常量的指针，const作用于char *整体，即const指针
    // p2 = "Hello, World";  // Error, 向只读变量p2赋值
    cout << "p2 -> " << p2 <<endl;  // p2 -> ABCD
}

void test_enum() {
    enum Color{RED, GREEN, BLUE}; 
    
    Color myColor;
    myColor = BLUE;
    cout <<"myColor is " <<myColor <<endl;  // myColor is 2
    
    // myColor = 1;  // Error, cannot assign a int value to a enum variable
    
    myColor = (enum Color)0;  // OK, type cast
    myColor = (enum Color)(myColor + 1); // OK 
    // myColor += 1;  // Error
    cout <<"myColor is " <<myColor <<endl;  // myColor is 1
    
    if (myColor == RED) {
        cout << "It is RED!" <<endl;
    } else {
        cout << "It is not RED!" <<endl;  // hit
    }
}

void test_const_cast() {
    const int * p = new int (100);
    cout << "address of p pointing to is " << reinterpret_cast<long>(p) << endl;  // address of p pointing to is 25769870528
    
    int * p2 = const_cast<int *>(p);  // p and p 2 point to the same address
    cout << "address of p2 pointing to is " << reinterpret_cast<long>(p2) << endl;  // address of p2 pointing to is 25769870528
    
    *p2 = 200;
    cout << "*p = " << *p << ", *p2 = " << *p2 << endl;  // *p = 200, *p2 = 200  二者所指地址相同，自然值也相同
    
    int a = 300;
    p2 = &a; 
    cout << "p = " << p << ", p2 = " << p2 << endl;  // p = 0x6000104c0, p2 = 0x22cabc  二者所指已不同
    cout << "*p = " << *p << ", *p2 = " << *p2 << endl;  // *p = 200, *p2 = 300  故值也不同了
}

void test_const_int_star() {
    int a = 10;
    const int * p = &a;
    cout << *p <<endl;  // 10
    // *p = 20;  // Error, assign a value to the read-only position *p
    
    const int b = 20;
    const int * pb = &b;
    cout << *pb <<endl;  // 20
    
    pb = p;  // The content cannot be changed but the pointer can be changed
    cout <<*p <<" " <<*pb <<endl;  // 10 10
}