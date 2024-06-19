#ifndef DevelopmentCard_HPP
#define DevelopmentCard_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <memory>

#include "Player.hpp"

using namespace std;

class Player;

//"abstract" class with purning functions play and get type
class DevelopmentCard 
{
private:
    string developmentType;

public:
    ~DevelopmentCard() = default;
    virtual string getDevelopmentType() = 0;
    virtual void playCard(vector<Player*>& p, size_t i, Board& b) = 0;
};

#endif