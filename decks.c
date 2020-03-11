#include "decks.h"
#include "stdlib.h"
#include "stdio.h"


Deck create_deck(Deck deck){
    if (deck.size % LEN_TYPES != 0){
        printf("Не могу создать колоду с количеством карт неделящимся на %d.\n", LEN_TYPES);
    } else {
        int begin_i = (MAX_LEN_DECK - deck.size)/LEN_TYPES;
        deck.cards = calloc(sizeof(Card), deck.size);
        int card_id = 0;
        for (int i = begin_i; i < LEN_FACES; i++) {
            for (int j = 0; j < LEN_TYPES; j++) {
                deck.cards[card_id].id = card_id;
                card_id++;
            }
        }
    }
    return deck;
}


Deck shuffle(Deck deck){
    Card card_tmp;
    for (int i = 0; i < deck.size; i++){
        card_tmp = deck.cards[i];
        int rand_ = rand() % deck.size;
        deck.cards[i] = deck.cards[rand_];
        deck.cards[rand_] = card_tmp;
    }
    return deck;
}