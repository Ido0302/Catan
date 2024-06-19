#include <iostream>
#include <stdexcept>
#include <vector>
#include <set>
#include <limits>


#include "DevelopmentCard.hpp"
#include "ProgressCard.hpp"
#include "Player.hpp"

using namespace std;

ProgressCard::ProgressCard(string progressType) : progressType(progressType){};

string ProgressCard::getDevelopmentType()
{
    return "progress card";
}

string ProgressCard::getProgressType()
{
    return this->progressType;
}

/**
 * get the players, the number of player who using card and the board.
 * play according the tylpe of progress card
 */
void ProgressCard::playCard(vector<Player*>& p, size_t i, Board& b)
{
    cout << p[i]->getName() << " reach the development card " <<  this->getDevelopmentType() << " " << this->getProgressType() << endl;

    if(this->progressType == "building")
        roadBuilding(p[i], b);
    
    if(this->progressType == "plenty")
        plentyYear(p[i]);

    if(this->progressType == "monopoly")
        monopoly(p, i);
}

/**
 * get player and board
 * the player choose two new lanes to build roads(if possible)
 */
void ProgressCard::roadBuilding(Player* p, Board& b)
{
    cout << "Please enter two junctions for the first lane you want to build on it road:" << endl;
    int junction1, junction2;
    cin >> junction1;
    cin >> junction2;
    Edge* lane1 = b.findEdge(junction1, junction2); //find the edge according the junction that scan

    while (p->isValidLane(lane1, b) == false) //continue scan until the road is valid
    {
        cout << "It's invalid lane. Please enter new junctions" << endl;
        cin >> junction1;
        cin >> junction2;
        lane1 = b.findEdge(junction1, junction2);
    }    
    p->placeRoad(junction1, junction2, b); //build new road

    //scan another lane
    cout << "Please enter two junctions for the second lane you want to build on it road:" << endl;
    cin >> junction1;
    cin >> junction2;
    Edge* lane2 = b.findEdge(junction1, junction2);
    
    while (p->isValidLane(lane2, b) == false)
    {
        cout << "It's invalid lane. Please enter new junctions:" << endl;
        cin >> junction1;
        cin >> junction2;
        lane2 = b.findEdge(junction1, junction2);
    }
    p->placeRoad(junction1, junction2, b);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clean buffer
}

/**
 * get player and add him 2 resources according his choice
 */
void ProgressCard::plentyYear(Player* p)
{
    string resource1;
    string resource2;
    
    p->printResources();
    cout << "Please enter two resources you want to get from stack: (brick, lumber, iron, wheat, wool) " << endl;
    cin >> resource1;
    cin >> resource2;

    int res1 = p->getResourceFromString(resource1);
    int res2 = p->getResourceFromString(resource2);

    p->setResources(res1, p->getResources()[(size_t)res1] + 1);
    p->setResources(res2, p->getResources()[(size_t)res2] + 1);

    if(res1!=res2)
        cout << "You decide to get the resources " << resource1 << " and " << resource2 << " from the stack" <<endl;
    else
        cout << "You decide to get two " << resource1 << "s from the stack" <<endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clean buffer
}

/*
 * get the players and the number of player who using card.  
   the player take one resource from each player according his choice
 */
void ProgressCard::monopoly(vector<Player*>& p, size_t i)
{
    string resource;
    cout << "All resource of players: " << endl;
    p[0]->printResources();
    p[1]->printResources();
    p[2]->printResources();
    cout << "Please enter one resource you want to get from other players: (brick, lumber, iron, wheat, wool) " << endl;
    cin >> resource;
    cout << "You decide to get the resource " << resource << endl;

    size_t res = (size_t)p[i]->getResourceFromString(resource);
    for (size_t j = 0; j < p.size(); j++)
    {
        if(j != i && p[j]->getResources()[res] > 0)
        {
            p[i]->setResources(res, p[i]->getResources()[res] + 1);
            p[j]->setResources(res, p[j]->getResources()[res] - 1);
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clean the buffer
}



