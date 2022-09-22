#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
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

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600
#define PI M_PI

#define _USE_MATH_DEFINES

using namespace std;
using namespace std::chrono;



int main(int argc, char *argv[]){ 

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


    Sphere s1 = Sphere();

    Ray rayA = Ray(Vector(0,0,0), Vector(0,0,1));
    vector<Intersection> ic1 = Intersect(s1, rayA);
    cout << "Intersections for Sphere " << ic1[0].sphere.getSphereID() << " are: " << ic1[0].t << "  and " << ic1[1].t << '\n';

    Ray rayB = Ray(Vector(0,0,-5), Vector(0,0,1));
    vector<Intersection> ic2 = Intersect(s1, rayB);
    cout << "Intersections for Sphere " << ic2[0].sphere.getSphereID() << " are: " << ic2[0].t << "  and " << ic2[1].t << '\n';

    //Each call to the intersection function returners two
    // or possibly one intersection record output as per ic1[0] and [1] index referencing.
    Ray rayC = Ray(Vector(0,0,-5), Vector(0,0,1));
    vector<Intersection> ic3 = Intersect(s1, rayC);

    Intersection i1 = ic1[0];
    i1.t = -1;

    Intersection i2 = ic1[1];
    i2.t = -1;
    
    // Intersection i3 = ic2[0];
    // i3.t = -3;
   
    // Intersection i4 = ic2[1];
    // i4.t = 2;

    vector<Intersection> results = aggregatePoints({i2, i1});

    cout << "Front: " << results.front().t << '\n';
    cout << "Back: " << results.back().t << "\n\n";

    for (auto x : results){
        cout << x.t << '\n';
    }

    Intersection val = hit(results);
    cout << "\nHit returned: " << val.t << "\n";
    //cout << "The lowest result: " << results[0].t;

    // vector<Intersection> i1 = {a1,a2};

    // vector<vector<Intersection>> w = {i1};
    // iSections.is = w;

    // cout << "The lowest intersection object has a t value of: " << val.t << '\n';



    // for (int x = 0; x < points.size(); x++){
    //     cout << points[x] << '\n';
    // }




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

