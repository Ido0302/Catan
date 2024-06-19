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

#include "DevelopmentCard.hpp"
#include "Knight.hpp"
#include "VictoryPoint.hpp"
#include "ProgressCard.hpp"

class Player;
using namespace std;

class Catan{
    private:
        vector<Player*> players;
        vector<DevelopmentCard*> cards;

    public:
        size_t currentTurn;
        int mostKnights;


    Catan(Player* p1, Player* p2, Player* p3);
    vector<Player*> getPlayers();
    vector<DevelopmentCard*> getCards();
    Board getBoard();

    size_t maxAge(vector<Player*> p);
    void chooseFirstPlayer();
    void printPlayers();

    void shareResources(vector<Player*>& p, int rollNumber); 
    void giveBackResources(vector<Player*>& p);
    
    void endTurn(vector<Player*> p);
    void gameWinner(Player* p);
    
    void clearCatan();
};

#endif
