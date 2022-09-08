#include <cmath>
#include <iostream>
#include "assert.h"
#include <vector>
#include <tuple>
#include <chrono>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <math.h>
#include <complex>
#include <cfloat>

using namespace std;
enum Axis {RotX, RotY, RotZ};

class Matrix {
    private:
        int mRows;
        int mCols;
        vector<vector<double>> data;

    public:
        Matrix(int rows, int columns, const vector<vector<double>> &vec) : mRows(rows), mCols(columns), data(vec) {
            if (mRows != mCols) { throw invalid_argument("The dimensions of the matrix specified are not equal.");}
        }
        Matrix(int mRows, int mCols)
            : mRows(mRows),
            mCols(mCols),
            data(mRows * mCols) {
        }

        Matrix(int rows, int cols, int value) 
            : mRows(rows), mCols(cols), 
        data(vector<vector<double>>(rows, vector <double> (cols, value)))
        {}

        int nCols() const { return mCols; }
        int nRows() const { return mRows; }
        double Detriment();

        vector<vector<double>> getData() const { return data; }
        void setData(vector<vector<double>> &v) { data = v; }

        Matrix operator*(const Matrix &m) const;
        Vector operator*(const Vector &v) const;

        Matrix Transpose();
        Matrix Inverse();

        static Matrix Translation(const Vector&v );
        static Matrix Scaling(const Vector&v);
        static Matrix Identity(int nRows, int nCols, int value = 1);

        static Matrix Rotation(double radians, Axis rot);

        //Matrix submatrix(int row, int column) const;
        Matrix fill(int rows, int cols, int val);
        bool canInvert();
        
        void print() const;
        void printDouble() const;
        friend class Vector;
};
//! will need to include as utility function

string FPClass(double x)
{
    int i = _fpclass(x);
    string s;
    switch (i)
    {
        case _FPCLASS_SNAN: s = "Signaling NaN";                break;
        case _FPCLASS_QNAN: s = "Quiet NaN";                    break; 
        case _FPCLASS_NINF: s = "Negative infinity (-INF)";     break; 
        case _FPCLASS_NN:   s = "Negative normalized non-zero"; break;
        case _FPCLASS_ND:   s = "Negative denormalized";        break; 
        case _FPCLASS_NZ:   s = "Negative zero (-0)";           break; 
        case _FPCLASS_PZ:   s = "Positive 0 (+0)";              break; 
        case _FPCLASS_PD:   s = "Positive denormalized";        break; 
        case _FPCLASS_PN:   s = "Positive normalized non-zero"; break; 
        case _FPCLASS_PINF: s = "Positive infinity (+INF)";     break;
    }
    return s;
}

Matrix Matrix::operator*(const Matrix &b) const {
    if (mCols != b.mRows) {
        throw invalid_argument("Cannot multiplty these matrices." );
    }
    const int n = this->mRows; // a rows
    const int m = this->mCols;
    const int p = b.mCols;

    std::vector<std::vector<double>> c = vector<vector<double>>(n, vector<double> (p, 0));
    for (auto j = 0; j < p; ++j) {
        for (auto k = 0; k < m; ++k) {
            for (auto i = 0; i < n; ++i) {
                c[i][j] += this->data[i][k] * b.data[k][j];
            }
        }
    }
    return Matrix(n, p, c);
}

Vector Matrix::operator*(const Vector &v) const{
  
    vector<double> res = {v.x, v.y, v.z, v.w};
    vector<double> result = {0,0,0,0};
    vector<vector<double>> data = this->getData();    
    for (auto j = 0; j < mCols; ++j) {
        for (auto k = 0; k < mCols; ++k) {
            result[j] += data[j][k] * (res[k]);
        }
    }

    return Vector(result[0],result[1],result[2],result[3]);
}

Matrix Identity(int nRows = 4, int nCols = 4, int value = 0)
{   vector<vector<double>> init = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    Matrix identity = Matrix(nRows,nCols,init);
    auto data = identity.getData();
    for (int i = 0; i < nRows; i++){
        data[i][i] = 1;
    }
    identity.setData(data);
    return identity;
}

//! translation function - takes a vector (x,y,z,w)
static Matrix Translation(const Vector& v)
{
    Matrix translationMatrix = Identity();
    auto mData = translationMatrix.getData();

    //! translation matrix unchanging
    mData[0][3] = v.x; // { 1 0 0 x }
    mData[1][3] = v.y; // { 0 1 0 y}
    mData[2][3] = v.z; // { 0 0 1 z }
    mData[3][3] = v.w; // { 0 0 0 1 }

    translationMatrix.setData(mData);
    return translationMatrix;
}

//! used to rotate a vector around the x axis
static Matrix Rotation(double radians, Axis rotation)
{
    Matrix rotMatrix = Identity();
    vector<vector<double>> mData = rotMatrix.getData();
    switch (rotation)
    {
    case Axis::RotX:
        cout << "X Case executed.";
        mData[1][1] = cos(radians);
        mData[1][2] = -+sin(radians);
        mData[2][1] = sin(radians);
        mData[2][2] = cos(radians);
        break;
    case Axis::RotY:
        mData[0][0] = cos(radians);
        mData[0][2] = sin(radians);
        mData[2][0] = -+sin(radians);
        mData[2][2] = cos(radians);
        break;
    case Axis::RotZ:
        mData[0][0] = cos(radians);
        mData[0][1] = -+sin(radians);
        mData[1][1] = sin(radians);
        mData[1][1] = cos(radians);
        break;
    default:
        break;
    }

    rotMatrix.setData(mData);
    return rotMatrix;
}

static Matrix Scaling(const Vector& v)
{

    Matrix scalingMatrix = Identity(4,4,0);
    auto mData = scalingMatrix.getData();

    //! scaling matrix unchanging
    mData[0][0] = v.x;  
    mData[1][1] = v.y;  
    mData[2][2] = v.z;  
    mData[3][3] = v.w;  

    scalingMatrix.setData(mData);
    return scalingMatrix;

}
Matrix Matrix::Transpose()
{
    int nrows = this->nRows();
    int ncols = this->nCols();
    Matrix res = Matrix(nrows, ncols, 0);
    std::vector<std::vector<double>> data(nrows, std::vector <double> (ncols, 0));

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < ncols; i++)
        for (int j = 0; j < nrows; j++)
            data[i][j] = this->data[j][i];

    this->data = data;
    return *this;
}
Matrix submatrix(const Matrix &m, int row, int col)
{   
    vector<vector<double>> d = m.getData();
    int subi = 0;
    for (int i = 0; i < m.nRows(); i++) {
        int subj = 0;
        if (i == row) continue;
        for (int j = 0; j < 4; j++) {
            if (j == col) continue;
            double val = d[i][j];
            d[subi][subj] = val;
            subj++;
        }
        subi++;
    }
    Matrix result = Matrix(m.nRows()-1, m.nCols()-1, d);
    return result;
}

double minor(const Matrix &m, int row, int col)
{   
    return submatrix(m, row, col).Detriment();
}
double cofactor(const Matrix &m, int row, int col)
{
    double miner = minor(m, row, col);
    return (row + col) % 2 == 0 ? miner : -miner;
}
double Matrix::Detriment()
{   
    double determinent = 0;
    int ncols = this->nCols();
    int nrows = this->nRows();
    
    vector<vector<double>> data = this->getData();
    // cout << "num rows: " << nrows << '\n';
    // cout << "num rows: " << ncols << '\n';

    if (ncols == 2 && nrows == 2) {
        return (data[0][0] * data[1][1]) - (data[1][0] * data[0][1]);
    } else {
        for (int i = 0; i < ncols; i++) 
            determinent += cofactor(*this, 0, i) * data[0][i];
    }
    return determinent;
}

bool Matrix::canInvert() {return true ? this->Detriment() != 0 : false; }

Matrix Matrix::Inverse()
{      
    int ncols = this->nCols();
    int nrows = this->nRows();
    vector<vector<double>> data = this->getData();
    if (this->canInvert() == false){
        throw invalid_argument("The matrix is not invertable and has a determinent of 0.");
    }
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++)
        {
            double c = cofactor(*this, i, j);
            data[j][i] = double(c / this->Detriment()); 
        }
    }
    return Matrix(ncols, nrows, data);
}

void Matrix::print() const
{   
    cout << '\n';
    int nrows = this->mRows;
    int ncols = this->mCols;

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < nrows; i++) {
        cout << "{";
        for (int j = 0; j <ncols; j++)
        {
            std::cout << std::fixed;
            cout << ' ' <<  std::setprecision(6) << this->data[i][j] << ' ';
        }
        cout << "}\n";
    }
    cout << '\n';
}