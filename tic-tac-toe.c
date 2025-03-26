#include <stdio.h>

char board[3][3];
char current_player;

void initialize_board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '1' + i * 3 + j; // Assign positions as 1-9
}

void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

int check_winner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

int is_draw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return 0;
    return 1;
}

void switch_player() {
    current_player = (current_player == 'X') ? 'O' : 'X';
}

void play_game() {
    int position;
    current_player = 'X';

    while (1) {
        print_board();
        printf("Player %c, enter position (1-9): ", current_player);
        scanf("%d", &position);

        if (position < 1 || position > 9) {
            printf("Invalid position. Try again.\n");
            continue;
        }

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Position already taken. Try again.\n");
            continue;
        }

        board[row][col] = current_player;

        if (check_winner()) {
            print_board();
            printf("Player %c wins!\n", current_player);
            break;
        }

        if (is_draw()) {
            print_board();
            printf("It's a draw!\n");
            break;
        }

        switch_player();
    }
}

int main() {
    initialize_board();
    play_game();
    return 0;
}
