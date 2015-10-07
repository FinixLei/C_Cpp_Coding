#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix {
private:
    int _row;
    int _col;
    int ** _mp;
    
public:
    Matrix(int row=0, int col=0);
    virtual ~Matrix();
    Matrix(const Matrix & other);
    Matrix& operator = (const Matrix & other);
    
    friend const Matrix operator + (const Matrix & a, const Matrix & b);
    friend const Matrix operator * (const Matrix & a, const Matrix & b);
    friend ostream& operator << (ostream& oo, const Matrix & m);
    
    void set_value(int value, int row, int col);
};

#endif
