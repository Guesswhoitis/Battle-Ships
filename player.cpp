#include "main.hpp"

void Player::addShip(Ship* s){
    playerShips.insert(s);
}

std::set<Ship*> Player::getShips(){
    return playerShips;
}