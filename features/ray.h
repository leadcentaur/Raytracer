#ifndef _INCL_GUARD_RAY
#define _INCL_GUARD_RAY

#define PI M_PI

using namespace std;

class Ray {
    private:
        Vector origin;
        Vector direction;
    public:
    Ray(Vector origin, Vector direction) : origin(origin), direction(direction) {}
    inline Vector position(size_t t);
};

Vector Ray::position(size_t t)
{   
    return this->origin + this->direction * t;
}

#endif
