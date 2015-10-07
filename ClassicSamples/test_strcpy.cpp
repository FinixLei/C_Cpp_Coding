#include <cassert>
#include <iostream>
using namespace std;

char * my_strcpy(char * dest, const char * source) {
    assert(dest != NULL && source != NULL);
    
    int i = 0;
    while(true) {
        dest[i] = source[i++];
        if (dest[i-1] == '\0') {
            break;
        }
    }
    
    return dest;
}

int main() {
    char dest[100];
    char source[] = "Hello, my_strcpy()!"; 
    
    my_strcpy(dest, source);
    cout << dest << endl;
}