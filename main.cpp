#include <iostream>
#include "card.h"
#include "deck.h"
#include "baccarat_hand.h"
#include "baccarat_table.h"
#include "player.h"

#include <string>

using namespace std;

int main()
{
    cout << "initializing game..." << endl;
    cout << "Enter number of players: ";
    int num_players;
    cin >> num_players;
    vector<Player *> players;

    for (int i = 0; i < num_players; i++)
    {
        cout << "Enter name for player " << i + 1 << ": ";
        string name;
        cin >> name;

        cout << "Enter starting cash for " << name << ": ";
        int starting_cash;
        cin >> starting_cash;

        players.push_back(new Player(name, starting_cash));
    }

    cout << "STARTING GAME" << endl << endl;
    


    Baccarat_table table1;
    cout << table1.play_round() << endl;
    
    return 0;
}
