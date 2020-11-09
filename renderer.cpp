#include "main.h"


class renderer{


private:

    SDL_Window *mainWindow;
    SDL_Renderer *renderer;
    SDL_Texture *crossTexture;

public:
    int start(){
        mainWindow = SDL_CreateWindow("Main Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);

        if (mainWindow == nullptr) std::cout << "window was not created" << std::endl;

        renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);

        if (renderer == nullptr) std::cout << "renderer was not created" << std::endl;

        crossTexture = IMG_LoadTexture(renderer, "Textures/cross.png");

        if (crossTexture == nullptr) std::cout << "crossTexture was not created" << std::endl;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    int doGarbageClear(){

    }


};
