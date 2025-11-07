#include <iostream>
#include "card.h"

using namespace std;

int main()
{
    Card card1(4, 's');
    Card card2(5, 'c');
    Card card3(6, 'd');

    card1.print_card();
    card2.print_card();
    card3.print_card();


}
