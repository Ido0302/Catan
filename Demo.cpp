/**
 * Demo file for Ex3.
 *
 */
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
    //catan.printPlayers();

    // Starting of the game. Every player places two settlements and two roads.

    //catan.chooseFirstPlayer(); // sort the players in vector according their age. should print the name of the starting player, assume it is Amit.

    vector<Player *> p = catan.getPlayers(); // return vector of players

    Board board = catan.getBoard(); // get the board of the game.
                                    // board.printBoard();

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

    p[0]->rollDice(catan, p); // Lets say it's print 4. Then, p1 gets ore from the mountations.
    catan.endTurn();

    p[1]->rollDice(catan, p); // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    catan.endTurn();  // p2 ends his turn.

    p[2]->rollDice(catan, p); // Lets say it's print 3. Then, p3 gets wheat from the Agricultural landand Ore from the Mountains, p1 gets wheat from the Agricultural Land.
    catan.endTurn();  // p3 ends his turn.

    try
    {
        p[1]->rollDice(catan, p); // p2 tries to roll the dice again, but it's not his turn.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    for (size_t i = 0; i < 3; i++)
    {
        p[i]->rollDice(catan, p);
        catan.endTurn();
    }

    for (size_t i = 0; i < 3; i++)
    {
        p[i]->rollDice(catan, p);
        catan.endTurn();
    }


    p[0]->rollDice(catan,p);
    p[0]->trade(p[1], "iron", 2, "lumber", 3);
    catan.endTurn();

    p[1]->rollDice(catan,p);
    p[1]->buildRoad(41, 40, board);
    catan.endTurn();

    p[2]->rollDice(catan,p);
    p[2]->buildRoad(21, 4, board);
    catan.endTurn();

    p[0]->rollDice(catan, p);
    p[0]->buildCity(3, board);
    catan.endTurn();

    p[1]->rollDice(catan,p);
    p[1]->trade(p[2], "wool", 1, "wheat", 1);
    p[1]->buildSettlement(40, board);
    catan.endTurn();

    p[2]->rollDice(catan, p);
    //p[2]->buyDevelopCard;
    catan.endTurn();

    p[0]->printResources();
    p[1]->printResources();
    p[2]->printResources();
    
    
    
    /*
            p1.rollDice();                       // Lets say it's print 6. Then, p1 gets bricks from the hills.
            p1.trade(p2, "wood", "brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
            p1.endTurn();                        // p1 ends his turn.

            p2.rollDice();           // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
            p2.buyDevelopmentCard(); // p2 buys a development card. Lets say it is a bonus points card.
            p2.endTurn();            // p2 ends his turn.

            p1.printPoints(); // p1 has 2 points because it has two settelments.
            p2.printPoints(); // p2 has 3 points because it has two settelments and a bonus points card.
            p3.printPoints(); // p3 has 2 points because it has two settelments.

            catan.printWinner(); // Should print None because no player reached 10 points.
            */
    return 0;
}