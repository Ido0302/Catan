//ID 207826694

#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <cstdlib> // For rand() and srand()
#include <ctime>   //for time
#include <limits>

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Tile.hpp"
#include "Board.hpp"

#include "Person.hpp"
#include "Player.hpp"
#include "Catan.hpp"

#include "DevelopmentCard.hpp"
#include "Knight.hpp"
#include "VictoryPoint.hpp"
#include "ProgressCard.hpp"

using namespace std;

int main()
{

    // create 3 players
    Player p1("Amit", 25, red);
    Player p2("Yossi", 21, orange);
    Player p3("Dana", 18, white);

    Catan catan(&p1, &p2, &p3); // create catan with 3 players

    // print description about players
    cout << "The Players are: " << endl;
    catan.printPlayers();

    // Starting of the game. Every player places two settlements and two roads.
    catan.chooseFirstPlayer(); // sort the players in vector according their age. should print the name of the starting player, assume it is Amit.

    vector<Player *> p = catan.getPlayers(); // return vector of players

    Board board = catan.getBoard(); // get the board of the game.
    //board.printBoard();

    p[0]->placeSettlement(3, board);
    p[0]->placeRoad(3, 9, board);

    p[0]->placeSettlement(24, board); // 24
    p[0]->placeRoad(24, 30, board);   // 24 30

    // Amit placed his settlements and roads

    p[1]->placeSettlement(13, board);
    p[1]->placeRoad(13, 8, board);

    p[1]->placeSettlement(42, board);
    p[1]->placeRoad(42, 41, board);

    // Yossi placed his settlements and roads

    p[2]->placeSettlement(21, board);
    p[2]->placeRoad(21, 22, board);

    try
    {
        p[2]->placeSettlement(42, board); // Dana tries to place a settlement in the same location as Yossi.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    p[2]->placeSettlement(33, board);
    p[2]->placeRoad(33, 16, board);

    // Dana placed her settlements and roads

    cout << "Let's start the game!" << endl
         << endl;

    // Use the current time as the seed for demonstration purposes
    srand(static_cast<unsigned int>(time(0)));

    p[0]->rollDice(catan, p); // p1 roll dice
    catan.endTurn(p);         // p1 end turn

    p[1]->rollDice(catan, p);
    catan.endTurn(p);

    p[2]->rollDice(catan, p);
    catan.endTurn(p);

    try
    {
        p[1]->rollDice(catan, p); // p2 tries to roll the dice again, but it's not his turn.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    for (size_t i = 0; i < p.size(); i++)
    {
        p[i]->rollDice(catan, p);
        catan.endTurn(p);
    }

    p[0]->rollDice(catan, p);
    p[0]->trade(p[1], "iron", 2, "lumber", 3); // p1 trade with p2
    catan.endTurn(p);

    p[1]->rollDice(catan, p);
    p[1]->buildRoad(41, 40, board); // p2 build road
    catan.endTurn(p);

    p[2]->rollDice(catan, p);
    p[2]->buildRoad(16, 15, board); // p3 build road
    catan.endTurn(p);

    for (size_t i = 0; i < p.size(); i++)
    {
        p[i]->rollDice(catan, p);
        catan.endTurn(p);
    }

    p[0]->rollDice(catan, p);
    p[0]->buildCity(3, board); // p1 build city
    catan.endTurn(p);

    p[1]->rollDice(catan, p);
    p[1]->trade(p[2], "wool", 1, "wheat", 1); // p2 trade with p3
    p[1]->buildSettlement(40, board);         // p2 build settlement
    catan.endTurn(p);

    p[2]->buyDevelopmentCard(catan, p, board); // p3 buy development card - is not can roll dice
    catan.endTurn(p);

    p[0]->rollDice(catan, p);
    p[0]->buildRoad(30, 44, board);
    catan.endTurn(p);

    p[1]->buyDevelopmentCard(catan, p, board);
    catan.endTurn(p);

    p[2]->rollDice(catan, p);
    p[2]->buildSettlement(15, board);
    catan.endTurn(p);

    cout << p[0]->getName() << " has: " << p[0]->getPoints() << " points" << endl;
    cout << p[1]->getName() << " has: " << p[1]->getPoints() << " points" << endl;
    cout << p[2]->getName() << " has: " << p[2]->getPoints() << " points" << endl;
    
    board.clearBoard(); //free all memory was allocate in board
    catan.clearCatan(); //free all memory was allocate in catan
    
    return 0;
}
