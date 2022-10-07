
#ifndef _INCL_GUARD_LIGHT
#define _INCL_GUARD_LIGHT



class Light {
    private:
        Color intensity;
        Vector positon;
    public:
        
        Light(Color i, Vector p) : intensity(i), positon(p) {}

        void setIntensity(Color intensity);


        Color getIntensity();

        void setPosition(Vector position);
        Vector getPosition();
};

void Light::setIntensity(Color intensity)
{
    this->intensity = intensity;
}

void Light::setPosition(Vector position)
{
    this->positon = position;
}

Color Light::getIntensity()
{
    return this->intensity;
}

Vector Light::getPosition()
{
    return this->positon;
}

#endif


