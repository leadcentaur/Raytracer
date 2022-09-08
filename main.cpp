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

#define _USE_MATH_DEFINES
#define P_2 1.570796

using namespace std;
using namespace std::chrono;

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

    vector<vector<int>> a = {
        {2,5,1},
        {6,7,1},
        {1,8,1}
    };

    return 0;
}

template<typename T>
inline bool isinf(T value) {
    return std::numeric_limits<T>::has_infinity &&
        value == std::numeric_limits<T>::infinity();
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
    vector<vector<int>> z = {
        {1,2,6},
        {-5,8,-4},
        {2,6,4}
    };

    vector<vector<double>> a = {
        {8,-5,9,2},
        {7,5,6,1},
        {-6,0,9,6},
        {-3,0,-9,-4}
    };

    vector<vector<double>> b = {
        {9,3,0,9},
        {-5,-2,-6,-3},
        {-4,9,6,4},
        {-7,6,6,2}
    };

     vector<vector<double>> dm = {
        {1,5},
        {-3,2},
    }; 

    Vector p1 = Vector(2,3,4,POINT_FLAG);
    Matrix hQY = Rotation(M_PI / 4, Axis::RotZ);
    Vector r4 = hQY * p1;

    // Transvection(Vector(2,3,4,1), 0,0,0,0,0,1).print();
    Vector(2,3,4,1).Transvection(0,0,0,0,0,1).print();

    auto stop = high_resolution_clock::now();  
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "\nTime taken by function: "
         << duration.count() << " microseconds" << endl;
    // Display display;
    // display.initDisplay();
}

