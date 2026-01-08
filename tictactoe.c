#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

// Use enum to represent the states.
// HACK: The value of the enum represent the corresponding char for printing.
enum State : unsigned char {
    FREE = ' ',
    X    = 'X',
    O    = 'O',
};

// Prints the game to console.
void print_game(unsigned char game[9]) {
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

// Prints the game to console, adds index when field is free.
void print_game_numbered(unsigned char game[9]) {
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

enum State check_win(unsigned char game[9]) {
    for (int ih = 0; ih < 3; ih++) {
        size_t iv = ih * 3;
        // Check vertical lines
        if (game[iv] == game[iv + 1] && game[iv] == game[iv + 2] &&
            game[iv] != FREE) {
            return game[ih];
        }
        // Check horizontal lines
        if (game[ih] == game[ih + 3] && game[ih] == game[ih + 6] &&
            game[ih] != FREE) {
            return game[ih];
        }
    }
    // Check cross
    if (game[0] == game[4] && game[0] == game[8] && game[0] != FREE) {
        return game[0];
    }
    if (game[2] == game[4] && game[2] == game[6] && game[2] != FREE) {
        return game[0];
    }
    // No win yet
    return FREE;
}
int main(int argc, const char* _argv[argc]) {
    // Create a new empty game.
    unsigned char game[9] = {
        FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE, FREE,
    };

    int selected       = -1;
    bool is_player_one = true;

    while (true) {
        print_game(game);
        print_game_numbered(game);

        while (true) {
            // 256 Bytes seems enough as we expect only one byte input.
            const size_t buffer_size = 256;
            char buffer[buffer_size];

            printf("Please enter a field (%c) [1-9]:", is_player_one ? X : O);
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

        printf("Field #%i selected\n", selected);

        game[selected - 1] = is_player_one ? X : O;
        is_player_one      = !is_player_one;

        enum State player_won = check_win(game);
        if (player_won != FREE) {
            printf("Player %c has won!\n", player_won);
            print_game(game);
            // Clear game
            for (int i = 0; i < sizeof(game) / sizeof(game[0]); i++) {
                game[i] = FREE;
            }
        }
    }
}
