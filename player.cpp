#include <iostream>
#include <vector>

using namespace std;

Player::Player()
{
    m_cash = 0;
}

Player::Player(int cash)
{
    m_cash = cash;
}

void add_outcome(int outcome)
{
    m_outcomes.push_back(outcome);
}
