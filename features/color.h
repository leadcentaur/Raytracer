#include <iostream>

class Color {
    public:
        float r, g, b;
        Color(float r=0.0, float g=0.0, float b=0.0) : r(r), g(g), b(b) {}
        
        Color& operator=(const Color& a);
        Color operator-(const Color& a) const;
        Color operator+(const Color& a) const;
        Color& operator-=(const Color& a);
        Color& operator+=(const Color& a);
        Color& operator*=(const float a);
        Color operator*(const float a) const;
        Color operator*(const Color& a) const;
    
        void print() const; 
        Color& hadmard_product(const Color& a, const Color& b) const; 
};

void Color::print() const {
	printf("(%lf, %lf, %lf)\n", this->r, this->g, this->b);
}

Color& Color::operator+=(const Color& a) {
    this->r+=a.r;
    this->g+=a.g;
    this->b+=a.b;

    return *this;
}

Color& Color::operator-=(const Color& a) {
    this->r-=a.r;
    this->g-=a.g;
    this->b-=a.b;

    return *this;
}

Color& Color::operator=(const Color& a) {
    this->r=a.r;
    this->g=a.g;
    this->b=a.b;
    return *this;
}

Color& Color::operator*=(const float a) {
    this->r*=a;
    this->g*=a;
    this->b*=a;

    return *this;
}

Color Color::operator*(const float a) const {
    Color res(*this);
    res*=a;
    return res;
}

Color Color::operator*(const Color& a) const {
    Color res(*this);
    res.r = res.r * a.r;	
    res.g = res.g * a.g;
    res.b = res.b * a.b;

    return res;
}

Color Color::operator+(const Color& a) const {
    Color res(*this);
    res+=a;

    return res;
}

Color Color::operator-(const Color& a) const { 
    Color res(*this);
    res-=a;

    return res;
}



