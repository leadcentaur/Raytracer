
#ifndef _INCL_GUARD_LIGHT
#define _INCL_GUARD_LIGHT


class Light {
    private:
        Color intensity;
        Vector positon;
    public:
        
        Light(Vector p, Color i) : intensity(i), positon(p) {}

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

Color lighting(Material m, Vector point, Light light_source, Vector eye, Vector normal){
    Color intensity = light_source.getIntensity();
    Color diffuse;
    Color specular;

    Color effective_color = intensity * m.color;
    Vector light_v = (light_source.getPosition() -  point).normalize();
    Color ambient = effective_color * m.ambient;

    int light_dot_normal = Vector::dot(light_v, normal);

    if (light_dot_normal < 0){
        Color diffuse = Color(0,0,0);
        Color specular = Color(0,0,0);
    } else {
        Color diffuse = effective_color * m.diffusel * light_dot_normal;
    }

    //Will need a function that sets light v to negative
    Vector reflectv = reflect(light_v, normal);
    int reflect_dot_eye = Vector::dot(reflectv, eye);
    if (reflect_dot_eye <= 0){
        Color specular = Color(0,0,0);
    } else {
        double factor = std::pow(reflect_dot_eye, m.shininess);
        Color intensity = light_source.getIntensity();
        Color specular = intensity * m.specular * factor;
    }

    return ambient + diffuse + specular;
}

#endif


