#include <stdio.h>
#include <string.h>

/* 
    char * strstr(char * str1, char * str2)
    Function: find the first place of the designated string
*/

void test_strstr() {
    char str1[] = "This is a simple string";
    char * str2 = "simple";
    char * replace_str = "sample";
    char * ptr = NULL;
    int size, length;
    
    size = sizeof(replace_str);
    printf("size is %d\n", size);  // size is 8, as this is a pointer on a 64-bit machine
    length = strlen(replace_str);
    printf("length is %d\n", length);  // length is 6
    
    ptr = strstr(str1, str2);
    strncpy(ptr, replace_str, strlen(replace_str));
    puts(str1);  // This is a sample string
}

/*
    char * strok(char * s, char * delimeters); 
    Function: find all the words in str1 but delimited by the delimitors specified in str2
*/

void test_strtok() {
    char input[] = "a b c,d";
    char * p;
    char delimeters[] = ", ";  // the delimiter is space and comma
    
    // the first use of strok
    p = strtok(input, delimeters);
    
    while (p != NULL) {
        printf("%s ", p);
        p = strtok(NULL, delimeters);
    }
    // will print: a b c d
}

int main(int argc, char ** argv) {
    test_strstr();
    test_strtok();
    
    return 0;
}
