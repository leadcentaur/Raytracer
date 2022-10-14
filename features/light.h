
#ifndef _INCL_GUARD_LIGHT
#define _INCL_GUARD_LIGHT


class Light {
    private:
        Color intensity;
        Vector positon;
    public:
        
        Light(Vector positon, Color intensity) : positon(positon), intensity(intensity) {}

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

Color lighting(Material m, Light light, Vector point, Vector eyev, Vector normalv){
    Color diffuse;
    Color specular;
    Color intensity = light.getIntensity();
    Vector position = light.getPosition();

    Color effective_color = m.color * intensity;
    Vector lightv = (position - point).normalize();
    Color ambient = effective_color * m.ambient;
    double light_dot_normal = Vector::dot(lightv, normalv);
    if (light_dot_normal < 0){
        diffuse = Color(1,1,1);
        specular = Color(1,1,1);
    } else {
        diffuse = effective_color * m.diffuse * light_dot_normal;
        Vector reflectv = reflect(Vector(-lightv.x, -lightv.y, -lightv.z, lightv.w), normalv);
        double reflect_dot_eye = Vector::dot(reflectv, eyev);
        if(reflect_dot_eye <= 0){
            specular = Color(1,1,1);
        } else {
            double factor = std::pow(reflect_dot_eye, m.shininess);
            specular = light.getIntensity() * m.specular * factor;
        }
    }
    return ambient + diffuse + specular;
}

#endif


