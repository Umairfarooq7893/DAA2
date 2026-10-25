
#include <iostream>
#include <vector>
using namespace std;

int V = 4;

int graph[4][4] = {
    {0, 1, 1, 1},
    {1, 0, 0, 1},
    {1, 0, 0, 1},
    {1, 1, 1, 0}
};

int count = 0;

bool isSafe(vector<int>& color, int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

void graphColoring(vector<int>& color, int v, int m) {
    if (v == V) {
        count++;
        cout << "Solution " << count << ": ";
        for (int c : color) {
            cout << c << " ";
        }
        cout << endl;
        return;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(color, v, c)) {
            color[v] = c;

            graphColoring(color, v + 1, m);

            color[v] = 0;
        }
    }
}

int main() {
    vector<int> color(V, 0);
    int m = 4;

    graphColoring(color, 0, m);

    if (count == 0) {
        cout << "No solution with " << m << " colors" << endl;
    } else {
        cout << "Total solutions: " << count << endl;
    }

    return 0;
}
