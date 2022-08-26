#include <cmath>
#include <iostream>
#include "assert.h"
#include <vector>
#include <tuple>
#include <chrono>
#include <algorithm>
#include <functional> 
#include "exceptions.h"

class Matrix {
    public:
        int mRows;
        int mCols;
        std::vector<vector<int>> data;

        Matrix(int rows, int columns, const std::vector<vector<int>> &vec) : mRows(rows), mCols(columns), data(vec) {
            if (mRows != mCols) { throw invalidMatrixException("The dimensions of the matrix specified are not equal.");}
        }

        bool validateMatrix();
        Matrix operator+(const Matrix &m) const ;
        Matrix operator*(const Matrix &m) const;
        Matrix& Transpose();
        Matrix& Inverse();
};

Matrix Matrix::operator+(const Matrix &m) const {
    ;
}

Matrix Matrix::operator*(const Matrix &m) const {
    ;
}

