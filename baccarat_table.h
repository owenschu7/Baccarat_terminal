//implements the ability to play a round of baccarat and stores the data of all the previous games
#ifndef BACCARAT_TABLE_H
#define BACCARAT_TABLE_H

#include <iostream>
#include <vector>
#include "card.h"
#include "deck.h"
#include "baccarat_hand.h"
#include "baccarat_table.h"

using namespace std;

struct Round_Record {
    int winner; // 0=Banker, 1=Player, 2=Tie, etc.
    int player_total;
    int banker_total;
    Baccarat_hand player_cards;
    Baccarat_hand banker_cards;
};

class Baccarat_table
{
public:
    Baccarat_table();
    ~Baccarat_table();

    //plays a round returns who wins also it pushes the result to m_outcomes
    int play_round(); // 0 for banker; 1 for player; 2 for tie; 3 for panda; 4 for dragon


    void print_history_of_round(int round);


private:
    Deck m_deck{1};
    int m_cards_left;
    vector<Round_Record> m_outcomes; // stores all the information about the game

};

#endif
