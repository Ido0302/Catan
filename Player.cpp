#include <iostream>
#include <stdexcept>
#include <vector>

#include "Player.hpp"

using namespace std;

Player::Player(std::string name)
{
    this->name = name;
}

string Player::getName()
{
    return this->name;
}

Player::~Player() {}
