#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int row;
    int col;
    vector<vector<int>> vec;
    
public:
    Matrix(int row=0, int col=0);
    
    Matrix(const Matrix& other);
    Matrix& operator = (const Matrix& other);
    
    Matrix(Matrix&& other);
    Matrix& operator = (Matrix&& other);
    
    ~Matrix();

    void copyFrom(const vector<vector<int>>& array);
    
    const vector<int>& operator [](int index) const;
    vector<int>& operator[] (int index);
    
    friend std::ostream& operator << (std::ostream& oo, const Matrix& m);
    friend Matrix operator + (const Matrix& m1, const Matrix& m2);
    friend Matrix operator * (const Matrix& m1, const Matrix& m2);
};

#endif