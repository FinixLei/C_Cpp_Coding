#include <iostream>
using namespace std;

char * my_strcpy(char * dest, const char * source) {
	if (dest == nullptr || source == nullptr) return nullptr;
	
	size_t i = 0;
	while(*(source+i) != '\0') {
		dest[i] = source[i];
		i ++;
	}
	dest[i] = '\0';
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
