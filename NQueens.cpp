#include <iostream>
using namespace std;

int n;
int board[20][20];

bool safe(int row, int col) {

    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solve(int row) {

    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {

        if (safe(row, col)) {
            board[row][col] = 1;

            if (solve(row + 1))
                return true;

            board[row][col] = 0;   // Backtrack
        }
    }

    return false;
}

int main() {
    cin >> n;

    if (solve(0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution";
    }
}