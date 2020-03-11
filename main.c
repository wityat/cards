#include <stdio.h>
#include <stdlib.h>
#include "tables.h"

int main() {
    int number_of_players, number_of_table, count_tables;

    printf("Введите количeство игроков:");
    scanf("%d", &number_of_players);

    Table* tables = create_tables(number_of_players);

    if (number_of_players >= MIN_PLAYERS_AT_TABLE) {
        char c = 0;
        while (c != 'q') {
            count_tables = get_quantity_of_tables(number_of_players);

            printf("\n\nВведите номер стола, на котором хотите посмотреть игру:\n(от 1 до %d включительно)"
                   "\nЕсли я Вам надоел, нажмите q \n", count_tables);
            scanf("%d", &number_of_table);

            if (count_tables < number_of_table || number_of_table <= 0)
                printf("\nСтола с таким номером несуществует!\nПопробуйте снова или нажмите q, чтобы выйти.");
            else {
                Table table = tables[number_of_table - 1];
                show_table(table);
            }
            c = (char) getchar();
        }
    }

    free(tables);

    return 0;
}
