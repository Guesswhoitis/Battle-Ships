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
    Tile(int x,int y,std::string);
    int getX();
    int getY();
    std::string getTexture();
    bool isShip();
    SDL_Rect getTileRect();
private:
    int x;
    int y;
    std::string textureDir;
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
private:
    bool blownUp;
    std::string name;
};


class Ship{
public:
    bool shipDead();
    void addShipTile(ShipTile*);
private:
    std::set<ShipTile*> shipTiles;
};





#endif