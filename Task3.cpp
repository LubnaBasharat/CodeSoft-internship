#include <iostream>
using namespace std;
char GameB[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

string WIN_NEXT(char board[3][3]) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return (board[i][0] == 'X') ? "X Player Win!" : "O Player Win!";
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return (board[0][i] == 'X') ? "X Player Win!" : "O Player Win!";
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return (board[0][0] == 'X') ? "X Player Win!" : "O Player Win!";
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return (board[0][2] == 'X') ? "X Player Win!" : "O Player Win!";
    }

    return "Next";
}


bool drawGame(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;  // Board is not full, not a draw
            }
        }
    }
    return true;  // All cells are filled, it's a draw
}

void display_Board(char board[3][3]) {

    int j = 1;

    for (int i = 0; i < 3; i++) 
    {
        cout  << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
       if ( j != 3&&j<3) {
            cout << "-----------" << endl;
            j++;
        }
     }
  
}

int main() {

    char currentPlayer = 'O';
    int row, col;

    for (int turn = 0; turn < 9; turn++) {
        display_Board(GameB);

        do {
            cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
            cin >> row >> col;

            if (GameB[row][col] != ' ' || row < 0 || row > 2 || col < 0 || col > 2) 
            {
                cout << "Invalid move. Try again.\n";
            }
            else {
                break;
            }
        } while (1);


        GameB[row][col] = currentPlayer;

        string result = WIN_NEXT(GameB);

        if (result != "Next") {
            display_Board(GameB);
            cout << result << endl;
            break;
        }

        if (drawGame(GameB)) {
            display_Board(GameB);
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
