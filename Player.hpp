#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Player
{
private:
    std::string name;

public:
    Player(std::string name);
    ~Player();

    std::string getName();
};

#endif