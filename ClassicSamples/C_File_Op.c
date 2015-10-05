#include <stdio.h>

int main(int argc, char ** argv) {
    FILE * fp = fopen("ClassicSamples/C_File_Op.c", "r");
    char ch;
    
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
    
    return 0;
}
