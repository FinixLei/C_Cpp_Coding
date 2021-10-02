#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

class MyClass
{
private:
    int * _pd;
    
public:
    MyClass(int d=0) {
        _pd = new int(d);
    }
    
    ~MyClass() {
        delete _pd;
    }
    
    int get_data() {return *_pd;}
};

int main()
{
    char * buf = (char *) malloc(sizeof(MyClass));
    MyClass * p = new (buf) MyClass(100);
    
    cout << p->get_data() << endl;
    
    p->~MyClass();
    free(buf);
    
    return 0;
}