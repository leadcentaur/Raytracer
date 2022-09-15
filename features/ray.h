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
    Vector position(double t);
    static int Sphere();

};

int Sphere()
{   
    srand (time(NULL));
    int sphereID = rand() % 2147483627;
    cout << "Sphere id is: " << sphereID;
    return 1;
}

Vector Ray::position(double t)
{   
    return this->origin + this->direction * t;
}

#endif
