#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int current) {
    visited[current] = true;
    cout << current << " ";

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3},
        {0, 4},
        {1},
        {2}
    };

    vector<bool> visited(graph.size(), false);

    dfs(graph, visited, 0);

    return 0;
}