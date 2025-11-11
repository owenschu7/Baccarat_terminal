//implements the ability to play a round of baccarat and stores the data of all the previous games
#ifndef BACCARAT_TABLE_H
#define BACCARAT_TABLE_H
#include <iostream>
#include <vector>
#include "baccarat_hand.h"

using namespace std;

class Baccarat_table
{
public:
    Baccarat_table();
    ~Baccarat_table();

    //plays a round returns who wins also it pushes the result to m_outcomes
    int play_round(); // 0 for banker; 1 for player; 2 for tie; 3 for panda; 4 for dragon


private:
    vector<int> m_outcomes; // stores all the information about the game

};

#endif
