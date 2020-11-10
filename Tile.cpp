#include "Main.hpp"

int Tile::getX(){
    return x;
}

int Tile::getY(){
    return y;
}

SDL_Texture* Tile::getTexture(){
    return texture;
}

bool Tile::isShip(){
    return false;
}