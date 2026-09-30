#include<iostream>
#include<vector>
using namespace std;

int main(){

    // n = number of items
    // w = maximum capacity of the knapsack
    int n;
    int w;

    // Read number of items
    cout<<"enter n";
    cin>>n;

    // Read maximum capacity
    cout<<"enter w";
    cin>>w;

    // Weight of each item
    vector<int> weight = {2,3,4,5};

    // Profit/value of each item
    vector<int> profit = {3,4,5,6};

    // Create Dynamic Programming table
    // K[i][j] = maximum profit using first i items
    // when the knapsack capacity is j
    vector<vector<int>> K(n+1, vector<int>(w+1, 0));

    // Consider each item one by one
    for(int i=1; i<=n; i++){

        // Consider every possible capacity from 1 to w
        for(int j=1; j<=w; j++){

            // Check whether the current item can fit
            if(weight[i-1] <= j){

                // We have two choices:
                // 1. Include the current item
                // 2. Exclude the current item
                //
                // Include:
                // profit[i-1] = profit of current item
                // K[i-1][j-weight[i-1]] = best profit
                // using remaining capacity
                //
                // Exclude:
                // K[i-1][j] = best profit without current item

                // Take the maximum of both choices
                K[i][j] = max(
                    profit[i-1] + K[i-1][j-weight[i-1]],
                    K[i-1][j]
                );
            }

            else{

                // If the item does not fit,
                // we cannot include it.
                // So copy the result from the previous item.
                K[i][j] = K[i-1][j];
            }
        }
    }

    // K[n][w] contains the maximum profit
    // using all n items with capacity w
    cout<<"Maximum Profit = "<<K[n][w];

    return 0;
}