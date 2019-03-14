#include <iostream>
#include "matrix.h"

using namespace std;

int main(int argc, char *argv[])
{
    int i, j;
    int value = 1;
    Matrix m1(2, 3);
    for(i=0; i<2; i++)
        for(j=0; j<3; j++)
            m1.set_value(i, j, value++);
    cout<<"m1=\n";
    cout<<m1<<endl;
    
    Matrix m2 = m1;
    cout<<"m2=\n";
    cout<<m2<<endl;
    
    Matrix m3 = m1 + m2;
    cout<<"m3=\n";
    cout<<m3<<endl;
    
    Matrix m4(3, 2);
    value = 1;
    for(i=0; i<3; i++)
        for(j=0; j<2; j++)
            m4.set_value(i, j, value++);
    cout<<"m4=\n";
    cout<<m4<<endl;
    
    Matrix m5(2,2);
    m5 = m3 * m4;
    cout<<"m5=\n";
    cout<<m5 <<endl;
    
    return 0;
}
