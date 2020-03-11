#ifndef CARDS_DECKS_H
#define CARDS_DECKS_H
    #include "cards.h"

    typedef struct {
        Card* cards;
        int size;
    } Deck;

    Deck create_deck(Deck deck);
    Deck shuffle(Deck deck);
#endif //CARDS_DECKS_H
