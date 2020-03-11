#include "tables.h"
#include "stdlib.h"
#include "stdio.h"


Table deal_cards_on_ (Table table)
{
    table.players = calloc(table.players_count, sizeof(Player));
    int tmp = 0;
    for (int i = 0; i < table.players_count; i++){
        table.players[i].cards = calloc(table.game.cards_count_for_each_player, sizeof(Card));
        for (int j = 0; j < table.game.cards_count_for_each_player; j++) {
            table.players[i].cards_count += 1;
            table.players[i].cards[j] = table.game.deck.cards[tmp];
            tmp += 1;
        }
    }
    Card* deck = table.game.deck.cards;
    table.game.deck.cards = calloc(table.game.deck.size-tmp, sizeof(Card));
    for (int i = 0; i < table.game.deck.size-tmp; i++) {
        table.game.deck.cards[i] = deck[i+tmp];
    }
    return table;
}

int get_quantity_of_tables(int number_of_players){
    if (number_of_players % MAX_PLAYERS_AT_TABLE != 0)
        return (int) number_of_players / MAX_PLAYERS_AT_TABLE + 1;
    else
        return number_of_players / MAX_PLAYERS_AT_TABLE;
}

Table* create_tables(int number_of_players){
    Table* tables;
    int number_of_tables = get_quantity_of_tables(number_of_players);

    tables = calloc(number_of_tables, sizeof(Table));

    if (number_of_players >= MIN_PLAYERS_AT_TABLE) {
        for (int i = 0; i < number_of_tables; i++) {
            tables[i].id = i;
            tables[i].game = get_game(rand() % LEN_GAMES);

            if (number_of_players - MAX_PLAYERS_AT_TABLE >= 0) {
                tables[i].players_count = MAX_PLAYERS_AT_TABLE;
                number_of_players -= MAX_PLAYERS_AT_TABLE;
            } else {
                tables[i].players_count = number_of_players;
                number_of_players = 0;
                while (tables[i].players_count < MIN_PLAYERS_AT_TABLE) {
                    tables[number_of_players % number_of_tables].players_count -= 1;
                    tables[i].players_count += 1;
                    number_of_players += 1;
                }
            }
            if (MAX_PLAYERS_AT_TABLE > tables[i].game.deck.size / tables[i].game.cards_count_for_each_player){
                printf("Измените MAX_PLAYERS_AT_TABLE в tables.c на меньшее значение\n"
                       "или размер колоды(deck.size) для данной игры (%s) на бОльшее значение!\n"
                       "Программа завершается!", tables[i].game.name);
                exit(-1);
            }
            tables[i] = deal_cards_on_(tables[i]);
        }
    }
    else{
        printf("Неправильный ввод!\nПрограмма завершается!");
        return tables;
    }
    return tables;
}

void show_table(Table table){
    printf("\n\n____________СТОЛ №%d.____________\n"
           "Игра на данном столе: %s\n"
           "-----------Игроки----------\n", table.id+1, table.game.name);
    for(int i = 0; i < table.players_count; i ++){
        printf("Игрок №%d.\n"
               "    Количество карт:%d\n"
               "        Карты:\n", i+1, table.players[i].cards_count);
        for(int j = 0; j < table.players[i].cards_count; j++){
            Card_ card = get_card(table.players[i].cards[j].id, table.game.deck.size);
            printf("            %d. %s %s\n", j+1, card.face, card.type);
        }
    }
}