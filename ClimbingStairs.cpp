#include <bits/stdc++.h>
using namespace std;

// to climb n stairs
int climbStairs(int n) {
    // 1 stair -> 1 way
    // 2 stairs -> 2 ways
    if (n <= 2) return n;

    int prev2 = 1;
    int prev1 = 2;

    // number of ways for steps 3 to n
    for (int i = 3; i <= n; i++) {

        int curr = prev1 + prev2;

        // Update previous values for the next iteration
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n;
    cout << "Enter number of steps N: ";
    cin >> n;

    cout << "Distinct ways to climb " << n
         << " steps: " << climbStairs(n) << endl;

    return 0;
}
