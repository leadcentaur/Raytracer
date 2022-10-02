#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <limits>
#include <iostream>
#include <iomanip>
#include <map>
#include <chrono>
#include "features/vec.h"
#include "features/display.h"
#include "features/color.h"
#include "features/matrix.h"
#include "features/ray.h"

#include "util/fpclass.h"
#include <Windows.h>
#include <stdio.h>

#define SCREEN_WIDTH 200
#define SCREEN_HEIGHT 200

#define PI M_PI

#define _USE_MATH_DEFINES

using namespace std;
using namespace std::chrono;



int main(int argc, char *argv[]){ 

    int screen_width_half = int(SCREEN_WIDTH / 2);
    int screen_height_half = int(SCREEN_HEIGHT / 2);
    auto start = high_resolution_clock::now();

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        std::cout << "Starting sdlc";
        return 1;
    }

    //Create the window 
    SDL_Window *window = SDL_CreateWindow("SLD test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(!window){
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    //Create the renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(renderer,0,0);
    //Draw the sphere

    //start the ray at z = -5
    Sphere s = Sphere();
    Vector rayOrigin = Vector(0, 0, -5, 1);

    // s.normal_at(Vector(1,0,0,1)).print();
    // s.normal_at(Vector(0,1,0,1)).print();
    // s.normal_at(Vector(0,0,1,1)).print();
    // s.normal_at(Vector(sqrt(3)/3,sqrt(3)/3,sqrt(3)/3,1)).print();

    Sphere s1 = Sphere();
    s1.setTransform(Translation(Vector(0,1,0,1)));
    s1.normal_at(Vector(0,1.70711,-0.70711,1)).print();

    Sphere s2 = Sphere();
    Matrix m = Scaling(Vector(1,0.5,1,1)) * Rotation(PI/5, Axis::RotZ);
    s2.setTransform(m);
    s2.normal_at(Vector(0,sqrt(2)/2,-sqrt(2)/2,1)).print();

    double wall_Z = 10;
    double wall_size = 3.0;
    double pixel_size = wall_size / SCREEN_WIDTH;
    double half = wall_size / 2;

    // Matrix m = Shearing(1,0,0,0,0,0) * Scaling(Vector(0.5,1,1,1));
    // s.setTransform(m);
    // for (int y = 0; y <= SCREEN_WIDTH; y++) {
    //     double world_y = half - pixel_size * y;

    //     for (int x = 0; x  <= SCREEN_WIDTH; x++){
    //         double world_x = -half + pixel_size * x;
    //         Vector position = Vector(world_x, world_y, wall_Z);
    //         Ray r = Ray(rayOrigin, (position-rayOrigin).normalize());

    //         vector<Intersection> xs = Intersect(s, r);
    //         if (hit(xs).t != INT32_MIN){
    //             SDL_RenderDrawPoint(renderer, x, y);
    //         }
    //     }
    //     cout << '\n';
    // }
    


    SDL_Surface *sshot = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_WIDTH, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    SDL_SaveBMP(sshot, "sphereSilhouette.bmp");
    SDL_FreeSurface(sshot);
    
    return 0;
    auto stop = high_resolution_clock::now();  
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "\nTime taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}

