#include <stdio.h>
#include <stdlib.h>

char* my_itoa(int num, char* str, int radix)
{
    char index[]="0123456789ABCDEF";  /*索引表*/
    unsigned unum;/*中间变量*/
    int i=0;
    int j, k, l;
    
    /*确定unum的值*/
    if(radix==10 && num<0)/*十进制负数*/
    {
        unum=(unsigned)-num;
        str[i++]='-';
    }
    else 
        unum=(unsigned)num;
    
    do{
        str[i++]=index[unum%(unsigned)radix];
        unum/=radix;
    } while(unum);
    str[i]='\0';
    
    /*逆序*/
    if(str[0]=='-')  /*负数*/
        k=1;
    else
        k=0;
    
    char temp;
    for(j=k, l=i-1; j<l; j++, l--) {
        temp = str[j];
        str[j] = str[l];
        str[l] = temp;
    }
    return str;
}

int main(void) {
    char s[20];
    char str_style[20];
    int int_style;
    
    printf("Please input a number: ");
    scanf("%s", s);
    
    int_style = atoi(s);
    printf("int_style = %d\n", int_style);
    
    my_itoa(int_style, str_style, 10);
    printf("str_style = %s\n", str_style);
    
    return 0;
}
