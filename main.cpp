#include <iostream>
#include "card.h"
#include "deck.h"
#include "baccarat_hand.h"
#include "baccarat_table.h"

using namespace std;

int main()
{
    Baccarat_table table1;
    table1.play_round();
    
    table1.print_history_of_round(1);

    return 0;
}
