#include "Main.hpp"



Ship::Ship(SDL_Texture* newTexture,int newRotate,int length2){
    mainTexture = newTexture;
    rotate =newRotate;
    length = length2;
}

void Ship::addShipTile(ShipTile* s){
    shipTiles.insert(s);
}

void Ship::placeShipTiles(Tile* (&board)[10][10],int x,int y){

    if(rotate == 1){
        std::cout<<"2.1"<<std::endl;
        for(int i =0; i<length; i++){
            std::cout<<"2.2"<<std::endl;
            delete board[x+i][y];
            board[x+i][y] = new ShipTile(x+i, y, mainTexture,i,rotate);
            std::cout<<"2.3"<<std::endl;
        }
    }else{
        for(int i =0; i<length; i++){
            delete board[x][y+i];
            board[x][y+i] = new ShipTile(x, y+i, mainTexture,i,rotate);
        }
    }
   

}

bool Ship::shipDead(){
    
    for(ShipTile* s : shipTiles){
        if(!(s->isBlownUp())){
            return false;
        }
    }

    return true;
}