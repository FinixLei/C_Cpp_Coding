#include <iostream>
#include "matrix.h"
using namespace std;


Matrix::Matrix(int row, int col) : row(row), col(col)
{
    if (row <= 0 || col <= 0) return; 
    
    mp = new int* [row];
    for (int i=0; i<row; ++i) {
        mp[i] = new int [col];
    }
}

Matrix::Matrix(const Matrix& other)
{
    row = other.row;
    col = other.col;
    mp = new int* [row];
    for (int i=0; i<row; ++i) {
        mp[i] = new int [col];
    }
    for (int i=0; i<row; ++i) {
        for (int j=0; j<col; ++j) {
            mp[i][j] = other.mp[i][j];
        }
    }
}

Matrix& Matrix::operator= (const Matrix &other) 
{
    if (this == &other) return *this;
    
    for (int i=0; i<row; ++i) {
        delete [] mp[i];
    }
    delete [] mp; 
    
    row = other.row;
    col = other.col;
    mp = new int* [row];
    for (int i=0; i<row; ++i) {
        mp[i] = new int [col];
    }
    for (int i=0; i<row; ++i) {
        for (int j=0; j<col; ++j) {
            mp[i][j] = other.mp[i][j];
        }
    }
    return *this;
}

Matrix::~Matrix()
{
    for (int i=0; i<row; ++i) {
        delete [] mp[i];
    }
    delete [] mp; 
}

void Matrix::set_value(int row, int col, int value)
{
    this->mp[row][col] = value;
}

Matrix operator+ (const Matrix& a, const Matrix& b) 
{
    if (a.row != b.row || a.col != b.col) return Matrix();
    
    Matrix c(a.row, a.col);
    for (int i=0; i<a.row; ++i) {
        for (int j=0; j<a.col; ++j) {
            c.mp[i][j] = a.mp[i][j] + b.mp[i][j];
        }
    }
    return c;
}

Matrix operator* (const Matrix& a, const Matrix& b) 
{
    if (a.col != b.row) {
        return Matrix();
    }
    
    Matrix c(a.row, b.col);
    
    for (int i=0; i<a.row; ++i) {
        for (int j=0; j<b.col; ++j) {
            c.mp[i][j] = 0;
            for (int k=0; k<a.col; ++k) {
                c.mp[i][j] += a.mp[i][k] * b.mp[k][j];
            }
        }
    }
    return c; 
}

ostream& operator<< (ostream& out, const Matrix& m)
{
    for (int i=0; i<m.row; ++i) {
        for (int j=0; j<m.col; ++j) {
            out << m.mp[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

