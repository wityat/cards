#ifndef CARDS_TABLES_H
#define CARDS_TABLES_H

    #include "games.h"

    #define MAX_PLAYERS_AT_TABLE 6
    #define MIN_PLAYERS_AT_TABLE 5

    typedef struct {
        Card* cards;
        int cards_count;
    } Player;

    typedef struct {
        Game game;
        Player* players;
        int players_count;
        int id;
    } Table;

    Table deal_cards_on_ (Table table);
    int get_quantity_of_tables(int number_of_players);
    Table* create_tables(int number_of_players);
    void show_table(Table table);
#endif //CARDS_TABLES_H
