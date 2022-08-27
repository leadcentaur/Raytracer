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
        Matrix operator*(const Vector &v) const;

        Matrix& Transpose();
        Matrix& Inverse();
        Matrix fill(int rows, int cols, int val);
};

//! used to multiply A * n where A is a matrix and b is a vector / tuple
Matrix Matrix::operator*(const Vector &v) const{
    if (this->mRows != 4) 
    { 
        throw invalid_argument("When mulitply a Matrix by a vector. dimensions of matrix must be : 4xn (rows x cols)");
    }
    for (auto j = 0; j < p; ++j)
    {
        for (auto k = 0; k < m; ++k)
        {
            
        }
    }
}

//! used to multiple A * B where A and are both Matrices
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
