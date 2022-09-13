#include <SDL2/SDL.h>
#include <iostream>
#include <iomanip>
#include <chrono>
#include "features/vec.h"
#include "features/display.h"
#include "features/color.h"
#include "features/matrix.h"
#include "util/fpclass.h"
#include <Windows.h>
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 550

int ClockFaces() {

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

    Vector origin = Vector(SCREEN_WIDTH/2,0,SCREEN_HEIGHT/2,1); //p(0,0,0)
    cout << "\n\nThe clock origin is located at: (x,y)=" << "(" << origin.x << "," << 
        " " << origin.y << ")\n\n";
    SDL_RenderDrawPoint(renderer, origin.x, origin.z);

    //Precompute the tweleve o'clock position
    int TweleveY = int(origin.z - int(0.25 * SCREEN_HEIGHT));
    Vector hourTwelevePos = Vector(450,0,TweleveY,1);
    cout << "\nTweleve O'clock located at [x,y]= " << "(" << hourTwelevePos.x << ", " << hourTwelevePos.z << ")\n";

    for (int i = 1; i <= 12; i++){

        Matrix rotMatrix = Rotation(i*PI/6, RotY);
        Vector computed_point = rotMatrix * hourTwelevePos;
        computed_point.x = computed_point.x * 0.25 + origin.x;
        computed_point.z = computed_point.z * 0.25 + origin.z;
    
        SDL_RenderDrawPoint(renderer,computed_point.x, computed_point.z);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(renderer, 1, 550);

    SDL_Surface *sshot = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_WIDTH, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    SDL_SaveBMP(sshot, "ss.bmp");
    SDL_FreeSurface(sshot);

    //     // <-- Render the Graphics here -->
    return 0;
}

// \   // SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
//     //             SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
//     //             SDL_RenderDrawLine(renderer, 340, 240, 320, 200);

//     // up is - down is +
//     Vector origin = Vector(SCREEN_WIDTH/2,0,SCREEN_HEIGHT/2,1); //p(0,0,0)
//     cout << "\n\nThe clock origin is located at: (x,y)=" << "(" << origin.x << "," << 
//         " " << origin.y << ")\n\n";
//     //SDL_RenderDrawPoint(renderer, origin.x, origin.z);


//     //12 Oclock code and 6y
//     int TweleveY = int(origin.z - int(0.25 * SCREEN_HEIGHT/2));
//     cout << "Tweleve y value is: " << int(TweleveY) << '\n';
//     Vector hourTwelevePos = Vector(SCREEN_WIDTH/2,0,TweleveY,1);
//     //SDL_RenderDrawPoint(renderer,hourTwelevePos.x, hourTwelevePos.z);
//     cout << "\nTweleve O'clock located at [x,y]= " << "(" << hourTwelevePos.x << ", " << hourTwelevePos.z << ")\n";
//    // hourTwelevePos.print();

//     for (int i = 1; i <= 12; i++){

//         Matrix rotMatrix = Rotation(i*PI/6, RotY);
//         Vector computed_point = rotMatrix * hourTwelevePos;
//         computed_point.x = computed_point.x * 0.25 + origin.x;
//         computed_point.z = computed_point.z * 0.25 + origin.z;
    
//         SDL_RenderDrawPoint(renderer,computed_point.x, computed_point.z);
//     }