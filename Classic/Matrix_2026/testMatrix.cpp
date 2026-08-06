#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
    vector<vector<int>> v1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    vector<vector<int>> v2 ={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    Matrix m1(3, 4);
    m1.copyFrom(v1);
    cout << "m1 is : " << endl;
    cout << m1 << endl;
    
    Matrix m2 = m1;
    
    Matrix m3 = m1 + m2;
    cout << "m3 is : " << endl;
    cout << m3 << endl;
    
    
    Matrix m4(4,3);
    m4.copyFrom(v2);
    cout << "m4 is : " << endl;
    cout << m4 << endl;
    
    Matrix m5 = m1 * m4;
    cout << "m5 is : " << endl;
    cout << m5;
}