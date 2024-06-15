#ifndef CATAN_HPP
#define CATAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tile.hpp"
#include "Board.hpp"
#include "Player.hpp"

class Player;
using namespace std;

class Catan{
    private:
        vector<Player*> players;
    public:
        size_t currentTurn;


    Catan(Player* p1, Player* p2, Player* p3);
    vector<Player*> getPlayers();
    size_t maxAge(vector<Player*> p);
    void chooseFirstPlayer();
    void printPlayers();
    Board getBoard();

    void shareResources(vector<Player*>& p, int rollNumber); 
    void giveBackResources(vector<Player*>& p);
    void endTurn();
  
};

#endif
