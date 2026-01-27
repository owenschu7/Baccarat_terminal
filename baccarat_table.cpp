#include <iostream>
#include "card.h"
#include "deck.h"
#include "baccarat_hand.h"
#include "baccarat_table.h"

int play_round()
{
    Deck deck(1);
    deck.shuffle_deck();
    
    Baccarat_hand player = Baccarat_hand(deck.deal_card(), deck.deal_card());
    Baccarat_hand banker = Baccarat_hand(deck.deal_card(), deck.deal_card());

    // continue with the logic here
    // check if third card needs to be dealt...
    cout << "Player has: " << player.get_total() << endl;
    cout << "Banker has: " << banker.get_total() << endl;
}




