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
    vector<vector<int>> a = {
        {1,2,6},
        {-5,8,-4},
        {2,6,4}
    };

    vector<vector<int>> b = {
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4}
    };


    
    cout << '\n';
    
    // Matrix m1 = Matrix(3,3, a);
    // cout << "\nThe determinent of m1 is: " << m1.Detriment() << '\n';

    Matrix m2 = Matrix(4,4, b);
    // cout << "The determinent of m2 is: " << m2.Detriment() << '\n';
    m2.Transpose();
    m2.print();

    cout << '\n';
    
   
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

