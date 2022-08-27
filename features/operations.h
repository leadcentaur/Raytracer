#include <cmath>
#include <iostream>
#include "assert.h"
#include <vector>
#include <tuple>
#include <chrono>
#include <algorithm>
#include <functional> 

using namespace std;

static const float EPSILON = 0.00001;
static const int VEC_FLAG = 0;
static const int POINT_FLAG = 1;

class Vector {
    public:
        float x, y, z, w;

        Vector(float px=0.0, float py=0.0, float pz=0.0, float pw=0.0) : x(px), y(py), z(pz), w(pw)  {}
        
        bool equal(float a, float b) {return fabs(a - b) < EPSILON;}

        float dot(const Vector& a) 
        { 
            return this->x * a.x + this->y * a.y + this->z * a.z + this->w * a.w; 
        }
        
        inline void normalize() 
        { 
            float ivm = 1 / this->magnitude(); 
            this->x*ivm; this->y*ivm; this->z*ivm; this->w*ivm; 
        }

        inline void cross() 
        { 
            float ivm = 1 / this->magnitude(); this->x*ivm; this->y*ivm; this->z*ivm; this->w*ivm; 
        }

        inline void toInt();
        void print() const;

        //arithmetic operations vectors
        Vector& operator=(const Vector& a);
        Vector& operator+=(const Vector& a);
        Vector& operator-=(const Vector& a);
        
        Vector operator+(const Vector& a) const;
        Vector operator-(const Vector& a) const;
        Vector& operator*=(const float a);
        Vector operator*(const float a) const;
        float operator*(const Vector& a) const;
        Vector& operator/=(const float a);

        float magnitude();
        float length();
	    Vector cross(const Vector& a);
};

float Vector::magnitude() { return sqrt((*this)*(*this)); }

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

Vector& Vector::operator*=(const float a) {
    this->x*=a;
    this->y*=a;
    this->z*=a;
    this->w*=a;

    return *this;
}

Vector Vector::operator*(const float a) const {
    Vector res(*this);
    res*=a;

    return res;
}

float Vector::operator*(const Vector& a) const {
    float dot=0.0;	

    dot+=this->x*a.x;
    dot+=this->y*a.y;
    dot+=this->z*a.z;
    dot+=this->w*a.w;

    return dot;
}

Vector& Vector::operator/=(const float a) {
    this->x/=a;
    this->y/=a;
    this->z/=a;
    this->w/=a;

    return *this;
}