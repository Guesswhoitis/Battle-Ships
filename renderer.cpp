#include "Main.hpp"



class renderer{


private:

    SDL_Window *mainWindow;
    SDL_Renderer *renderer;
    
    std::unordered_map<int,SDL_Texture*> mapOfTextures;

public:
    void start(Tile* (&board)[10][10]){
        
        mainWindow = SDL_CreateWindow("Main Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1500, 1000, 0);

        if (mainWindow == nullptr) std::cout << "window was not created" << std::endl;

        renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);

        if (renderer == nullptr) std::cout << "renderer was not created" << std::endl;


        mapOfTextures[2] = loadTexture("Textures/destroyer.png");
        mapOfTextures[3] = loadTexture("Textures/submarine.png");
        mapOfTextures[4] = loadTexture("Textures/battleShip.png");
        mapOfTextures[5] = loadTexture("Textures/aircraftCarrier.png");

 

        
    }

    void renderBoard(Tile* (&board)[10][10]){
        SDL_SetRenderDrawColor(renderer, 3, 163, 255, 255);
        SDL_RenderClear(renderer);

        //std::cout << "about to loop boi" << std::endl;

    
        for(int i =0; i< 10; i++){
            for(int j=0; j < 10; j++){

                if(board[i][j]->getTexture() == nullptr){
                    std::cout << "fucked" << std::endl;
                }

                if((board[i][j]->getTileSplitter()).x == -1){
                     SDL_RenderCopy(renderer,board[i][j]->getTexture(),nullptr,&(board[i][j]->getTileRect()));
                }else{
                     SDL_RenderCopy(renderer,board[i][j]->getTexture(),&(board[i][j]->getTileSplitter()),&(board[i][j]->getTileRect()));
                }

               
                
            }
        }
        //std::cout << "looped boi" << std::endl;
        
       
    }

    void renderSideBar(int selection, std::string texture){
        SDL_Rect sideBarSelection;

        sideBarSelection.x = 1000;
        sideBarSelection.y = 100;
        sideBarSelection.w = (selection*100);
        sideBarSelection.h = 100;

        SDL_RenderCopy(renderer,mapOfTextures[selection],nullptr,&sideBarSelection);

        
    }

    void renderFinish(){
        SDL_RenderPresent(renderer);
    }

    SDL_Texture* loadTexture(std::string textureDir){
        SDL_Texture* texture2 =  IMG_LoadTexture(renderer, textureDir.c_str());
        return texture2;
    }

    void doGarbageClear(){

    }


};
