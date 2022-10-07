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
#include "features/light.h"

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

    Sphere s1 = Sphere();
    reflect(Vector(0,-1,0), Vector(sqrt(2)/2,sqrt(2)/2,0)).print();
    
    s1.setMaterial({3,3,3,3});
    cout << s1.material.ambient;


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

