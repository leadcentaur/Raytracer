#ifndef _INCL_GUARD_RAY
#define _INCL_GUARD_RAY

#define PI M_PI

using namespace std;

class Sphere {
    private:
        int sphereID;
        Vector origin;
        
    public:
        Sphere(Vector origin = Vector(0,0,0,1)) {setSphereID();}
        int getSphereID();
        void setSphereID();
        void setOrigin(Vector origin);
        Vector getOrigin();
};

class Ray {
    private:
        Vector origin;
        Vector direction;
        friend Sphere;
    public:
        Ray(Vector origin, Vector direction) : origin(origin), direction(direction) {}
        Vector position(double t);
        void setDirection(Vector dir);
        Vector getDirection();
        Vector getOrigin();
        static int Sphere();
};

void Sphere::setOrigin(Vector origin){ this->origin = origin; }

Vector Sphere::getOrigin() { return this->origin; }

void Ray::setDirection(Vector dir){ this->direction = dir; }

Vector Ray::getOrigin() { return this->origin; }

Vector Ray::getDirection() { return this->direction; }

int Sphere::getSphereID() { return this->sphereID; }

//the meat and potatoes
vector<double> Intersect(Sphere s, Ray r)
{   
    int sphereRadius = 1;
    Vector rayOrigin = r.getOrigin();
    Vector sphereOrigin = s.getOrigin();
    Vector rayDireciton = r.getDirection();
    
    Vector sphereToRay = rayOrigin - sphereOrigin;
    double a = Vector::dot(rayDireciton, rayDireciton);
    double b = Vector::dot(r.getDirection(), sphereToRay) * 2;
    double c = Vector::dot(sphereToRay, sphereToRay) - 1;

    double discriminant = pow(b,2) - 4 * a * c;
    if (discriminant < 0) {
        exit(1);
    }
    double t1 = (-1*b - sqrt(discriminant)) / (2*a);
    double t2 = (-1*b + sqrt(discriminant)) / (2*a);
    return {abs(t1), abs(t2)};

}

void Sphere::setSphereID()
{
    srand(time(NULL));
    this->sphereID = rand() % 2147483627;
}

Vector Ray::position(double t)
{   
    return this->origin + this->direction * t;
}

#endif
