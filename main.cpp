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

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 100

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

    /*
        Need to flip the y vlaue from positive to negative,
        this is because the origin starts at 0,0 which is in the top left of the screen.
        there for to increases the height of the projectile we substract.
    */

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

    //Draw the sphere

    //start the ray at z = -5
    Vector rayOrigin = (SCREEN_WIDTH/2, SCREEN_HEIGHT/2, -5, 1);
    SDL_RenderDrawPoint(renderer, screen_width_half, screen_height_half);
    
    //put the wall at z = 10
    int wall_z = 10;
    int wall_size = 7;
    int half = SCREEN_WIDTH / 2;
    int pixel_size = wall_size / SCREEN_WIDTH;

    Sphere sphere = Sphere();
    for (int y = 0; y < SCREEN_WIDTH; y++){
        int world_y = half - pixel_size * y;
        for (int x = 0; x < SCREEN_WIDTH; x++){
            int world_x = -half + pixel_size * x;
            Vector position = Vector(world_x, world_y, wall_z);

            Ray r = Ray(rayOrigin, (position - rayOrigin).normalize());
            vector<Intersection> xs = Intersect(sphere, r);

        }
    }

    SDL_Surface *sshot = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_WIDTH, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    SDL_SaveBMP(sshot, "clockface.bmp");
    SDL_FreeSurface(sshot);
    
    return 0;
    auto stop = high_resolution_clock::now();  
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "\nTime taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}

