#include <cmath>
#include <iostream>
#include "assert.h"
#include <vector>
#include <tuple>
#include <chrono>
#include <algorithm>
#include <functional> 

template< typename T, 
typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class Matrix {
    private:
        size_t rows;
        size_t columns;
        vector<T> data;

        Matrix& Matrix(size_t rs, size_t, cs, const Vector<T> &d) : rows(rs), columns(cs) data(data) {
            if (data.size() != rows.col)
                throw invalid_argument("Matrix provided must have equal dimensions")
        }

        Matrix operator+(const &Matrix m) const;
        Matrix operatior*(const &Matrix m) const;
};
