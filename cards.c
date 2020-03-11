#include "cards.h"

char* types[LEN_TYPES] = {"буби", "крести", "винни", "черви"};
char* faces[LEN_FACES] = {"двойка", "тройка", "четверка", "пятёрка", "шестёрка", "семёрка", "восьмёрка", "девятка",
                          "десятка", "валет", "дама", "король", "туз"};

Card_ get_card(int card_id, int deck_size){
    Card_ card;
    int SHIFT_LEN_FACES = (MAX_LEN_DECK - deck_size)/LEN_TYPES;
    card.type = types[(int) card_id % LEN_TYPES];
    card.face = faces[SHIFT_LEN_FACES + (int) card_id / LEN_TYPES];
    return card;
}
