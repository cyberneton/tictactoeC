#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

enum State : unsigned char {
    FREE = ' ',
    X    = 'X',
    O    = 'O',
};

void print_level(unsigned char game[9]) {
    printf("\n┌───────────┐\n");
    for (unsigned char i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            printf("│");
        }
        putchar(' ');
        putchar(game[i]);
        putchar(' ');

        if (i % 3 == 0 || i % 3 == 1) {
            putchar('|');
        }
        if (i % 3 == 2) {
            printf("│");
        }
        if (i % 3 == 2 && i != 8) {
            printf("\n│---+---+---│\n");
        }
    }
    printf("\n└───────────┘\n");
}

void print_level_numbered(unsigned char game[9]) {
    printf("\n┌───────────┐\n");
    for (unsigned char i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            printf("│");
        }
        putchar(' ');
        game[i] == FREE ? printf("%i", i + 1) : putchar(game[i]);
        putchar(' ');

        if (i % 3 == 0 || i % 3 == 1) {
            putchar('|');
        }
        if (i % 3 == 2) {
            printf("│");
        }
        if (i % 3 == 2 && i != 8) {
            printf("\n│---+---+---│\n");
        }
    }
    printf("\n└───────────┘\n");
}

int main() {
    unsigned char game[9] = {
        FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE,
    };

    int selected       = -1;
    bool is_player_one = true;

    while (1) {
        print_level(game);
        print_level_numbered(game);

        while (true) {
            const size_t buffer_size = 256;
            char buffer[buffer_size];

            printf("Please enter a field [1-9]:");
            fgets(buffer, buffer_size, stdin);

            if (sscanf(buffer, "%i", &selected) == 1) {
                if (selected < 1 || selected > 9) {
                    printf("Field #%i out of bound!\n", selected);
                    continue;
                } else {
                    if (game[selected - 1] != FREE) {
                        printf("Fieled already placed!\n");
                        continue;
                    } else {
                        break;
                    }
                }
            } else {
                printf("Unexpected input: %s\n", buffer);
                continue;
            }
        };
        assert(selected > 0);
        assert(selected < 10);
        printf("Selected field is %i\n", selected);

        game[selected - 1] = is_player_one ? X : O;
        is_player_one      = !is_player_one;
    }
}
