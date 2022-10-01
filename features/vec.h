#ifndef _INCL_GUARD_VEC
#define _INCL_GUARD_VEC

#include <cmath>
#include <iostream>
#include "assert.h"
#include <vector>
#include <tuple>
#include <chrono>
#include <algorithm>
#include <functional>

using namespace std;

static const double EPSILON = 0.0001;
static const int VEC_FLAG = 0;
static const int POINT_FLAG = 1;
static const int TUPLE_SIZE = 4;

#ifndef VEC_H
#define VEC_H

class Vector {
    public:
        double x, y, z, w;

        Vector(double px=0, double py=0, double pz=0, double pw=0) : x(px), y(py), z(pz), w(pw)  {}
    

        double dot(const Vector& a) 
        { 
            return double(this->x * a.x + this->y * a.y + this->z * a.z + this->w * a.w);
        }

        static double dot(const Vector& a, const Vector& b) 
        { 
            return double(a.x * b.x + a.y * b.y + a.z * b.z + a.w * a.w); 
        }
        
        inline Vector normalize() 
        { 
            double ivm = 1 / this->magnitude(); 
            this->x*ivm; this->y*ivm; this->z*ivm; this->w*ivm;
            return *this;
        }

        inline void cross() 
        { 
            double ivm = 1 / this->magnitude(); this->x*ivm; this->y*ivm; this->z*ivm; this->w*ivm; 
        }

        inline void toInt();
        void print() const;

        //arithmetic operations vectors
        Vector& operator=(const Vector& a);
        Vector& operator+=(const Vector& a);
        Vector& operator-=(const Vector& a);
        
        Vector operator+(const Vector& a) const;
        Vector operator-(const Vector& a) const;
        Vector& operator*=(const double a);
        Vector operator*(const double a) const;
        double operator*(const Vector& a) const;
        Vector& operator/=(const double a);

        double magnitude();
        double length();

	    Vector cross(const Vector& a);
        Vector ToVec3(vector<int> &v);
        vector<int> FromVec3();
        Vector Transvection(double Xy, double Xz, double Yx, double Yz, double Zx, double Zy);
        friend class Matrix;

};

#endif /* GRANDPARENT_H */

double Vector::magnitude() { return sqrt((*this)*(*this)); }


Vector Vector::Transvection(double Xy, double Xz, double Yx, double Yz, double Zx, double Zy)
{   
    auto x = this->x;
    auto y = this->y;
    auto z = this->z;

    double _Xy = Xy * y;
    x += _Xy;
    double _Xz = Xz * z;
    x += _Xz;
    double _Yz = Yz * z;
    y += _Yz;
    double _Yx = Yx * x;
    y += _Yx; 
    double _Zx = Zx * x;
    z += _Zx;
    double _Zy = Zy * y;
    z += _Zy;

    this->x = x;
    this->y = y;
    this->z = z;

    return *this;
}

Vector Vector::ToVec3(vector<int> &v)
{
    if (v.size() > TUPLE_SIZE) throw invalid_argument("Vec3 must have a length of 3 (x, y, z, w)");
    return Vector(v[0], v[1], v[2], v[3]);
}

vector<int> Vector::FromVec3() {
    return vector<int>{int(this->x), int(this->y), int(this->z), int(this->w)};
}

void Vector::toInt() {
    this->x = int(this->x);
    this->y = int(this->y);
    this->z = int(this->z);
    this->w = int(this->w);
}

void Vector::print() const {
	printf("(%lf, %lf, %lf, %lf)\n", this->x,this->y,
		this->z,this->w);
}

Vector& Vector::operator=(const Vector& a) {
    this->x=a.x;
    this->y=a.y;
    this->z=a.z;
    this->w=a.w;

    return *this;
}

Vector& Vector::operator+=(const Vector& a) {
    this->x+=a.x;
    this->y+=a.y;
    this->z+=a.z;
    this->w+=a.w;

    return *this;
}

Vector& Vector::operator-=(const Vector& a) {
    this->x-=a.x;
    this->y-=a.y;
    this->z-=a.z;
    this->w-=a.w;

    return *this;
}

Vector Vector::operator+(const Vector& a) const {
    Vector res(*this);
    res+=a;

    return res;
}

Vector Vector::operator-(const Vector& a) const { 
    Vector res(*this);
    res-=a;

    return res;
}

Vector& Vector::operator*=(const double a) {
    this->x*=a;
    this->y*=a;
    this->z*=a;
    this->w*=a;

    return *this;
}

Vector Vector::operator*(const double a) const {
    Vector res(*this);
    res*=a;

    return res;
}

double Vector::operator*(const Vector& a) const {
    double dot=0.0;	

    dot+=this->x*a.x;
    dot+=this->y*a.y;
    dot+=this->z*a.z;
    dot+=this->w*a.w;

    return dot;
}

Vector& Vector::operator/=(const double a) {
    this->x/=a;
    this->y/=a;
    this->z/=a;
    this->w/=a;

    return *this;
}

#endif