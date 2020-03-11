#ifndef CARDS_CARDS_H
#define CARDS_CARDS_H
    #define LEN_TYPES 4
    #define LEN_FACES 13
    #define MAX_LEN_DECK LEN_TYPES*LEN_FACES

    typedef struct {
        int id;
    } Card;

    typedef struct {
        char* face;
        char* type;
    } Card_;

    Card_ get_card(int card_id, int deck_size);
#endif //CARDS_CARDS_H