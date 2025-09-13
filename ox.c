#include<stdio.h>
#include<stdlib.h>

char board[3] [3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
};

int choice;
int row, column;
char turn = 'X';
int draw = 0;

//function to display the board
void displayboard() {
    system("cls"); // use "clear if on linux/mac"
    printf("\nTIC TAC GAME\n");
    printf("player 1 [X] --- player 2 [0]\n\n");
    printf("      |     |     \n");
    printf("   %c   | %c  |  %c  \n", board [0] [0], board[0][1], board[0][2]);
    printf("----- |-----|-----\n");
    printf("      |     |     \n");
    printf("   %c  |  %c |   %c \n", board[1][0], board[1][1], board[1][2]);
    printf("----- |-----|-----\n");
    printf("      |     |     \n");
    printf("   %c  |  %c |   %c \n", board[2][0], board[2][1], board[2][2]);
    printf("      |     |     \n\n");
}

// function to check game status
int checkWin() {
    // rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) return 1;
    }
    // diagonals 
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) return 1;

    // draw condition
    draw = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                draw = 0;

    return 0;
}
// function to update board
void markboard() {
    if (choice >= 1 && choice <= 9) {
        row = (choice - 1) / 3;
        column = (choice - 1) % 3;

        if (board[row][column] != 'X' && board[row][column] != 'O') {
            board[row][column] = turn;
        } else {
            printf("cell already taken! try again. \n");
            getchar();
        }
    } else {
        printf("invalid move! try again. \n");
        getchar();
    }
}

int main() {
    int gameStatus;

    while (1) {
        displayBoard();
        printf("printf %c, enter your choice (1-9): ", turn);
        scanf("%d", &choice);

        if (gameStatus == 1) {
            displayBoard();
            printf("player %c wins!\n", (turn == 'X') ? 'O' : 'X');
            break;
        } else if (draw == 1) {
            displayBoard();
            printf("its a draw!\n");
            break;
        }
    }

    return 0;
}