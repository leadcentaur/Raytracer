#include <SDL2/SDL.h>
#include <iostream>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 550

class Utils {
    public:
        void screenCapture(const char* str, SDL_Renderer *renderer);
};

void Utils::screenCapture(const char* capture_name, SDL_Renderer *renderer) {
    SDL_Surface *sshot = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_WIDTH, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    SDL_SaveBMP(sshot, capture_name);
    SDL_FreeSurface(sshot);
}