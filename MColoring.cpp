#include <iostream>
using namespace std;

int n, m;
int graph[10][10], color[10];

bool safe(int v, int c) {
    for (int i = 0; i < n; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool solve(int v) {
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (safe(v, c)) {
            color[v] = c;

            if (solve(v + 1))
                return true;

            color[v] = 0;   // Backtrack
        }
    }
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    if (solve(0)) {
        for (int i = 0; i < n; i++)
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
    } else {
        cout << "No solution";
    }
}