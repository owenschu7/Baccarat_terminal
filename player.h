#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>

using namespace std;

class Player
{
public:
    Player();
    ~Player();

    Player(int cash);

    void add_outcome(int outcome); // 0 for banker; 1 for player; 2 for tie; 3 for panda; 4 for dragon; also keeps track of how many games played (length of vector)

    //need to implement a way to calculate win % from m_outcomes

private:
    int m_cash;
    vector<int> m_outcomes;
};

#endif
