#include "Main.hpp"



class renderer{


private:

    SDL_Window *mainWindow;
    SDL_Renderer *renderer;
    SDL_Texture *crossTexture;
    SDL_Texture *circleTexture;

public:
    void start(Tile (*board)[10][10]){
        mainWindow = SDL_CreateWindow("Main Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);

        if (mainWindow == nullptr) std::cout << "window was not created" << std::endl;

        renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);

        if (renderer == nullptr) std::cout << "renderer was not created" << std::endl;

        crossTexture = IMG_LoadTexture(renderer, "Textures/cross.png");

        if (crossTexture == nullptr) std::cout << "crossTexture was not created" << std::endl;

        circleTexture = IMG_LoadTexture(renderer, "Textures/circle.png");

        if (circleTexture == nullptr) std::cout << "circleTexture was not created" << std::endl;

        //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
       // SDL_RenderClear(renderer);

        /*
        for(int i =0; i< (sizeof board / sizeof board[0]); i++){
            for(int j=0; j < (sizeof board[0] / sizeof(int)); j++){
               SDL_RenderCopy(renderer,circleTexture,&board[i][j]->getTileRect(),nullptr);
            }
        }
        */
        SDL_RenderCopy(renderer,circleTexture,nullptr,&board[0][0]->getTileRect());
        printf("%d %d %d %d",board[0][0]->getTileRect().x, board[0][0]->getTileRect().y, board[0][0]->getTileRect().w,board[0][0]->getTileRect().h);
        SDL_RenderPresent(renderer);
        SDL_Delay(100000);
    }

    void doGarbageClear(){

    }


};
