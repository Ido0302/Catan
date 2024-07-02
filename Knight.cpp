#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>

#include "DevelopmentCard.hpp"
#include "Knight.hpp"
#include "Player.hpp"

using namespace std;

Knight::Knight(){}

string Knight::getDevelopmentType()
{
    return "knight";
}

/**
 * get the players, the number of player who using card and the board.
   add to player who use the card knight.
 */
void Knight::playCard(vector<Player*>& p, size_t i, Board& b)
{
    cout << p[i]->getName() << " reach the development card " <<  this->getDevelopmentType()  << endl;  
    p[i]->addKnights();
}

