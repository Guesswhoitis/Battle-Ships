#include "Main.hpp"



class renderer{


private:

    SDL_Window *mainWindow;
    SDL_Renderer *renderer;
    SDL_Texture *crossTexture;
    SDL_Texture *circleTexture;

public:
    void start(Tile (&board)[10][10]){
        
        mainWindow = SDL_CreateWindow("Main Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);

        if (mainWindow == nullptr) std::cout << "window was not created" << std::endl;

        renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);

        if (renderer == nullptr) std::cout << "renderer was not created" << std::endl;

        crossTexture = IMG_LoadTexture(renderer, "Textures/cross.png");

        if (crossTexture == nullptr) std::cout << "crossTexture was not created" << std::endl;

        circleTexture = IMG_LoadTexture(renderer, "Textures/circle.png");

        if (circleTexture == nullptr) std::cout << "circleTexture was not created" << std::endl;

        
    }

    void renderBoard(Tile (&board)[10][10]){
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        //std::cout << "about to loop boi" << std::endl;
    
        for(int i =0; i< 10; i++){
            for(int j=0; j < 10; j++){

                SDL_Texture* texture = IMG_LoadTexture(renderer, board[i][j].getTexture().c_str());
                SDL_RenderCopy(renderer,texture,nullptr,&board[i][j].getTileRect());
                
            }
        }
        //std::cout << "looped boi" << std::endl;
        
        SDL_RenderPresent(renderer);
    }

    void doGarbageClear(){

    }


};
