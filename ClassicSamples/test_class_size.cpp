#include <iostream>
using namespace std;


class E1 {};                      // sizeof(E1) == 1
class E2 {static int a;};         // sizeof(E2) == 1
class E3 {int a;};                // sizeof(E3) = 4
class E4 {virtual void fn() {}};  // sizeof(E4) == 8  // 64-bit machine

// sizeof(A) == 16  // This is because of alignment. 
class A
{
    int a;
    static int aa;
    virtual fn1()=0;
};

// sizeof(B) == 16
class B
{
    int x;
    virtual fn2()=0;
};

// sizeof(C) == 32
class C :public A, public B
{
    virtual fn1(){}
    virtual fn2(){}
    virtual fn3(){}
};

// sizeof(R) == 8
class R {
public:
    virtual void fn(){}
};

// sizeof(VA) == 8
class VA: virtual public R{
public:
    virtual void fn_a() {}
};

// sizeof(VB) == 8
class VB: virtual public R{
public:
    virtual void fn(){}
    virtual void fn_b() {}
}; 

// sizeof(VC) == 16
class VC: public VA, public VB {};

int main(int argc, char ** argv)
{
    cout << "sizeof(E1) = " << sizeof(E1) << endl;  // 1
    cout << "sizeof(E2) = " << sizeof(E2) << endl;  // 1
    cout << "sizeof(E3) = " << sizeof(E3) << endl;  // 4
    cout << "sizeof(E4) = " << sizeof(E4) << endl;  // 8
    cout << "sizeof(A) = "  << sizeof(A) << endl;   // 16
    cout << "sizeof(B) = "  << sizeof(B) << endl;   // 16
    cout << "sizeof(C) = "  << sizeof(C) << endl;   // 32
    
    C * cp = new C;
    A * ap = (A*)cp;
    B * bp = (B*)cp;
    cout << "ap=" << ap << ", bp=" << bp << ", cp=" << cp << endl; //ap和cp一样，比bp小16 bytes
    // ap=0x600048560, bp=0x600048570, cp=0x600048560
    
    cout << "sizeof(R) = "   << sizeof(R) << endl;    // 8
    cout << "sizeof(VA) = "  << sizeof(VA) << endl;   // 8
    cout << "sizeof(VB) = "  << sizeof(VB) << endl;   // 8
    cout << "sizeof(VC) = "  << sizeof(VC) << endl;   // 16
    
    VC * vcp = new VC;
    VA * vap = (VA*)cp;
    VB * vbp = (VB*)cp;
    cout << "vap=" << vap << ", vbp=" << vbp << ", vcp=" << vcp << endl; 
    //vap=0x600048560, vbp=0x600048560, vcp=0x600048590
    
    return 0;
}
