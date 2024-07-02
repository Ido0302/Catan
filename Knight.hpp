#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <memory>

#include "DevelopmentCard.hpp"
#include "Player.hpp"

class Player;

using namespace std;

class Knight : public DevelopmentCard
{
public:
    Knight();
    string getDevelopmentType() override;
    void playCard(vector<Player *>& p, size_t i, Board& b) override;
};

#endif