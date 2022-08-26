#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <chrono>
#include "features/operations.h"
#include "features/display.h"
#include "features/color.h"
#include "features/matrix.h"
#include <Windows.h>

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

Projectile* tick(Environment* env, Projectile* proj) {
    *proj->point = *proj->point + *proj->velocity;
    *proj->velocity = *proj->velocity + *env->gravity + *env->wind;
    return proj;
}
       

int Display::initDisplay() {

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        std::cout << "Starting sdlc";
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("SLD test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(!window){
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }

    //create a new matrix

    vector<vector<int>> v2 = {
        {2,5,1},
        {6,7,1},
        {1,8,1}
    };

    
   std::vector<vector<int>> v1 = {
        {1,2,1},
        {0,1,0},
        {2,3,4}
    };

    vector<vector<int>> v3 = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

    for (int i = 0; i < 3; i++){ 
        for (int j = 0; j < 3; j++) {
            v3[i][j] = (v1[0][0] * v2[0][0]) + (v1[0][1] * v2[1][0]) + (v1[0][2] * v2[2][0]);
        }
    }

    cout << v3[0][0] << ' ' << v3[0][1] << ' ' << v3[0][2] << '\n';
    cout << v3[1][0] << ' ' << v3[1][1] << ' ' << v3[1][2] << '\n';
    cout << v3[2][0] << ' ' << v3[2][1] << ' ' << v3[2][2] << '\n';


    return 0;
}

int main(int argc, char** argv){

    Display display;
    display.initDisplay();
}

