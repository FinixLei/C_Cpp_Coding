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

void * my_memcpy(void *dest, void *src, int size) 
{
    char * c_dest = (char *)dest; 
    char * c_src  = (char *)src; 
    void * result = nullptr;
    
    if (c_src == c_dest) {
        result = dest;
    }
    else if (c_src < c_dest && c_dest < c_src+size) {
        for (int count = size-1; count >= 0; --count) {
            c_dest[count] = c_src[count];
        }
        result = (void *)c_dest;
    }
    else {
        for (int i=0; i<size; ++i) {
            c_dest[i] = c_src[i];
        }
        result = (void *)c_dest;
    }
    return result; 
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
    my_memcpy(np2, np1, size1*sizeof(int));
    print_array(np1, size1);
    print_array(np2, size1);
    
    int *np3 = np1 + 2;
    // size2 = 10 will cause crash for both memcpy and my_memcpy
    int size2 = 5;
    // memcpy(np3, np1, size2*sizeof(int));
    my_memcpy(np3, np1, size2*sizeof(int));
    print_array(np3, size2);
    print_array(np1, size1);
    
    delete [] np1;
    delete [] np2;
    
    return 0;
}