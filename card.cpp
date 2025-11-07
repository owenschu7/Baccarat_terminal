#include <iostream>
#include "card.h"

using namespace std;

//default constructor
Card::Card()
{
    m_value = 0;
    m_suit = 'n';
}

//default deconstructor
Card::~Card()
{
    
}

//full constructor
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
    cout << "printing card..." << endl;
    cout << "Value is: " << m_value << endl;
    cout << "Suit is: " << m_suit << endl;
}

