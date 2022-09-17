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

template <class T>
vector<int> aggregatePoints( std::initializer_list<T> list )
{   
    vector<int> iPoints;
    for( auto elem : list )
    {
        iPoints.push_back(elem[0].t);
        iPoints.push_back(elem[1].t);
    }
    return iPoints;
}

struct Intersection
{
    int t;
    Sphere sphere;
};

struct Intersections 
{
    vector<vector<Intersection>> is;
};

void Sphere::setOrigin(Vector origin)
{ 
    this->origin = origin; 
}

Vector Sphere::getOrigin()
{ 
    return this->origin; 
}

void Ray::setDirection(Vector dir)
{ 
    this->direction = dir; 
}

Vector Ray::getOrigin()
{ 
    return this->origin; 
}

Vector Ray::getDirection()
{ 
    return this->direction; 
}

int Sphere::getSphereID() 
{ 
    return this->sphereID; 
}

bool isEqual(double a, double b) {return std::abs(a - b) <= EPSILON * std::abs(a); }

vector<Intersection> Intersect(Sphere s, Ray r)
{   
    int sphereRadius = 1;

    Vector rayOrigin = r.getOrigin();
    Vector sphereOrigin = s.getOrigin();
    Vector rayDireciton = r.getDirection();
    
    Vector sphereToRay = rayOrigin - sphereOrigin;
    double a = Vector::dot(rayDireciton, rayDireciton);
    double b = Vector::dot(r.getDirection(), sphereToRay) * 2;

    // I think the -1 needs ot be changed to the spehre radii
    double c = Vector::dot(sphereToRay, sphereToRay) - 1;
    double discriminant = pow(b,2) - 4 * a * c;
    if (discriminant > -1.0 && discriminant < 1.0){
        discriminant = 0;
    }
    if (discriminant < 0) {
        cout << "The ray misses the sphere.";
        return {};
    }

    double t1 = (-b - sqrt(discriminant)) / (2*a);
    double t2 = (-b + sqrt(discriminant)) / (2*a);

    Intersection iSectA, iSectB;
    iSectA.sphere = s, iSectB.sphere = s;
    iSectA.t = t1, iSectB.t = t2;

    return vector<Intersection>{iSectA,iSectB};
}


Intersection hit(Intersections isx)
{   
    int lowest = isx.is[0][0].t;


    for(int i = 0; i < isx.is.size(); i++){
        for (int j = 0; j < isx.is.size();j++) {
            if (isx.is[i][j].t < lowest) {
                lowest = isx.is[i][j].t;
                return isx.is[i][j];
            }
        }
    }
    return isx.is[0][0];
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
