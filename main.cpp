#include "Main.hpp"
#include "renderer.cpp"



class ahhhhh{
    
    Tile board[10][10];
    
    renderer r;


    
public:

    ahhhhh(){

    }


    void gameIntit(){
        for(int i =0; i< 10; i++){
            for(int j=0; j < 10; j++){
                board[i][j] = Tile(i,j);
            }
        }

    }


    void gameRun(){

        r.start(board);
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

