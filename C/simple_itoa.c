#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_itoa(int num, char* str, int radix)
{
    char index[]="0123456789ABCDEF";
    
    int pos = 0;
    unsigned int unum = ( num < 0 ? (-num) : num );
    
    if ( num < 0) {
        str[0] = '-';
        ++ pos;
    }

    do {
        str[pos++] = index[unum % radix]; 
        unum /= radix; 
    }while (unum > 0);
    
    int beg = ( num < 0 ? 1 : 0 );
    int end = pos - 1;
    
    while (beg < end) {
        char tmp = str[beg];
        str[beg] = str[end];
        str[end] = tmp; 
        beg ++; 
        end --;
    }
    
    return str;
}

int main(void) {
    const int size = 20;
    char char_array[size];
    int int_style;
    
    int num1 = 1234;
    my_itoa(num1, char_array, 10);
    printf("num1 = %d, str_num1 = %s\n", num1, char_array);
    
    memset(char_array, 0, size);
    int num2 = 0x9A;
    my_itoa(num2, char_array, 16);
    printf("num2 = 0x%x, str_num2 = %s\n", num2, char_array);
    
    return 0;
}
