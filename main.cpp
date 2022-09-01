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

#define _USE_MATH_DEFINES

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

    //point multiplied by translation
    Vector tranformation = Vector(5,-3,2,1);
    Vector point = Vector(-3, 4, 5, 1);
    Matrix tM = Translation(tranformation);
    Vector pXtform = tM * point;
    tM.print();

    //point multiplied by inverse of trans
    Matrix inv = tM.Inverse();
    Vector res = inv * point;
    //res.print();

    //scaling by a vector or a point
    Vector scaleVec = Vector(2, 3, 4, 1);
    Vector p0 = Vector(-4, 6, 8, 1);
    Matrix scaleMatrix = Scaling(scaleVec);
    Vector pXsm = scaleMatrix * p0;
    //pXsm.print();

    //scaling inverse
    Matrix invScalemat = scaleMatrix.Inverse();
    Vector iXv = invScalemat * p0;
    //iXv.print();

    //reflection example
    Matrix scalingMatrix = Scaling(Vector(-1, 1, 1, 0));
    //the point to reflect
    Vector reflectPoint = Vector(2,3,4,1);
    Vector reflectionVec = scalingMatrix * reflectPoint;
    //gets reflected on the xAxis
    reflectionVec.print();
    
   
    //write a submatrix function
    int row_index = 0;
    int col_index = 1;

    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
 
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    Display display;
    display.initDisplay();
}

