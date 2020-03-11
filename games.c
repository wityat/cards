#include "games.h"


Game create_game(char* game_name, int cards_count_for_each_player, int deck_size, Game game){
    Deck deck;
    deck.size = deck_size;
    deck = create_deck(deck);
    deck = shuffle(deck);
    game.deck = deck;
    game.cards_count_for_each_player = cards_count_for_each_player;
    game.name = game_name;
    return game;
}

Game get_game(int game_id){
    Game game;
    switch (game_id){
        case poker:
            game = create_game("Покер", 2, 52, game);
            break;
        case durak:
            game = create_game("Дурак", 6, 36, game);
            break;
        case twenty_one:
            game = create_game("Двадцать одно", 2, 52, game);
            break;
        default:
            game = create_game("Покер", 2, 52, game);
            break;
    }
    return game;
}
