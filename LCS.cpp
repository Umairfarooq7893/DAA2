#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    // Declare two strings to store the input sequences
    string X, Y;

    // Ask the user to enter the first string
    cout << "Enter first string: ";
    cin >> X;

    // Ask the user to enter the second string
    cout << "Enter second string: ";
    cin >> Y;

    // Store the length of the first and second strings
    int m = X.length();
    int n = Y.length();

    // Create a DP table of size (m+1) x (n+1)
    // dp[i][j] stores the length of LCS of
    // first i characters of X and first j characters of Y
    // Initially, all values are 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Traverse through each character of string X
    for (int i = 1; i <= m; i++) {

        // Traverse through each character of string Y
        for (int j = 1; j <= n; j++) {

            // If the current characters of both strings are same
            if (X[i - 1] == Y[j - 1])

                // Add 1 to the LCS of the previous characters
                // Move diagonally: dp[i-1][j-1]
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else

                // If characters are different,
                // choose the maximum LCS by either:
                // 1. Removing current character from X -> dp[i-1][j]
                // 2. Removing current character from Y -> dp[i][j-1]
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // dp[m][n] contains the length of the LCS
    // of the complete strings X and Y
    cout << "Length of LCS = " << dp[m][n] << endl;

    return 0;
}