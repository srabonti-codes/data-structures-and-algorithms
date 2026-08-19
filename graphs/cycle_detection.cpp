#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int current, int parent) {
    visited[current] = true;

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            if (dfs(graph, visited, neighbor, current)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 2},
        {0, 1, 3},
        {2}
    };

    vector<bool> visited(graph.size(), false);
    bool hasCycle = false;

    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i] && dfs(graph, visited, i, -1)) {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}