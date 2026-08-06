#include <iostream>
#include <stdexcept>
#include <vector>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int row, int col) : row(row), col(col), vec(row, vector<int>(col, 0)) {}

Matrix::Matrix(const Matrix& other) : row(other.row), col(other.col), vec(other.vec) {}

Matrix::Matrix(Matrix&& other) : row(other.row), col(other.col), vec(std::move(other.vec)) {
    other.row = 0;
    other.col = 0;
}

Matrix& Matrix::operator = (Matrix&& other) {
    if (this == &other) return *this;
    
    row = other.row;
    col = other.col;
    vec = std::move(other.vec);
    
    other.row = 0;
    other.col = 0;
    other.vec.clear();
    
    return *this;
}

Matrix::~Matrix() {}

Matrix& Matrix::operator = (const Matrix& other) {
    if (this == &other) return *this;
    
    row = other.row;
    col = other.col;
    vec = other.vec;
    return *this;
}

void Matrix::copyFrom(const vector<vector<int>>& array) {
    if (row != array.size()) {
        throw std::out_of_range("Wrong row of array");
    }
    for (int i = 0; i < row; ++i) {
        if (array[i].size() != col) {
            throw std::out_of_range("Wrong column in some row");
        }
    }
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            vec[i][j] = array[i][j];
        }
    }
}

const vector<int>& Matrix::operator [](int index) const {
    return vec[index];
}

vector<int>& Matrix::operator [](int index) {
    return vec[index];
}

Matrix operator + (const Matrix& m1, const Matrix& m2)
{
    if (m1.row != m2.row || m1.col != m2.col) {
        throw runtime_error("Matrix size not matched for +");
    }
    
    Matrix m3(m1.row, m1.col);
    for (int i=0; i<m3.row; i++) {
        for (int j=0; j<m3.col; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return m3;
}

Matrix operator * (const Matrix& m1, const Matrix& m2) {
    if (m1.col != m2.row) {
        throw runtime_error("Matrix size not matched for *");
    }
    
    Matrix m3(m1.row, m2.col);
   
    for (int i=0; i<m3.row; i++) {
        for (int j=0; j<m3.col; j++) {
            int tmp = 0;
            for (int k=0; k<m1.col; k++) {
                tmp += m1[i][k] * m2[k][j];
            }
            m3[i][j] = tmp;
        }
    }
    return m3;
}

ostream& operator << (ostream& oo, const Matrix& m) {
    for (int i=0; i<m.row; i++) {
        for (int j=0; j<m.col; j++) {
            oo << m[i][j] << " ";
        }
        oo << endl;
    }
    return oo;
}
