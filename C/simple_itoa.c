#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_itoa(int num, char* str, int radix)
{
    char index[]="0123456789ABCDEF";  // Ë÷Òý±í
    unsigned unum;
    int i=0;
    int j, k, l;
    
    if (num<0) {
        str[0] = '-';
        i = 1;
        num = -num; 
    }
    unum = (unsigned)(num);
    
    do{
        str[i++] = index[unum%(unsigned)radix];
        unum /= radix;
    } while(unum);
    
    str[i]='\0';
    
    if(str[0]=='-')
        k=1;
    else
        k=0;
    
    // ÄæÐò
    char temp;
    for(j=k, l=i-1; j<l; j++, l--) {
        temp = str[j];
        str[j] = str[l];
        str[l] = temp;
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
