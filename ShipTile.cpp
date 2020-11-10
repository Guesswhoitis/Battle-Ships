#include "Main.hpp"

bool ShipTile::isBlownUp(){
    return blownUp;
}

std::string ShipTile::getName(){
    return name;
}

bool ShipTile::shipDead(){
    
    for(ShipTile* s : shipTiles){
        if(!(s->blownUp)){
            return false;
        }
    }

    return true;
}
