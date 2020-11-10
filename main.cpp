#include "Main.hpp"
#include "renderer.cpp"



class ahhhhh{
    
    Tile board[10][10];
    
    renderer r;


    
public:

    ahhhhh(){

    }


    void gameIntit(){
        for(int i =0; i< (sizeof board / sizeof board[0]); i++){
            for(int j=0; j < (sizeof board[0] / sizeof(int)); j++){
                board[i][j] = Tile(i,j);
            }
        }

    }


    void gameRun(){

        r.start(&board);
    }


};

int main(){
    SDL_Init(SDL_INIT_EVERYTHING);
    
    ahhhhh m;

    std::cout << "gg" << std::endl;
    m.gameIntit();
    std::cout << "gg2" << std::endl;
    m.gameRun();

    
    return 0;
};

