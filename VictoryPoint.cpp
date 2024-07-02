#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>


#include "DevelopmentCard.hpp"
#include "VictoryPoint.hpp"
#include "Player.hpp"

using namespace std;

VictoryPoint::VictoryPoint(){}

string VictoryPoint::getDevelopmentType()
{
    return "victory point";
}

/*
 * get the players, the number of player who using card and the board.
    add to player who use the card point.
*/
void VictoryPoint::playCard(vector<Player*>& p, size_t i, Board& b) 
{
    cout << p[i]->getName() << " reach the development card " <<  this->getDevelopmentType()  << endl;  
    p[i]->setPoints(1);
}
