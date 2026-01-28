#include <iostream>
#include "card.h"
#include "deck.h"
#include "baccarat_hand.h"
#include "baccarat_table.h"

Baccarat_table::Baccarat_table()
{
}

Baccarat_table::~Baccarat_table()
{
}

void Baccarat_table::print_history_of_round(int round)
{
    cout << "=========Player=========" << endl;
    m_outcomes[round-1].player_cards.get_first_card().print_card();
    m_outcomes[round-1].player_cards.get_second_card().print_card();
    m_outcomes[round-1].player_cards.get_third_card().print_card();
    cout << "=========Banker=========" << endl;
    m_outcomes[round-1].banker_cards.get_first_card().print_card();
    m_outcomes[round-1].banker_cards.get_second_card().print_card();
    m_outcomes[round-1].banker_cards.get_third_card().print_card();

}

int Baccarat_table::play_round()
{
    // start the round
    m_deck.shuffle_deck(); // shoe should be shuffled only when shoe ends

    Round_Record current_round;

    Baccarat_hand player(m_deck.deal_card(), m_deck.deal_card());
    Baccarat_hand banker(m_deck.deal_card(), m_deck.deal_card());

    int player_total = player.get_total();
    int banker_total = banker.get_total();

    // 2. check for naturals (8 or 9)
    // if either has 8 or 9, no more cards are dealt. game ends immediately.
    if (player_total >= 8 || banker_total >= 8) {

        if (player_total > banker_total)
        {
            //append cards to outcome
            current_round.banker_cards = banker;
            current_round.player_cards = player;
            current_round.winner = 1;
            current_round.banker_total = banker_total;
            current_round.player_total = player_total;
            m_outcomes.push_back(current_round);

            return 1; // player win (natural)
        }
        if (banker_total > player_total)
        {
            //append cards to outcome
            current_round.banker_cards = banker;
            current_round.player_cards = player;
            current_round.winner = 0;
            current_round.banker_total = banker_total;
            current_round.player_total = player_total;
            m_outcomes.push_back(current_round);

            return 0; // banker win (natural)
        }
        //append cards to outcome
        current_round.banker_cards = banker;
        current_round.player_cards = player;
        current_round.winner = 2;
        current_round.banker_total = banker_total;
        current_round.player_total = player_total;
        m_outcomes.push_back(current_round);
        return 2; // tie
    }

    // 3. player's third card logic
    // player draws if total is 0-5. stands on 6-7.
    int player_third_card_value = -1; // flag to track if player drew (-1 means no draw)
    
    if (player_total <= 5) {
        Card c = m_deck.deal_card();
        player_third_card_value = c.calc_card_value(); // assuming get_value() returns baccarat value (0 for 10/j/q/k)
        player.add_third_card(c);
    }

    // 4. banker's third card logic
    // banker's move depends on whether player drew a card
    bool banker_draws = false;

    if (player_third_card_value == -1) {
        // scenario a: player stood (did not draw)
        // banker draws if 0-5, stands if 6-7
        if (banker_total <= 5) {
            banker_draws = true;
        }
    } else {
        // scenario b: player drew a third card
        // banker acts based on own score and player's third card value
        switch (banker_total) {
            case 0: case 1: case 2:
                banker_draws = true; // always draw
                break;
            case 3:
                // draw unless player's third card was an 8
                if (player_third_card_value != 8) banker_draws = true;
                break;
            case 4:
                // draw if player's third card was 2, 3, 4, 5, 6, 7
                if (player_third_card_value >= 2 && player_third_card_value <= 7) banker_draws = true;
                break;
            case 5:
                // draw if player's third card was 4, 5, 6, 7
                if (player_third_card_value >= 4 && player_third_card_value <= 7) banker_draws = true;
                break;
            case 6:
                // draw if player's third card was 6 or 7
                if (player_third_card_value == 6 || player_third_card_value == 7) banker_draws = true;
                break;
            case 7:
                banker_draws = false; // always stand
                break;
        }
    }

    if (banker_draws) {
        banker.add_third_card(m_deck.deal_card());
    }

    // 5. final calculation
    player_total = player.get_total();
    banker_total = banker.get_total();

    // 6. determine winner and special ez baccarat outcomes
    if (player_total == banker_total)
    {
        //append cards to outcome
        current_round.banker_cards = banker;
        current_round.player_cards = player;
        current_round.winner = 2;
        current_round.banker_total = banker_total;
        current_round.player_total = player_total;
        m_outcomes.push_back(current_round);

        return 2; // tie
    }
    else if (banker_total > player_total) {
        // banker win - check for dragon 7
        // dragon 7: banker wins with a total of 7 consisting of 3 cards
        // assuming checking if player_third_card_value flag or logic implies card counts
        bool banker_has_3_cards = banker_draws; // if banker drew, they have 3 cards (since they started with 2)
        
        if (banker_total == 7 && banker_has_3_cards)
        {
            //append cards to outcome
            current_round.banker_cards = banker;
            current_round.player_cards = player;
            current_round.winner = 4;
            current_round.banker_total = banker_total;
            current_round.player_total = player_total;

            m_outcomes.push_back(current_round);

            return 4; // Dragon 7
        }

        //append cards to outcome
        current_round.banker_cards = banker;
        current_round.player_cards = player;
        current_round.winner = 0;
        current_round.banker_total = banker_total;
        current_round.player_total = player_total;
        m_outcomes.push_back(current_round);
        return 0; // Standard Banker Win
    }
    else {
        // Player Win - Check for Panda 8
        // Panda 8: Player wins with a total of 8 consisting of 3 cards
        bool player_has_3_cards = (player_third_card_value != -1);
        
        if (player_total == 8 && player_has_3_cards)
        {
            //append cards to outcome
            current_round.banker_cards = banker;
            current_round.player_cards = player;
            current_round.winner = 3;
            current_round.banker_total = banker_total;
            current_round.player_total = player_total;
            m_outcomes.push_back(current_round);

            return 3; // Panda 8
        }
        //append cards to outcome
        current_round.banker_cards = banker;
        current_round.player_cards = player;
        current_round.winner = 1;
        current_round.banker_total = banker_total;
        current_round.player_total = player_total;
        m_outcomes.push_back(current_round);
        return 1; // Standard Player Win
    }
}




