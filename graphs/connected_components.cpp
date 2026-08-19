#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int current) {
    visited[current] = true;

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1},
        {0, 2},
        {1},
        {4},
        {3},
        {}
    };

    vector<bool> visited(graph.size(), false);
    int components = 0;

    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            dfs(graph, visited, i);
            components++;
        }
    }

    cout << "Connected components: " << components << endl;

    return 0;
}