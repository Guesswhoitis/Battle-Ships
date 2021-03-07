#include "Main.hpp"


ShipTile::ShipTile(int x, int y, SDL_Texture* texture,int x2g, int r):Tile(x,y,texture,x2g,r){

    
}

bool ShipTile::isBlownUp(){
    return blownUp;
}

std::string ShipTile::getName(){
    return name;
}


