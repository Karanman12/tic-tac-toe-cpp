#include <iostream>
using namespace std;

char board[3][3];  // Game board
char currentPlayer = 'X';  // Start with player X

// Function to initialize the board with numbers
void initializeBoard() {
    char ch = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

// Function to switch between players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check if the current player has won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

// Function to check for a tie
bool checkTie() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Function to handle a player's move
bool makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false; // Invalid move
    }

    board[row][col] = currentPlayer;
    return true;
}

int main() {
    initializeBoard();
    int position;

    cout << "=== TIC-TAC-TOE ===\n";
    cout << "Player 1: X, Player 2: O\n";

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter a position (1-9): ";
        cin >> position;

        if (!makeMove(position)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins! 🎉\n";
            break;
        }

        if (checkTie()) {
            displayBoard();
            cout << "It's a tie! 🤝\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}
