#include <iostream>
using namespace std;


class Singleton {
private:
    static Singleton * _sgt; 
    Singleton() {}
    
public:
    static Singleton * getInstance() {
        if (_sgt == NULL) {
            _sgt = new Singleton();
        } 
        return _sgt;
    }
};

Singleton * Singleton::_sgt = NULL;

int main(int argc, char ** argv) {
    Singleton * a = Singleton::getInstance();
    Singleton * b = Singleton::getInstance();
    
    cout << hex << a << endl;
    cout << hex << b << endl;
}
