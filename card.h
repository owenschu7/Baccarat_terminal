#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card
{
public:
    Card();
    ~Card();

    Card(int value, char suit);

    char get_suit();
    void set_suit(char suit);

    int get_value();
    void set_value(int value);

    void print_card();

private:
    int m_value;
    char m_suit;

};

#endif
