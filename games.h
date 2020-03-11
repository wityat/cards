#ifndef CARDS_GAMES_H
#define CARDS_GAMES_H
    #include "decks.h"

    typedef struct{
        char* name;
        int cards_count_for_each_player;
        Deck deck;
    } Game;

    enum games {poker, durak, twenty_one, LEN_GAMES};
    Game get_game(int game_id);
    Game create_game(char* game_name, int cards_count_for_each_player, int deck_size, Game game);
#endif //CARDS_GAMES_H
