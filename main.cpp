#include "Main.hpp"
#include "renderer.cpp"



class ahhhhh{
    
    Player p1;

    Player p2;
    
    
    renderer r;

    SDL_Texture* waterTile;

    int rotate = 1;

    int select =5;

    
public:

 
    void gameIntit(){

        r.start(board);
        waterTile = r.loadTexture("Textures/waterTile.png");

        for(int i =0; i< 10; i++){
            for(int j=0; j < 10; j++){
                board[i][j] = new Tile(i,j,waterTile,-1,0);
            }
        }
    }


    void gameRun(){

       

        SDL_Event event;
        while(SDL_WaitEvent(&event)){
            if(event.type == SDL_QUIT) break;

            if(event.type == SDL_MOUSEBUTTONDOWN){

                
                //std::cout<<"1"<<std::endl;
                Ship s = Ship(r.loadTexture(stringTexture(select)),rotate,select);
                //std::cout<<"2"<<std::endl;
                s.placeShipTiles(board, event.motion.x /100, event.motion.y /100);
                //std::cout<<"3"<<std::endl;
             }

              

                if(event.key.keysym.sym == SDLK_r && event.type == SDL_KEYDOWN){
                    
                   rotate = (rotate * -1);
                   //std::cout<<rotate<<std::endl;
                   
                }

                if(event.key.keysym.sym == SDLK_5){
                    select = 5;
                }

                 if(event.key.keysym.sym == SDLK_4){
                    select = 4;
                }

                if(event.key.keysym.sym == SDLK_3){
                    select = 3;
                }

                if(event.key.keysym.sym == SDLK_2){
                    select = 2;
                }

                
            

            r.renderBoard(board);
            r.renderSideBar(select,stringTexture(select));
            r.renderFinish();
        }
    }


    std::string stringTexture(int select){
        

        if(rotate == -1){
            if(select == 5){
                return "Textures/aircraftCarrierR.png";
            }else if(select ==4){
                return "Textures/battleShipR.png";
            }if(select ==3){
                return "Textures/submarineR.png";
            }if(select ==2){
                return "Textures/destroyerR.png";
            }   
        }else{
            if(select == 5){
                return "Textures/aircraftCarrier.png";
            }else if(select ==4){
                return "Textures/battleShip.png";
            }if(select ==3){
                return "Textures/submarine.png";
            }if(select ==2){
                return "Textures/destroyer.png";
            }  
        }
    }



};

int main(){
    SDL_Init(SDL_INIT_EVERYTHING);
    
    ahhhhh m;


    //std::cout << "gg" << std::endl;
    m.gameIntit();
    //std::cout << "gg2" << std::endl;
    m.gameRun();

    
    return 0;
};

