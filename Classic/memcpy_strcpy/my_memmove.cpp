#include <cstring>
#include <iostream>
using namespace std; 


template <typename T> 
void print_array(T* array, int size)
{
    for (int i=0; i<size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << endl;
}

void *my_memmove(void *dst, const void *src, size_t n)
{
	if (dst == src || n == 0) return dst;
	
	char * d = (char *)dst;
	const char * s = (const char *)src;
	
	if (s < d && d < s + n) {
		for (size_t i=n; i>0; i--) {
			d[i-1] = s[i-1];
		}
	}
	else {
		for (size_t i=0; i<n; i++) {
			d[i] = s[i];
		}
	}
	return dst;	
}

int main()
{
    const int size1 = 10;
    int *np1 = new int [size1];
    for(int i=0; i<size1; i++) {
        np1[i] = (i+1) * 10;
    }
    
    int *np2 = new int [size1];
    // memcpy(np2, np1, size1*sizeof(int));
    my_memmove(np2, np1, size1*sizeof(int));
    print_array(np1, size1);
    print_array(np2, size1);
    
    int *np3 = np1 + 2;
    // size2 = 10 will cause crash for both memcpy and my_memmove
    int size2 = 5;
    // memcpy(np3, np1, size2*sizeof(int));
    my_memmove(np3, np1, size2*sizeof(int));
    print_array(np3, size2);
    print_array(np1, size1);
    
    delete [] np1;
    delete [] np2;
    
    return 0;
}