#include <iostream>
#include <vector>
#include "player.h"

using namespace std;

Player::Player()
{
    m_cash = 0;
}

Player::~Player()
{
    m_cash = 0;
}

Player::Player(string name, int cash)
{
    m_name = name;
    m_cash = cash;
}

void Player::add_outcome(int outcome)
{
    m_outcomes.push_back(outcome);
}

