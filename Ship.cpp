#include "Main.hpp"


void Ship::addShipTile(ShipTile* s){
    shipTiles.insert(s);
}

bool Ship::shipDead(){
    
    for(ShipTile* s : shipTiles){
        if(!(s->isBlownUp())){
            return false;
        }
    }

    return true;
}