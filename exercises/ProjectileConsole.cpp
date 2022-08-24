#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "features/operations.h"
#include "features/display.h"

struct Projectile {
    Vector* point;
    Vector* velocity;
};

struct Environment {
    Vector* gravity;
    Vector* wind;
};

Projectile* tick(Environment* env, Projectile* proj) {

    *proj->point = *proj->point + *proj->velocity;
    *proj->velocity = *proj->velocity + *env->gravity + *env->wind;
    return proj;
}

void Projectile2DConsole() {
        //Testing type
        Projectile* projectile = new Projectile;
        Environment* environment = new Environment;

        projectile->point = new Vector(0.0, 1, 0.0);
        projectile->velocity = new Vector(1.5, 1, 0);

        environment->gravity = new Vector(0.0, -0.1, 0);
        environment->wind = new Vector(0, 0, 0);

        for (int i = 0; i <100; i++) {
            Projectile* pa = tick(environment, projectile);
            pa->point->print();
            if (pa->point->y <= 0.0) {
                cout << "Projectile hit the ground in " << i << " ticks.";
                break;
            }
        }
}
