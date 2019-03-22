#include <memory>
#include <iostream>
using namespace std;


struct C {int* data;};

int main()
{
    // Case-1
    int *p = new int(10);
    shared_ptr<int> a(p);
    cout << "a = " << *a << endl;
    
    shared_ptr<int> b(a);
    shared_ptr<int> c = b; 
    shared_ptr<int> d;
    d =c;
    
    cout << "b = " << *b << endl;
    cout << "c = " << *c << endl;
    cout << "d = " << *d << endl;
    
    *p = 20;
    cout << "a = " << *a << endl;
    cout << "b = " << *b << endl;
    cout << "c = " << *c << endl;
    cout << "d = " << *d << endl;
    
    cout << "a.use_count = " << a.use_count() << endl;
    a = d;   // 循环引用，检查不出
    cout << "a.use_count = " << a.use_count() << endl;
    
    // make_shared 
    shared_ptr<int> bar = make_shared<int>(20);  // move, the same as "shared_ptr<int> bar(new int(20));"
    cout << "bar = " << *bar << endl; 
    
    // use_count & reset 
    shared_ptr<int> sp1(unique_ptr<int>(new int(10)));
    cout << "sp1: " << sp1.use_count() << endl;  // 1
    unique_ptr<int> up2(new int(20));
    shared_ptr<int> sp2(std::move(up2));
    cout << "sp2: " << sp2.use_count() << endl;  // 1
    sp1.reset(new int(30));  // delete pointer, then get a new pointer 
    sp2.reset();  // delete pointer 
    
    // Case-2 
    std::shared_ptr<int> p1;
    std::shared_ptr<int> p2 (nullptr);
    std::shared_ptr<int> p3 (new int);
    std::shared_ptr<int> p4 (new int, std::default_delete<int>());
    std::shared_ptr<int> p5 (new int, [](int* p){delete p;}, std::allocator<int>());
    std::shared_ptr<int> p6 (p5);
    std::shared_ptr<int> p7 (std::move(p6));
    std::shared_ptr<int> p8 (std::unique_ptr<int>(new int));
    std::shared_ptr<C> obj (new C);
    std::shared_ptr<int> p9 (obj, obj->data);

    std::cout << "use_count:\n";
    std::cout << "p1: " << p1.use_count() << '\n';  // 0
    std::cout << "p2: " << p2.use_count() << '\n';  // 0
    std::cout << "p3: " << p3.use_count() << '\n';  // 1
    std::cout << "p4: " << p4.use_count() << '\n';  // 1
    std::cout << "p5: " << p5.use_count() << '\n';  // 2 
    std::cout << "p6: " << p6.use_count() << '\n';  // 0
    std::cout << "p7: " << p7.use_count() << '\n';  // 2
    std::cout << "p8: " << p8.use_count() << '\n';  // 1
    std::cout << "p9: " << p9.use_count() << '\n';  // 2
    
    return 0;
}