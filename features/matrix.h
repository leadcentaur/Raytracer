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
    private:
        int mRows;
        int mCols;
        std::vector<vector<int>> data;
    public:
        Matrix(int rows, int columns, const vector<vector<int>> vec) : mRows(rows), mCols(columns), data(vec) {
            if (mRows != mCols) { throw invalid_argument("The dimensions of the matrix specified are not equal.");}
        }
        Matrix(int rows, int cols, int value) 
            : mRows(rows), mCols(cols), 
        data(std::vector<std::vector<int>>(rows, std::vector <int> (cols, value))) 
        {}

        int nCols() const { return mCols; }
        int nRows() const { return mRows; }
        vector<vector<int>> getData() const { return data; }
        void setData(vector<vector<int>> &v) { data = v;}

        std::vector<vector<int>> mData() const { return data; }

        Matrix operator*(const Matrix &m) const;
        Vector operator*(const Vector &v) const;

        int Detriment();
        Matrix Transpose();
        Matrix Inverse();

        //Matrix submatrix(int row, int column) const;
        Matrix fill(int rows, int cols, int val);
        void print() const;
};
//Transpose matrix function
Matrix Matrix::Transpose()
{
    int nrows = this->nRows();
    int ncols = this->nCols();
    vector<vector<int>> oData = this->getData();

    cout << "Number of rows; " << nrows << '\n';
    cout << "Number of cols; " << ncols << '\n';

    std::vector<std::vector<int>> data(nrows, std::vector <int> (ncols, 0));

    for (int i = 0; i < ncols; i++)
        for (int j = 0; j < nrows; j++)
            data[i][j] = oData[i][j];

    this->data = data;
    return *this;
}

Matrix submatrix(const Matrix &m, int row, int col)
{   
    int nrows = m.nRows();
    int ncols = m.nCols();

    vector<vector<int>> d = m.getData();

    int subi = 0;
    for (int i = 0; i < nrows; i++)
    {   
        int subj = 0;
        if (i == row) continue;
        for (int j = 0; j < ncols; j++) {
            if (j == col) continue;
            int val = d[i][j];
            cout << val << '\n';
            d[subi][subj] = val;
            subj++;
        }
        subi++;
    }
    Matrix result = Matrix(m.nRows()-1, m.nCols()-1, d);
    return result;
}
//! The minor is the determiant of the submatrix
int minor(const Matrix &m, int row, int col)
{   
    cout << "Minor called." << '\n';
    return submatrix(m, row, col).Detriment();
}
int cofactor(const Matrix &m, int row, int col)
{   
    cout << "Co-factor called." << '\n';
    int miner = minor(m, row, col);
    return (row + col) % 2 == 0 ? miner : -miner;
}
int Matrix::Detriment()
{   
    int ncols = this->nCols();
    int nrows = this->nRows();

    // cout << "ncols: " << ncols;
    // cout << "nrows: " << nrows;
    
    size_t determinent = 0;
    vector<vector<int>> data = this->getData();
    if (ncols == 2 && nrows == 2) {
        return (data[0][0] * data[1][1]) - (data[1][0] * data[0][1]);
    } else {
        for (int i = 0; i < ncols+1; i++) {
            determinent += cofactor(*this, 0, i) * data[0][i];
        }
    }
    return determinent;
}

void Matrix::print() const
{   
    cout << '\n';
    int nrows = this->nRows();
    int ncols = this->nCols();

    for (int i = 0; i < nrows; i++)
    {
        cout << "{";
        for (int j = 0; j <ncols; j++)
        {
            cout << ' ' << this->data[i][j] << ' ';
        }
        cout << "}\n";
    }
    cout << '\n';
}

Vector Matrix::operator*(const Vector &v) const{
  
    vector<int> res = {int(v.x), int(v.y), int(v.z), int(v.w)};
    // The vector will always have for components x, y, z, w. 
    vector<int> result = {0,0,0,0};

    #pragma omp parallel for collapse(2)
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
