#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char currentPlayer = 'X';

// Function to display the board
void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check winner
int checkWinner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

// Function to check draw
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // still empty space
            }
        }
    }
    return 1;
}

// Function to make move
void makeMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    } else {
        printf("Invalid move! Try again.\n");
    }
}

int main() {
    int choice;
    int winner = 0;

    printf("TIC TAC TOE GAME\n");
    displayBoard();

    while (1) {
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid input! Choose between 1-9.\n");
            continue;
        }

        makeMove(choice);
        displayBoard();

        if (checkWinner()) {
            printf("Player %c wins!\n", (currentPlayer == 'X') ? 'O' : 'X');
            break;
        }

        if (checkDraw()) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}