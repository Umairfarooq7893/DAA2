#include <iostream>
#include <vector>
using namespace std;

bool DFS(int node, int parent, vector<int> adj[],
         vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (DFS(neighbor, node, adj, visited))
                return true;
        }
        else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int V = 4;
    vector<int> adj[V];

    // Add undirected edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(0);
    adj[0].push_back(2);

    adj[2].push_back(3);
    adj[3].push_back(2);

    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (DFS(i, -1, adj, visited)) {
                cout << "Cycle detected";
                return 0;
            }
        }
    }

    cout << "No cycle";
    return 0;
}
