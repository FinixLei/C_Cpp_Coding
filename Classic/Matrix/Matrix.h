#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
public:
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);
    virtual ~Matrix();
    
    Matrix& operator = (const Matrix& other);
    Matrix& operator = (Matrix&& other);

    void set_value(int row, int col, int value);
    
    friend Matrix operator + (const Matrix& m1, const Matrix& m2);
    friend Matrix operator * (const Matrix& m1, const Matrix& m2);
    friend std::ostream& operator << (std::ostream& out, const Matrix& m);
    
private:
    int ** _array;
    int _rows;
    int _cols;
};

#endif