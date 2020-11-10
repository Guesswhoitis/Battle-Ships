#ifndef EXISTS
#define EXISTS
#define SDL_MAIN_HANDLED
#include <iostream>
#include "SDL2-2.0.12/include/SDL_main.h"
#include "SDL2-2.0.12/include/SDL.h"
#include "SDL2-2.0.12/include/SDL_image.h"
#include <stdio.h> 
#include <winsock.h>
#include <string.h> 
#include <set>


class Tile{

public:
    Tile(){};
    Tile(int x,int y);
    int getX();
    int getY();
    SDL_Texture* getTexture();
    bool isShip();
    SDL_Rect getTileRect();
private:
    int x;
    int y;
    SDL_Texture* texture;
    SDL_Rect tileRect;
};


class Water:public Tile{

public:

    
private:


};


class ShipTile:public Tile{

public:
    bool isBlownUp();
    std::string getName();
    bool shipDead();
private:
    bool blownUp;
    std::set<ShipTile*> shipTiles;
    std::string name;
};







#endif