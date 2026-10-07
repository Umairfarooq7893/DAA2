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
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0;
         i--, j--)
        if (board[i][j])
            return false;

    // Check right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n;
         i--, j++)
        if (board[i][j])
            return false;

    return true;
}

void solve(int row) {

    // All queens placed
    if (row == n) {

        // Print solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }

        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {

        if (safe(row, col)) {

            board[row][col] = 1;

            solve(row + 1);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

int main() {

    cin >> n;

    solve(0);

    return 0;
}