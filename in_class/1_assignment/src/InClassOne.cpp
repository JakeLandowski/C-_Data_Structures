/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  Assignment #2, 1/10/18
 * 
 *  This program creates a structure array of players
 *  and sets their names, and random jersey/goal stats
 *  then demonstrates their structure by printing each 
 *  player along with their total goals;
 */

#include <iostream> // for cout / cin
#include <string>   // backup if not in <iostream>
#include <cstdlib>  // for srand / rand
#include <ctime>    // for time()

using namespace std;

const int JERSEY_NUM_MIN = 0;
const int JERSEY_NUM_MAX = 99;
const int GOALS_NUM_MIN  = 0;
const int GOALS_NUM_MAX  = 50;

const string PLAYER_NAMES[] = { "Pele", "Lionel", "Diego", "Johan", "Zinedine" };
const int NUM_PLAYERS = 5;

struct Player
{
    string name;
    int jerseyNumber;
    int goalCount;
};

void setPlayers(Player players[]);
void printPlayer(Player *player);
void printTotalGoals(Player players[]);
void initRandom();
int randInt(int min, int max);

int main()
{
    initRandom();

    Player players[5];

    setPlayers(players);

    for(int i = 0; i < NUM_PLAYERS; i++)
        printPlayer(&players[i]);

    printTotalGoals(players);

    return 0;
}

void setPlayers(Player players[])
{
    for(int i = 0; i < NUM_PLAYERS; i++)
    {
        players[i].name = PLAYER_NAMES[i]; 
        players[i].jerseyNumber = randInt(0, 99); 
        players[i].goalCount = randInt(0, 50);
    }
}

void printPlayer(Player *player)
{
    cout << "Player Name : " << player->name         << endl
         << "Number : "      << player->jerseyNumber << endl
         << "Number of goals this season : " << player->goalCount << endl << endl;
}

void printTotalGoals(Player players[])
{
    int totalGoals = 0;

    for(int i = 0; i < NUM_PLAYERS; i++)
        totalGoals += players[i].goalCount;

    cout << "The number of goals for the team is : " << totalGoals << endl; 
}

/**
 *  Initialize random seed.
*/
void initRandom()
{
    srand((unsigned) time(0));
}

/**
 *  Return a random number between min and max inclusively.
*/
int randInt(int min, int max)
{
    return (rand() % (max - min + 1) + min);
}