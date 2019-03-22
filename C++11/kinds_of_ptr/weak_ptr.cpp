#include <memory>
#include <iostream>
using namespace std;


int main()
{
    // expired()
    shared_ptr<int> sp(new int(10));
    weak_ptr<int> wp(sp);
    
    cout << "wp " << (wp.expired()?"is ":"is not ") << "expired.\n";  // is not 
    sp.reset();
    cout << "wp " << (wp.expired()?"is ":"is not ") << "expired.\n";  // is 

    // lock() return shared_ptr 
    shared_ptr<int> sp1, sp2;      // shareing group: 
    sp1 = make_shared<int>(20);    // sp1 
    weak_ptr<int> wp1(sp1);        // sp1, wp1 
    sp2 = wp1.lock();              // sp1, wp1, sp2 
    // cout << "value of wp1 is: " << *wp1 << endl;  // weak_ptr has no operator* function. 
    
    sp1.reset();                   //      wp1, sp2 
    sp1 = wp1.lock();              // sp1, wp1, sp2 
    cout << "sp1 = " << *sp1 << endl; 
    cout << "sp2 = " << *sp2 << endl; 
    
    // weak_ptr to weak_ptr 
    weak_ptr<int> w1;
    weak_ptr<int> w2(w1);
    cout << "w1: " << w1.use_count() << endl;  // 0
    cout << "w2: " << w2.use_count() << endl;  // 0
    shared_ptr<int> s1(new int(10));
    w1 = s1;
    cout << "w1: " << w1.use_count() << endl;  // 1
    cout << "w2: " << w2.use_count() << endl;  // 0
    
    // owner_before()
    int *p = new int(20);
    shared_ptr<int> a(new int(10));
    shared_ptr<int> b(a, p);  // alias constructor, actually store p 
    cout << "a = " << *a << endl;
    cout << "b = " << *b << endl; 
    std::weak_ptr<int> c (b);
    std::cout << "comparing a and c...\n" << std::boolalpha;
    std::cout << "value-based: " << ( !(a<c.lock()) && !(c.lock()<a) ) << '\n';
    std::cout << "owner-based: " << ( !a.owner_before(c) && !c.owner_before(a) ) << '\n';

  delete p;
    
    
    
    
    return 0;
}