#include "Matrix.h"

#include <cassert>

Matrix::Matrix(int rows, int cols) : _rows(rows), _cols(cols) 
{
    _array = new int * [_rows];
    for (int i=0; i<rows; ++i) {
        _array[i] = new int [_cols];
    }
}

Matrix::~Matrix() {
    for (int i=0; i<_rows; ++i) {
        delete [] _array[i];
    }
    delete [] _array;
}

Matrix::Matrix(const Matrix& other)
{
    _rows = other._rows;
    _cols = other._cols;
    
    _array = new int * [_rows];
    for (int i=0; i<_rows; ++i) {
        _array[i] = new int [_cols];
    }
    
    for (int i=0; i<_rows; i++) {
        for (int j=0; j<_cols; j++) {
            _array[i][j] = other._array[i][j];
        }
    }
}

Matrix::Matrix(Matrix&& other)
{
    _rows = other._rows;
    _cols = other._cols;
    _array = other._array;
    other._rows = 0;
    other._cols = 0;
    other._array = nullptr;
}

Matrix& Matrix::operator = (const Matrix& other)
{
    if (this == &other) return *this;
    
    for (int i=0; i<_rows; i++) {
        delete [] _array[i];
    }
    delete [] _array;
    
    _rows = other._rows;
    _cols = other._cols;
    
    _array = new int * [_rows];
    for (int i=0; i<_rows; ++i) {
        _array[i] = new int [_cols];
    }
    
    for (int i=0; i<_rows; i++) {
        for (int j=0; j<_cols; j++) {
            _array[i][j] = other._array[i][j];
        }
    }
}

Matrix& Matrix::operator = (Matrix&& other)
{
    if (this == &other) return *this;
    
    for (int i=0; i<_rows; i++) {
        delete [] _array[i];
    }
    delete [] _array;
    
    _rows = other._rows;
    _cols = other._cols;
    _array = other._array;
    
    other._rows = 0;
    other._cols = 0;
    other._array = nullptr;
}

Matrix operator + (const Matrix& m1, const Matrix& m2)
{
    assert(m1._rows == m2._rows && m1._cols == m2._cols);
    Matrix mx(m1._rows, m1._cols);
    
    for (int i=0; i<mx._rows; i++) {
        for (int j=0; j<mx._cols; j++) {
            mx._array[i][j] = m1._array[i][j] + m2._array[i][j];
        }
    }
    
    return mx; 
}

Matrix operator * (const Matrix& m1, const Matrix& m2)
{
    assert(m1._cols == m2._rows);
    
    Matrix mx(m1._rows, m2._cols);
    
    for (int i=0; i<mx._rows; i++) {
        for (int j=0; j<mx._cols; j++) {
            int sum = 0;
            for (int k=0; k<m1._cols; k++) {
                sum += m1._array[i][k] * m2._array[k][j];
            }
            mx._array[i][j] = sum;
        }
    }
    
    return mx; 
}

std::ostream& operator << (std::ostream& out, const Matrix& m)
{
    for (int i=0; i<m._rows; i++) {
        for (int j=0; j<m._cols; j++) {
            out << m._array[i][j] << " ";
        }
        out << "\n";
    }
    out << "\n";
    return out;
}

void Matrix::set_value(int row, int col, int value)
{
    assert(0 <= row && row <= _rows);
    assert(0 <= col && col <= _cols);
    
    _array[row][col] = value;
}