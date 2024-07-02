#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <cstdlib> // For rand() and srand()
#include <ctime>   //for time
#include <limits>

#include "doctest.h"

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

// srand(static_cast<unsigned int>(time(0)));

TEST_CASE("Vertices & Edges")
{
    Vertex v1(1);
    CHECK(v1.isEmpty() == true);
    v1.build();
    CHECK(v1.isEmpty() == false);

    Vertex v2(2);
    Edge e1(&v1, &v2);
    CHECK(e1.getV1() == v1.getVertex());
    CHECK(e1.getV2Address() == &v2);

    CHECK(e1.isEmpty() == true);
    e1.build();
    CHECK(e1.isEmpty() == false);

    Edge e2(&v2, &v1);
    CHECK(e2.isEqual(e1.getV1(), e1.getV2()) == true);
}

TEST_CASE("Tiles & Board")
{
    Board b;

    CHECK(b.findVertex(50) != NULL);
    CHECK(b.findVertex(100) == NULL);

    Tile t1 = b.getBoard()[0];
    Tile t2 = b.getBoard()[1];

    CHECK(t1.getJunctions()[2] == t2.getJunctions()[0]); // same vertex in different tiles

    int indexV = t1.getJunctions()[1]->getVertex(); // get index 1
    Vertex *v = b.findVertex(indexV);               // get the address of index 1
    CHECK(t1.foundVertex(v) == true);
    CHECK(t2.foundVertex(v) == false);
    CHECK(t1.getJunctions()[2] == b.findVertex(2));

    int roll = t1.getCircleNumber();
    vector<Tile> tiles = b.findTiles(roll);
    for (size_t i = 0; i < tiles.size(); i++)
    {
        CHECK(tiles[i].getCircleNumber() == roll);
    }
    tiles.clear();

    Edge *e = b.findEdge(2, 3);
    CHECK(e == t1.getLanes()[2]);
    CHECK(e == t2.getLanes()[5]);

    vector<Edge *> edges1 = b.edgesIntersection(e->getV1Address());
    vector<Edge *> edges2 = b.edgesIntersection(e->getV2Address());
    CHECK(edges1[0] == t1.getLanes()[1]);
    CHECK(edges1[1] == t1.getLanes()[2]);
    CHECK(edges2[0] == t2.getLanes()[5]);

    Vertex *u = e->getV1Address();
    tiles = b.tilesIntersection(u);
    for (size_t i = 0; i < tiles.size(); i++)
    {
        CHECK(tiles[i].foundVertex(u) == true);
    }

    Vertex *z = t1.getJunctions()[4];
    CHECK(b.edgesIntersection(z).size() == b.tilesIntersection(z).size());

    b.clearBoard();
}

TEST_CASE("Test sort player and find oldest")
{
    Player p1("p1", 10, red);
    Player p2("p2", 20, orange);
    Player p3("p3", 25, white);

    Catan game(&p1, &p2, &p3);
    vector<Player *> p = {&p1, &p2, &p3};

    int maxIndex = game.maxAge(p);
    CHECK(p[(size_t)maxIndex]->getAge() > p[0]->getAge());
    game.chooseFirstPlayer();
    CHECK(game.getPlayers()[0]->getAge() > game.getPlayers()[2]->getAge());

    game.clearCatan();
}

TEST_CASE("Test roll cube, roll dice, and endTurn")
{

    Player p1("p1", 10, red);
    Player p2("p2", 20, orange);
    Player p3("p3", 25, white);

    Catan game(&p1, &p2, &p3);
    vector<Player *> p = {&p1, &p2, &p3};

    for (size_t i = 0; i < 3; i++)
    {
        int rc = p1.rollCube();
        CHECK(rc > 0);
        CHECK(rc < 7);
    }
    game.chooseFirstPlayer();
    CHECK_NOTHROW(game.getPlayers()[0]->rollDice(game, p));
    game.endTurn(p);
    CHECK_THROWS(game.getPlayers()[0]->rollDice(game, p)); // p[0] try to roll again
    CHECK_NOTHROW(game.getPlayers()[1]->rollDice(game, p));

    CHECK(game.currentTurn < 3);
    game.endTurn(p);
    CHECK(game.currentTurn == 2);
    game.endTurn(p);
    CHECK(game.currentTurn == 0); // return to first player

    game.clearCatan();
}

TEST_CASE("Build & Place Settlements")
{

    Player p1("p1", 10, red);
    Player p2("p2", 20, orange);
    Player p3("p3", 25, white);

    Board b;

    int junction = 3;
    Vertex *v = b.findVertex(junction);
    p1.placeSettlement(junction, b); // build without pay resources
    CHECK(p1.getSettlements().size() == 1);
    CHECK(p1.getColor() == v->getColor());
    CHECK_FALSE(v->isEmpty());
    CHECK(p1.getPoints() == 1);

    CHECK_THROWS(p1.placeSettlement(junction, b)); // build again on 3
    junction = 100;
    CHECK_THROWS(p1.placeSettlement(junction, b)); // throw because junction not found
    junction = 4;
    CHECK_THROWS(p1.placeSettlement(junction, b)); // throw becuse distance rule

    junction = 5;
    p1.buildSettlement(junction, b);                            // build with pay resources,
    CHECK(b.findVertex(junction)->getColor() != p1.getColor()); // not enough resoueces
    p1.setResources(brick, 1);
    p1.setResources(lumber, 1);
    p1.setResources(wheat, 1);
    p1.setResources(wool, 1);
    p1.buildSettlement(junction, b);
    CHECK(b.findVertex(junction)->isEmpty() == false);
    CHECK(b.findVertex(junction)->getColor() == p1.getColor());

    // after build 2 settlements
    junction = 21;
    CHECK_FALSE(p1.isValidJunction(b.findVertex(junction), b)); // not roads leads to junction
    p1.placeRoad(3, 4, b);
    p1.placeRoad(4, 21, b);
    CHECK(p1.isValidJunction(b.findVertex(junction), b));

    b.clearBoard();
}

TEST_CASE("Build & Place Roads")
{

    Player p1("p1", 10, red);
    Player p2("p2", 20, orange);
    Player p3("p3", 25, white);

    Board b;

    int junction1 = 3;
    int junction2 = 9;
    Edge *e = b.findEdge(junction1, junction2);
    CHECK_THROWS(p1.placeRoad(junction1, junction2, b)); // build without pay resources. throw because not settlement/city on any edge's vertex
    p1.placeSettlement(junction1, b);
    CHECK_NOTHROW(p1.placeRoad(junction1, junction2, b));

    CHECK(p1.getRoads().size() == 1);
    CHECK(p1.getColor() == e->getColor());
    CHECK_FALSE(e->isEmpty());

    CHECK_THROWS(p1.placeRoad(junction1, junction2, b)); // throw because build again on (3,9)
    junction2 = 8;
    CHECK_THROWS(p1.placeRoad(junction1, junction2, b)); // throw because junction not found

    junction1 = 9;
    p1.buildRoad(junction1, junction2, b);                                // build with pay resources
    CHECK(b.findEdge(junction1, junction2)->getColor() != p1.getColor()); // not enough resoueces
    p1.setResources(brick, 1);
    p1.setResources(lumber, 1);
    p1.buildRoad(junction1, junction2, b);
    CHECK(p1.getResources()[brick] == 0);
    CHECK(b.findEdge(junction1, junction2)->isEmpty() == false);
    CHECK(b.findEdge(junction1, junction2)->getColor() == p1.getColor());

    junction1 = 19;
    junction2 = 20;
    CHECK_FALSE(p1.isValidLane(b.findEdge(junction1, junction2), b)); // not roads leads to lane
    p1.placeRoad(19, 9, b);
    CHECK(p1.isValidLane(b.findEdge(junction1, junction2), b));

    b.clearBoard();
}

TEST_CASE("Build & Place Cities")
{

    Player p1("p1", 10, red);
    Player p2("p2", 20, orange);
    Player p3("p3", 25, white);

    Board b;

    int junction = 3;
    p1.setResources(iron, 3);
    p1.setResources(wheat, 2);
    CHECK_THROWS(p1.buildCity(junction, b)); // not has settlement

    p1.placeSettlement(junction, b);
    CHECK_NOTHROW(p1.buildCity(junction, b));
    CHECK(p1.getSettlements().size() == 0);
    CHECK(p1.getCities().size() == 1);
    CHECK(p1.getPoints() == 2);

    b.clearBoard();
}

Player p1("p1", 10, red);
Player p2("p2", 20, orange);
Player p3("p3", 25, white);

Catan game(&p1, &p2, &p3);
vector<Player *> p = {&p1, &p2, &p3};
Board b = game.getBoard();

TEST_CASE("Resoueces")
{

    for (size_t i = 0; i < p1.getResources().size(); i++)
    {
        CHECK(p1.getResources()[i] == 0);
    }

    string resource = "iron";
    int r = p1.getResourceFromString(resource);
    p1.addResource(Land::Mountain);
    CHECK(p1.getResources()[(size_t)r] == 1);

    int add = 3;
    p1.setResources(wool, add);
    CHECK(p1.getResources()[wool] == add);

    int junction1 = 22; // intersection of tiles FiledX2, Foretst
    p1.placeSettlement(junction1, b);
    p1.getBeginnersResource(b);
    CHECK(p1.getResources()[lumber] == 1);
    CHECK(p1.getResources()[wheat] == 2);

    int junction2 = 5;  // Mountain(10), Wheat(12)
    int junction3 = 13; // Hill(10), Pature(4) and Forest(9)
    int roll = 10;
    p2.placeSettlement(junction2, b);
    p3.placeSettlement(junction3, b);
    game.shareResources(p, roll);
    CHECK(p2.getResources()[iron] == 1);
    CHECK(p[2]->getResources()[brick] == 1);

    p2.setResources(iron, 3);
    p2.setResources(wheat, 2);
    CHECK(p2.getResources()[wheat] == 2);
    p2.buildCity(junction2, b);
    CHECK(p2.getResources()[wheat] == 0);
    roll = 12;
    game.shareResources(p, roll);
    CHECK(p2.getResources()[wheat] == 2);

    int count1Before = 0;
    int count2Before = 0;
    for (size_t i = 0; i < p1.getResources().size(); i++)
    {
        p1.setResources(i, 1);
        p2.setResources(i, 2);
        count1Before++;
        count2Before += 2;
    }
    game.giveBackResources(p);
    int count1After = 0;
    int count2After = 0;
    for (size_t i = 0; i < p1.getResources().size(); i++)
    {
        count1After += p1.getResources()[i];
        count2After += p2.getResources()[i];
    }

    CHECK(count1After == count1Before);     // had more 7 resources
    CHECK(count2After == count2Before / 2); // had less 7 resources
}

TEST_CASE("Trade")
{
    cout << "*****It's test, choose Y *****" << endl;
    p[0]->trade(p[1], "lumber", 1, "brick", 1); // asume p2 agree (write Y)
    CHECK(p[0]->getResources()[brick] == 0);
    CHECK(p[1]->getResources()[brick] == 2);
    CHECK(p[0]->getResources()[lumber] == 2);
    CHECK(p[1]->getResources()[lumber] == 0);

    cout << "*****It's test, choose n *****" << endl;
    p[2]->trade(p[1], "iron", 1, "brick", 1); // assume p2 disagree (write n)
    CHECK(p[1]->getResources()[brick] == 2);
    CHECK(p[2]->getResources()[brick] == 1);
    CHECK(p[1]->getResources()[iron] == 1);
    CHECK(p[2]->getResources()[iron] == 0);

    p[1]->trade(p[0], "wool", 1, "wheat", 2); // p2 has not enough resources to give. nothig be change
    CHECK(p[0]->getResources()[wool] == 1);
    CHECK(p[1]->getResources()[wheat] == 1);

    p[1]->trade(p[0], "wool", 2, "wheat", 1); // p1 has not enough resources to give. nothig be change
    CHECK(p[0]->getResources()[wheat] == 1);
    CHECK(p[1]->getResources()[wool] == 1);
}

TEST_CASE("Knights & Largest Army")
{
    CHECK(p[0]->getKnights() == 0);
    p[0]->addKnights();
    CHECK(p[0]->getKnights() == 1);

    Knight k;
    k.playCard(p, 0, b);
    p[0]->reachLargestArmy(game, p); // has not enough knights. larges army yet false
    CHECK(p[0]->getKnights() == 2);
    CHECK(p[0]->hasLargestArmy() == false);
    CHECK(game.mostKnights == 0);

    k.playCard(p, 0, b);
    p[0]->reachLargestArmy(game, p);
    CHECK(p[0]->getKnights() == 3);
    CHECK(p[0]->hasLargestArmy() == true);
    CHECK(game.mostKnights == 3);

    for (size_t i = 0; i < 4; i++)
    {
        p[1]->addKnights();
    }

    p[1]->reachLargestArmy(game, p);
    CHECK(p[1]->hasLargestArmy() == true);
    CHECK(p[0]->hasLargestArmy() == false);
    CHECK(game.mostKnights == 4);
}

TEST_CASE("Progress Card")
{
    for (size_t i = 0; i < p[0]->getResources().size(); i++)
    {
        p[0]->setResources(i, 0);
        p[1]->setResources(i, 0);
        p[2]->setResources(i, 0);
    }


    cout << "*****It's test, choose first brick and lumber *****" << endl;
    ProgressCard pro1("plenty");
    pro1.playCard(p, 0, b); // assume the player coose 1 brick and 1 lumber
    CHECK(p[0]->getResources()[brick] == 1);
    CHECK(p[0]->getResources()[lumber] == 1);

    cout << "*****It's test, choose twice iron *****" << endl;
    pro1.playCard(p, 1, b); // assume the player choose 2 iron
    CHECK(p[1]->getResources()[iron] == 2);

    cout << "****It's test, choose wheat *****" << endl;
    ProgressCard pro2("monopoly");
    p[0]->setResources(wheat, 1);
    p[1]->setResources(wheat, 1);
    pro2.playCard(p, 2, b); // assume the player choose wheat
    CHECK(p[2]->getResources()[wheat] == 2);
    CHECK(p[1]->getResources()[wheat] == 0);
    CHECK(p[0]->getResources()[wheat] == 0);

    cout << "*****It's test, choose the edges (50,53) and (52,53) *****" << endl;
    ProgressCard pro3("building");
    CHECK(p[1]->getRoads().size() == 0);
    CHECK(b.findEdge(52, 53)->isEmpty());
    CHECK(b.findEdge(50, 53)->isEmpty());
    p[1]->placeSettlement(53, b);
    pro3.playCard(p, 1, b); // assume the player choose edges (50,53), (52,53)
    CHECK(p[1]->getRoads().size() == 2);
    CHECK(b.findEdge(52, 53)->getColor() == p[1]->getColor());
    CHECK(b.findEdge(50, 53)->getColor() == p[1]->getColor());
}

TEST_CASE("Buy Development Card & Victory Point")
{
    VictoryPoint vp;
    CHECK(p[0]->getPoints() == 1); //get a point before because has asettlement
    vp.playCard(p, 0, b);
    CHECK(p[0]->getPoints() == 2);

    CHECK(game.getCards().size() == 5);   // knight, vp, monopoly, plenty, building
    p[0]->buyDevelopmentCard(game, p, b); // has not enough resources. do nothing

    cout <<"*****It's test,if p1 acheive building develop card - choose the roads (21,22), (22,23)" << endl;
    cout <<"If p2 acheive building develop card - choose the roads (12,13), (12,14) *****" << endl;
    p[1]->setResources(wheat, 1);
    p[1]->setResources(wool, 1);
    CHECK_NOTHROW(p[1]->buyDevelopmentCard(game, p, b)); // play development card

    p[2]->setResources(iron, 1);
    p[2]->setResources(wool, 1);
    CHECK_NOTHROW(p[2]->buyDevelopmentCard(game, p, b)); // play development card
}

TEST_CASE("End Game")
{
    game.gameWinner(p[0]); // anyone
    p1.setPoints(10);
    game.gameWinner(p[0]); // print p1
}

