#include <stdio.h>

/* 
    write a macro to convert the big endian/little endian to little endian/big endian. 
*/
void test_convert_bigendian_littleendian() {
    #define CONVERT(T) \
(*T) ^= (*(T+3)); (*(T+3)) ^= (*T); (*T) ^= (*(T+3)); \
(*(T+1)) ^= (*(T+2)); (*(T+2)) ^= (*(T+1)); (*(T+1)) ^= (*(T+2)); 

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
    # define IsUnsigned(X) ((X) >= 0 && (~X) >= 0)
    
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
    #define IsUnsignedType(TYPE) (((TYPE)0 - (TYPE)1) > (TYPE)0)
    
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

int main(int argc, char * argv[]) {
    test_check_type_signed_unsigned(); 
    test_check_signed_unassigned();
    test_convert_bigendian_littleendian();
    
    return 0;
}