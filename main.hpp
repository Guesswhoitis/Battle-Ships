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
#include <unordered_map>


class Tile{
public:
    Tile(){};
    Tile(int x,int y,SDL_Texture*,int,int);
    int getX();
    int getY();
    SDL_Texture* getTexture();
    bool isShip();
    SDL_Rect getTileRect();
    SDL_Rect getTileSplitter();
private:
    int x;
    int y;
    SDL_Texture* texture;
    SDL_Rect tileRect;
    SDL_Rect tileSplitter;
};


class Water:public Tile{

public:

    
private:


};


class ShipTile:public Tile{

public:
    ShipTile(int,int,SDL_Texture*,int,int);
    bool isBlownUp();
    std::string getName();
private:
    bool blownUp;
    std::string name;

};


class Ship{
public:
    Ship(SDL_Texture*,int,int);
    bool shipDead();
    void addShipTile(ShipTile*);
    void placeShipTiles(Tile* (&board)[10][10],int,int);
private:
    std::set<ShipTile*> shipTiles;
    int rotate;
    int length;
    SDL_Texture* mainTexture;
    
};

class Player{
public:
    Tile* playersBoard[10][10];
    Tile* hitBoard[10][10];

    void addShip(Ship*);
    std::set<Ship*> getShips();
private:
    std::set<Ship*> playerShips;
   
};





#endif