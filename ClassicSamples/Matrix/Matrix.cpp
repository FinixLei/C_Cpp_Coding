#include "Matrix.h"
#include <cassert>

Matrix::Matrix(int row, int col):_row(row), _col(col) {
    assert(_row > 0 && _col > 0);
    
    _mp = new int * [_row];
    for (int i=0; i<row; i++) {
        _mp[i] = new int[_col];
    }
}

Matrix::~Matrix() {
    for (int i=0; i<_row; i++) {
        delete [] _mp[i];
    }
    delete [] _mp;
}

Matrix::Matrix(const Matrix & other) {
    _row = other._row;
    _col = other._col;
    
    _mp = new int * [_row];
    for (int i=0; i<_row; i++) {
        _mp[i] = new int[_col];
    }
    
    for (int i=0; i<_row; i++)
        for (int j=0; j<_col; j++) {
            _mp[i][j] = other._mp[i][j];
        }
}

Matrix& Matrix::operator = (const Matrix & other) {
    if (this == &other) {
        return *this;
    }
    
    for (int i=0; i<_row; i++) {
        delete [] _mp[i];
    }
    delete [] _mp;
    
    _row = other._row;
    _col = other._col;
    
    _mp = new int * [_row];
    for (int i=0; i<_row; i++) {
        _mp[i] = new int[_col];
    }
    
    for (int i=0; i<_row; i++)
        for (int j=0; j<_col; j++) {
            _mp[i][j] = other._mp[i][j];
        }
}

void Matrix::set_value(int value, int row, int col) {
    assert(row >=0 && row < _row && col >= 0 && col < _col);
    
    _mp[row][col] = value;
}

const Matrix operator + (const Matrix & a, const Matrix & b) {
    assert(a._row == b._row && a._col == b._col);
    
    int row = a._row;
    int col = a._col;
    
    Matrix temp(row, col); 
    
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++) {
            temp._mp[i][j] = a._mp[i][j] + b._mp[i][j];
        } 
        
    return temp;
}

const Matrix operator * (const Matrix & a, const Matrix & b) {
    assert(a._col == b._row);
    
    int row = a._row;
    int col = b._col;
    Matrix temp(row, col);
    
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            temp._mp[i][j] = 0;
            
            for (int k=0; k<a._col; k++) {
                temp._mp[i][j] += a._mp[i][k] * b._mp[k][j];
            }
        }
    }
    
    return temp;
}

ostream& operator << (ostream& oo, const Matrix & m) {
    for (int i=0; i<m._row; i++) {
        for (int j=0; j<m._col; j++) {
            oo << m._mp[i][j] << " ";
        }
        oo << endl;
    }
    return oo;
}
