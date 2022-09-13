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

#ifndef _INCL_GUARD
#define _INCL_GUARD
#endif

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 550
#define PI M_PI

#define _USE_MATH_DEFINES

using namespace std;
using namespace std::chrono;

struct Projectile {
    Vector* point;
    Vector* velocity;
};

struct Origin{
    int x;
    int y;
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
    
template<typename T>
inline bool isinf(T value) {
    return std::numeric_limits<T>::has_infinity &&
        value == std::numeric_limits<T>::infinity();
}

int originNormal(int x, int y){
    int newX = 0;
    newX = SCREEN_WIDTH - x;
}

template <class T>
std::vector <std::vector<T>> MultiplyM(std::vector <std::vector<T>> &a, std::vector <std::vector<T>> &b)
{
    const int n = a.size();     // a rows 
    const int m = a[0].size();  // a cols
    const int p = b[0].size();  // b cols

    std::vector <std::vector<T>> c(n, std::vector<T>(p, 0));
    for (auto j = 0; j < p; ++j)
    {
        for (auto k = 0; k < m; ++k)
        {
            for (auto i = 0; i < n; ++i)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main(int argc, char** argv){

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

    // SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
    //             SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
    //             SDL_RenderDrawLine(renderer, 340, 240, 320, 200);

    // up is - down is +
    Vector origin = Vector(450,0,275,1); //p(0,0,0)
    cout << "\n\nThe clock origin is located at: (x,y)=" << "(" << origin.x << "," << 
        " " << origin.y << ")\n\n";
    SDL_RenderDrawPoint(renderer, origin.x, origin.z);


    //12 Oclock code and 6y
    int TweleveY = int(origin.z - int(0.25 * SCREEN_HEIGHT));
    cout << "Tweleve y value is: " << int(TweleveY) << '\n';
    Vector hourTwelevePos = Vector(450,0,TweleveY,1);
    // SDL_RenderDrawPoint(renderer,hourTwelevePos.x, hourTwelevePos.z);
    cout << "\nTweleve O'clock located at [x,y]= " << "(" << hourTwelevePos.x << ", " << hourTwelevePos.z << ")\n";
   // hourTwelevePos.print();

    int sixY = int(origin.z + int(0.25 * SCREEN_HEIGHT));
    cout << "six y value is: " << int(sixY) << '\n';
    Vector hoursixPos = Vector(450,0,sixY,1);
    // SDL_RenderDrawPoint(renderer,hoursixPos.x, hoursixPos.z);
    cout << "\n6 O'clock located at [x,y]= " << "(" << hoursixPos.x << ", " << hoursixPos.z << ")\n\n";
   // hourTwelevePos.print();

    //1 Oclock code




    Matrix ra1 = Rotation(3*PI/6, RotY);
    Vector res1 = ra1 * hourTwelevePos;
    res1.x = res1.x * 0.25 + origin.x;
    res1.z = res1.z * 0.25 + origin.z;
    SDL_RenderDrawPoint(renderer,res1.x, res1.z);


    Matrix ra2 = Rotation(2*PI/6, RotY);
    Vector res2 = ra2 * hourTwelevePos;
    res2.x = res2.x * 0.25 + origin.x;
    res2.z = res2.z * 0.25 + origin.z;
    SDL_RenderDrawPoint(renderer,res2.x, res2.z);

    Matrix ra3 = Rotation(PI/6, RotY);
    Vector res3 = ra3 * hourTwelevePos;
    res3.x = res3.x * 0.25 + origin.x;
    res3.z = res3.z * 0.25 + origin.z;
    SDL_RenderDrawPoint(renderer,res3.x, res3.z);

    Matrix ra4 = Rotation(4*PI/6, RotY);
    Vector res4 = ra4 * hourTwelevePos;
    res4.x = res4.x * 0.25 + origin.x;
    res4.z = res4.z * 0.25 + origin.z;
    SDL_RenderDrawPoint(renderer,res4.x, res4.z);

    Matrix ra5 = Rotation(5*PI/6, RotY);
    Vector res5 = ra5 * hourTwelevePos;
    res5.x = res5.x * 0.25 + origin.x;
    res5.z = res5.z * 0.25 + origin.z;
    SDL_RenderDrawPoint(renderer,res5.x, res5.z);

    Matrix ra6 = Rotation(6*PI/6, RotY);
    Vector res6 = ra6 * hourTwelevePos;
    res6.x = res6.x * 0.25 + origin.x;
    res6.z = res6.z * 0.25 + origin.z;
    SDL_RenderDrawPoint(renderer,res6.x, res6.z);

    Matrix ra7 = Rotation(7*PI/6, RotY);
    Vector res7 = ra7 * hourTwelevePos;
    res7.x = res7.x * 0.25 + origin.x;
    res7.z = res7.z * 0.25 + origin.z;
    SDL_RenderDrawPoint(renderer,res7.x, res7.z);

    Matrix ra8 = Rotation(8*PI/6, RotY);
    Vector res8 = ra8 * hourTwelevePos;
    res8.x = res8.x * 0.25 + origin.x;
    res8.z = res8.z * 0.25 + origin.z;
    SDL_RenderDrawPoint(renderer,res8.x, res8.z);

    Matrix ra9 = Rotation(9*PI/6, RotY);
    Vector res9 = ra9 * hourTwelevePos;
    res9.x = res9.x * 0.25 + origin.x;
    res9.z = res9.z * 0.25 + origin.z;
    SDL_RenderDrawPoint(renderer,res9.x, res9.z);

    Matrix ra10 = Rotation(10*PI/6, RotY);
    Vector res10 = ra10 * hourTwelevePos;
    res10.x = res10.x * 0.25 + origin.x;
    res10.z = res10.z * 0.25 + origin.z;
    SDL_RenderDrawPoint(renderer,res10.x, res10.z);

    Matrix ra11 = Rotation(11*PI/6, RotY);
    Vector res11 = ra11 * hourTwelevePos;
    res11.x = res11.x * 0.25 + origin.x;
    res11.z = res11.z * 0.25 + origin.z;
    SDL_RenderDrawPoint(renderer,res11.x, res11.z);

    Matrix ra12 = Rotation(12*PI/6, RotY);
    Vector res12 = ra12 * hourTwelevePos;
    res12.x = res12.x * 0.25 + origin.x;
    res12.z = res12.z * 0.25 + origin.z;
    SDL_RenderDrawPoint(renderer,res12.x, res12.z);




    SDL_Surface *sshot = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_WIDTH, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    SDL_SaveBMP(sshot, "ss.bmp");
    SDL_FreeSurface(sshot);
    
    return 0;
    auto stop = high_resolution_clock::now();  
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "\nTime taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}

