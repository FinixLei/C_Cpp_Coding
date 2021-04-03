#include <iostream>
using namespace std;

char * my_strcpy(char * dest, const char * source) {
    if (dest == nullptr || source == nullptr) return nullptr;
    
    int i = 0;
    
    // while((dest[i] = source[i++]) != '\0');
    // Above may have some problem in some case, 
    // so, personally, I like to use more readable style as below. 
    while (source[i] != 0) {
        dest[i] = source[i];
        ++i;
    }
    
    return dest;
}

int main() {
    char *dest = new char [100]; 
    char source[] = "Hello, my_strcpy()!"; 
    
    my_strcpy(dest, source);
    cout << dest << endl;
    
    delete [] dest;
    return 0;
}
