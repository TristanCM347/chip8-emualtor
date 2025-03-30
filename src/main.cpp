#include <iostream>
#include "chip8.h"

#include "SDL2/SDL.h"

int main(int argc, char **argv) {
    if (argc <= 1)
    {
        std::cerr << "Must give path to ROM as arguement\n";
        exit(1);
    }

    Chip8 chip8 = Chip8();

    // set up SDL
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;

    const int height = 320;
    const int width = 640;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "Error in initialising SDL " << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow(
        "Chip-8 Emulator",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        width, height, SDL_WINDOW_SHOWN
    );
    if (window == nullptr) {
        std::cerr << "Error in creating window " << std::endl;
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr)
    {
        std::cerr << "Error in initializing rendering " << std::endl;
        exit(1);
    }
    SDL_RenderSetLogicalSize(renderer, width, height);

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 64, 32);
    if (texture == nullptr)
    {
        std::cerr << "Error in setting up texture " << SDL_GetError() << std::endl;
        exit(1);
    }

    return 0;
}