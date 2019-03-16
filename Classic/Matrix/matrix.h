#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
public: 
    Matrix(int row=0, int col=0); 
    Matrix(const Matrix &other);
    ~Matrix();
    
    // Note, operator= should return reference for efficiency, as it returns *this 
    Matrix& operator= (const Matrix &other);
    
    void set_value(int row, int col, int value);
    
friend Matrix operator+ (const Matrix& a, const Matrix& b);
friend Matrix operator* (const Matrix& a, const Matrix& b);
friend std::ostream& operator<< (std::ostream& out, const Matrix& m);

private:
    int row;
    int col;
    int ** mp;
    
};


#endif