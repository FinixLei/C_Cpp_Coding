#include <cassert>
#include <iostream>
using namespace std;

char * my_strcpy(char * dest, const char * source) {
    assert(dest != NULL && source != NULL);
    
    int i = 0;
    while((dest[i] = source[i++]) != '\0');
    return dest;
}

int main() {
    char dest[100];
    char source[] = "Hello, my_strcpy()!"; 
    
    my_strcpy(dest, source);
    cout << dest << endl;
}