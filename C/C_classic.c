#include <stdio.h>
#include <stdlib.h>

/* 
    write a macro to convert the big endian/little endian to little endian/big endian. 
*/
void test_convert_bigendian_littleendian() {
    #define CONVERT(T) \
    { \
        (*T) ^= (*(T+3)); (*(T+3)) ^= (*T); (*T) ^= (*(T+3)); \
        (*(T+1)) ^= (*(T+2)); (*(T+2)) ^= (*(T+1)); (*(T+1)) ^= (*(T+2)); \
    }

    int a = 0x12345678;
    printf("0x%x\n", a);  // 0x12345678
    
    CONVERT((char *)&a);
    printf("0x%x\n", a);  // 0x78563412
    printf("---------------------------------\n");
}

/* 
    write a macro to check a varaible is signed or unassigned
*/
void test_check_signed_unassigned() {
    // Note, 下面要用取反的符号~，而不能用负号，否则无法判断0
    # define IsUnsigned(X) ((X) >= 0 && (~(X)) >= 0)
    
    int a = 0;
    unsigned int b = 0;
    
    if (IsUnsigned(a)) {
        printf("a is unsigned\n"); 
    } else {
        printf("a is signed\n");  // hit
    }
    
    if (IsUnsigned(b)) {
        printf("b is unsigned\n");  // hit
    } else {
        printf("b is signed\n");
    }
    printf("---------------------------------\n");
}

/* 
    write a macro to check a type is signed or unsigned
*/
void test_check_type_signed_unsigned() {
    #define IsUnsignedType(TYPE) ((TYPE)(0) - (TYPE)(1) > (TYPE)(0))
    
    if (IsUnsignedType(int)) {
        printf("int is unsigned type\n");
    } else {
        printf("int is signed type\n");
    }
    
    if (IsUnsignedType(unsigned int)) {
        printf("unsigned int is unsigned type\n");
    } else {
        printf("unsigned int is signed type\n");
    }
    
    printf("---------------------------------\n");
}

/* 
    write a macro to implement swap
*/
void test_swap() {
    #define swap_1(A,B) { A=A+B; B=A-B; A=A-B; }
    
    #define swap_2(A,B) { A=A^B; B=A^B; A=A^B; }
    
    int a = 10, b = 20;
    printf("a = %d, b = %d\n", a, b);  // 10, 20
    
    swap_1(a, b); 
    printf("a = %d, b = %d\n", a, b);  // 20, 10
    
    swap_2(a, b); 
    printf("a = %d, b = %d\n", a, b);  // 10, 20
    
    printf("---------------------------------\n");
}

/*
    write a macro to check if a variable is 2^n 
*/
void test_check_2_power() {
    # define IsTwoPower(X) (((X) & ((X)-1)) ? 0 : 1)
    
    int a = 100, b = 64;
    
    if (IsTwoPower(a)) {
        printf("%d is 2 power\n", a);
    } else {
        printf("%d is not 2 power\n", a);
    }
    
    if (IsTwoPower(b)) {
        printf("%d is 2 power\n", b);
    } else {
        printf("%d is not 2 power\n", b);
    }
    
    printf("---------------------------------\n");
}

/*
    calculate how many 1 there are in one specified number's binary style
*/
void test_count_one_in_binary_number(int value) {
    int num = value;
    int count = 0;
    char binary_style[10];
    
    while (num) {
        count ++;
        num = num & (num - 1); 
    }
    
    printf("There are %d 1-s in the binary style of %d\n", count, value);
    printf("The hex style of %d is 0x%x\n", value, value);
    printf("---------------------------------\n");
}

/* 
    basic usage of union
*/
void test_basic_usage_of_union() {
    union my_un{
        int a;
        char ch;
    };
    
    union my_un mu;  // union cannot be initialized. "my_un mu.a = 10;" cannot pass compiler. 
    mu.a = 100;
    printf("mu.a is %d\n", mu.a); 
    mu.ch = 'a';
    printf("mu.ch is %c\n", mu.ch); 
    printf("size of mu is %d\n", sizeof(mu));  // 4
    
    printf("---------------------------------\n");
}

/*
    show the initialization of struct; 
    show the array assignment in struct;
*/
void test_usage_of_struct() {
    int i;
    
    struct my_stct{
        int array[3]; 
    };
    
    struct my_stct a1 = {
        .array = {10, 20, 30}
    };
    struct my_stct a2 = {
        .array = {100, 200, 300}
    }; 
    
    a2 = a1;  // array assignment happened!
    
    for (i=0; i<3; i++) {
        printf("%d ", a2.array[i]);  // 10 20 30
    }
    printf("\n---------------------------------\n");
}

/*
    check big endian or little endian
*/
#include <stdio.h>

int isLittleEndian()
{
    union w
    {
        int a;
        char b;
    } c;
    c.a = 1;
return(c.b == 1);
}

void test_little_endian() {
    int isLittle = isLittleEndian();
    if (isLittle) {
        printf("This is Little Endian\n"); 
    } else {
        printf("This is Big Endian\n"); 
    }
    printf("---------------------------------\n");
}

int main(int argc, char * argv[]) {
    test_little_endian();
    test_usage_of_struct();
    test_basic_usage_of_union();
    test_count_one_in_binary_number(99);
    test_check_2_power();
    test_swap();
    test_check_type_signed_unsigned(); 
    test_check_signed_unassigned();
    test_convert_bigendian_littleendian();
    
    return 0;
}