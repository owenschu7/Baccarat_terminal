#include <iostream>
#include "card.h"
#include "deck.h"
#include "baccarat_hand.h"

using namespace std;

int main()
{
    Deck deck(1);
    deck.shuffle_deck();
    
    Baccarat_hand player = Baccarat_hand(Card(10, 'd'), Card(10, 's'), Card(10, 's'));
    Baccarat_hand player1 = Baccarat_hand(Card(11, 'd'), Card(12, 's'), Card(13, 's'));
    Baccarat_hand player2 = Baccarat_hand(Card(3, 'd'), Card(4, 's'), Card(3, 's'));
    Baccarat_hand player3 = Baccarat_hand(Card(14, 'd'), Card(9, 's'), Card());
    Baccarat_hand player4 = Baccarat_hand(Card(12, 'd'), Card(), Card());
    cout << "total: " << player.get_total() << endl;
    cout << "total: " << player1.get_total() << endl;
    cout << "total: " << player2.get_total() << endl;
    cout << "total: " << player3.get_total() << endl;
    cout << "total: " << player4.get_total() << endl;


    return 0;
}
