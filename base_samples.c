#define CONVERT(T) \
(*T) ^= (*(T+3)); (*(T+3)) ^= (*T); (*T) ^= (*(T+3)); \
(*(T+1)) ^= (*(T+2)); (*(T+2)) ^= (*(T+1)); (*(T+1)) ^= (*(T+2)); 

void test_convert_bigend_littleend() {
    int a = 0x12345678;
    printf("0x%x\n", a);  // 0x12345678
    
    CONVERT((char *)&a);
    printf("0x%x\n", a);  // 0x78563412
}

int main(int argc, char * argv[]) {
    test_convert_bigend_littleend();
    
    return 0;
}