#include <cmath>
#include <iostream>
#include "assert.h"
#include <vector>
#include <tuple>
#include <chrono>
#include <algorithm>
#include <functional>

using namespace std;

class Matrix {
    public:
        int mRows;
        int mCols;
        std::vector<vector<int>> data;

        Matrix(int rows, int columns, const vector<vector<int>> &vec) : mRows(rows), mCols(columns), data(vec) {
            if (mRows != mCols) { throw invalid_argument("The dimensions of the matrix specified are not equal.");}
        }

        Matrix(int mRows, int mCols)
            : mRows(mRows),
            mCols(mCols),
            data(mRows * mCols) {
        }

        //! Initializes an empty matrix of specified dimensions
        //! With specified value
        Matrix(int rows, int cols, int value) : mRows(rows), mCols(cols), data(std::vector<std::vector<int>>(rows, std::vector <int> (cols, value))) {}

        //! Initializes a square matrix
        //!  dimension number of rows and columns
        Matrix(int dimension) {
            Matrix(dimension, dimension);
        }

        Matrix operator*(const Matrix &m) const;
        Vector operator*(const Vector &v) const;

        Matrix& Transpose();
        Matrix& Inverse();
        Matrix fill(int rows, int cols, int val);
        void print() const;
};

//
Vector Matrix::operator*(const Vector &v) const{
  
    vector<int> res = {int(v.x), int(v.y), int(v.z), int(v.w)};
    // The vector will always have for components x, y, z, w. 
    vector<int> result = {0,0,0,0};

    for (auto j = 0; j < mCols; ++j)
    {
        for (auto k = 0; k < mCols; ++k) {
            result[j] += data[j][k] * res[k];
        }
    }
    return Vector(result[0],result[1],result[2],result[3]);
}

Matrix Matrix::operator*(const Matrix &b) const {
    if (mCols != b.mRows) {
        throw invalid_argument("Cannot multiplty these matrices." );
    }
    const int n = this->mRows; // a rows
    const int m = this->mCols;
    const int p = b.mCols;

    std::vector<std::vector<int>> c = std::vector<std::vector<int>>(n, std::vector <int> (p, 0));
    for (auto j = 0; j < p; ++j)
    {
        for (auto k = 0; k < m; ++k)
        {
            for (auto i = 0; i < n; ++i)
            {
                c[i][j] += this->data[i][k] * b.data[k][j];
            }
        }
    }
    return Matrix(n, p, c);
}
