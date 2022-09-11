// #include <iostream>
// #include <SDL2/SDL.h>
// #include <stdio.h>
// #include <iostream>
// #include <iomanip>

// #define SCREEN_WIDTH 1280 
// #define SCREEN_HEIGHT 720

// class Display {
//     public:
//         int initDisplay();
// };

// int Display::initDisplay() {

//     // Initialize rendering with error handling
//     if(SDL_Init(SDL_INIT_VIDEO) < 0){
//         printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
//         std::cout << "Starting sdlc";
//         return 1;
//     }

//     //Create the window 
//     SDL_Window *window = SDL_CreateWindow("SLD test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
//     if(!window){
//         printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
//         return 1;
//     }

//     //Create the renderer
//     SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     if(!renderer){
//         printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
//         return 1;
//     }

//     /*
//         Need to flip the y vlaue from positive to negative,
//         this is because the origin starts at 0,0 which is in the top left of the screen.
//         there for to increases the height of the projectile we substract.
//     */

//     SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
//     SDL_RenderClear(renderer);

//     SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
//     SDL_RenderDrawPoint(renderer, 1, 550);


//     SDL_Surface *sshot = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_WIDTH, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
//     SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
//     SDL_SaveBMP(sshot, "ss.bmp");
//     SDL_FreeSurface(sshot);
//     //     // <-- Render the Graphics here -->
//     return 0;
// }