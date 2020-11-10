#include "Main.hpp"

Tile::Tile(int x2, int y2){
    x = x2;
    y = y2;

    tileRect.x = x2*100;
    tileRect.y =y2*100;
    tileRect.w =100;
    tileRect.h =100;
}



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

SDL_Rect Tile::getTileRect(){
    return tileRect;
}