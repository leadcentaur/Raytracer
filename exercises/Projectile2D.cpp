#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <chrono>
#include "features/vec.h"
#include "features/display.h"
#include "features/color.h"
#include <Windows.h>
#include <thread>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 550

struct Projectile {
    Vector* point;
    Vector* velocity;
};

struct Environment {
    Vector* gravity;
    Vector* wind;
};

//tick function used to calculate state of projectile
Projectile* tick(Environment* env, Projectile* proj) {
    *proj->point = *proj->point + *proj->velocity;
    *proj->velocity = *proj->velocity + *env->gravity + *env->wind;
    return proj;
}
       

int Display::initDisplay() {

    // Initialize rendering with error handling
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

    //Instantiate projectile objects
    Projectile* projectile = new Projectile;
    Environment* environment = new Environment;

    //projectile->point = new Vector(0.0, 1, 0.0);
    projectile->point = new Vector(0, 550, 0.0);

    /*
        Need to flip the y vlaue from positive to negative,
        this is because the origin starts at 0,0 which is in the top left of the screen.
        there for to increases the height of the projectile we substract.
    */
    projectile->velocity = new Vector(11.5, -9.6, 0);
    *projectile->velocity * 51.25; 

    environment->gravity = new Vector(0, 0.25, 0);
    environment->wind = new Vector(-0.01, 0, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(renderer, 1, 550);

    for (int x = 0; x <= 300; x++) {
        Projectile* pa = tick(environment, projectile);

        //
        cout << "(" << int(pa->point->x) << ", " << int(pa->point->y) << ")" << "\n";
        SDL_RenderDrawPoint(renderer,int(pa->point->x) , int(pa->point->y));
        if (pa->point->y >= 550) {
            break;
        } 
    }

    SDL_Surface *sshot = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_WIDTH, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    SDL_SaveBMP(sshot, "screenshot.bmp");
    SDL_FreeSurface(sshot);

    //     // <-- Render the Graphics here -->
    return 0;
}