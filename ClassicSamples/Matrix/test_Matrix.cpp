#include "Matrix.h"

int main(int argc, char *argv[])
{
    int value = 1;
    
    Matrix m1(2, 3);
    for(int i=0; i<2; i++)
        for(int j=0; j<3; j++)
            m1.set_value(value++, i, j);
    cout << m1 << endl;
    
    Matrix m2(m1);
    cout << m2 << endl;
    
    Matrix m3 = m1 + m2;
    cout << m3 << endl;
    
    
    Matrix m4(3, 2);
    value = 1;
    for(int i=0; i<3; i++)
        for(int j=0; j<2; j++) {
            m4.set_value(value++, i, j);
        }
    cout << m4 << endl;
    
    Matrix m5(2,2);
    m5 = m3 * m4;
    cout << m5 << endl;
    
    return 0;
}

/*
    $ ./test_Matrix.exe
    1 2 3
    4 5 6

    1 2 3
    4 5 6

    2 4 6
    8 10 12

    44 56
    98 128
*/
