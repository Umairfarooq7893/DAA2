#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Traveling Salesman Problem (TSP) using backtracking.
// We start from city 0 and try to visit every other city exactly once,
// then return to the starting city to complete the tour.

// dfs() explores all possible routes from the current city.
// cost[i][j] stores the travel cost between city i and city j.
// vis[] keeps track of cities already visited.
// last is the current city, and cnt is the number of cities visited so far.
int dfs(vector<vector<int>>& cost, vector<bool>& vis, int last, int cnt) {
    int n = cost.size();

    // If all cities have been visited, return to the starting city (city 0).
    if (cnt == n)
        return cost[last][0];

    int minCost = (int)1e9;

    // Try every unvisited city as the next destination.
    for (int city = 1; city < n; city++) {
        if (!vis[city]) {
            // Visit this city and recursively find the cheapest route from there.
            vis[city] = true;
            minCost = min(minCost, cost[last][city] +
                                   dfs(cost, vis, city, cnt + 1));

            // Backtrack so that other routes can be explored.
            vis[city] = false;
        }
    }

    // Return the minimum cost among all valid tours from the current state.
    return minCost;
}

// tsp() initializes the starting conditions for the tour.
// city 0 is fixed as the starting city and is marked as visited.
int tsp(vector<vector<int>>& cost) {
    int n = cost.size();

    // vis[0] = true means we begin from city 0 and do not revisit it.
    vector<bool> vis(n, false);
    vis[0] = true;

    return dfs(cost, vis, 0, 1);
}

int main() {
    // Example cost matrix for the TSP.
    // cost[i][j] is the cost to travel from city i to city j.
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Compute and print the minimum possible tour cost.
    int res = tsp(cost);
    cout << res;
    return 0;
}
