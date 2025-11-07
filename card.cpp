#include <iostream>

using namespace std;

Card::Card();
Card::Card();

Card::Card(int value, char suit)
{
    m_value = value;
    m_suit = suit;
}


char Card::get_suit()
{
    return m_suit;
}
void Card::set_suit(char suit)
{
    m_suit = suit;
}

int Card::get_value()
{

    return m_suit;
}
void Card::set_value(int value)
{
    m_value = value;
}

void Card::print_card()
{
    cout <<printing card << endl;
    cout << "Value is: " << m_value;
    cout << "Suit is: " << m_suit;
}


