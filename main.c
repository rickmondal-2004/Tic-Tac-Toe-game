#include <stdio.h>

// Function to print the Tic Tac Toe board
void print_board(char board[][3]) {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if there is a winner
char check_winner(char board[][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    // No winner
    return ' ';
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int player = 1;
    int row, col;
    char symbol;

    printf("Tic Tac Toe\n");

    while (1) {
        // Print the board
        print_board(board);

        // Get player's move
        printf("Player %d, enter row (1-3): ", player);
        scanf("%d", &row);
        printf("Player %d, enter column (1-3): ", player);
        scanf("%d", &col);

        // Convert to zero-based indices
        row--;
        col--;

        // Check if cell is already occupied
        if (board[row][col] != ' ') {
            printf("Cell is already occupied. Please try again.\n");
            continue;
        }

        // Set the symbol
        if (player == 1) {
            symbol = 'X';
        } else {
            symbol = 'O';
        }
        board[row][col] = symbol;

        // Check for a winner
        char winner = check_winner(board);
        if (winner != ' ') {
            // Print the board and the winner
            print_board(board);
            printf("Player %d wins!\n", player);
            break;
        }

        // Switch players
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }

    return 0;
}
