#include "Main.hpp"

Tile::Tile(int x2, int y2, SDL_Texture* newTexture,int x2g,int r){
    x = x2;
    y = y2;

    tileRect.x = x2*100;
    tileRect.y =y2*100;
    tileRect.w =100;
    tileRect.h =100;

    texture = newTexture;

    if(x2g != -1){
        std::cout<<"2.2.1"<<std::endl;
        if(r == 1){
            std::cout<<"2.2.2"<<std::endl;
            tileSplitter.x = (x2g *100);
            tileSplitter.y =0;
            tileSplitter.w =100;
            tileSplitter.h =100;
        }else{
            tileSplitter.x = 0;
            tileSplitter.y =(x2g *100);
            tileSplitter.w =100;
            tileSplitter.h =100;
        }
        std::cout<<"2.2.3"<<std::endl;
        
    }else{
        tileSplitter.x = -1;
    }
    

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

SDL_Rect Tile::getTileSplitter(){
    return tileSplitter;
}